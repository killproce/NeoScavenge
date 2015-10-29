#include "MapManager.h"
#include "MapData.h"
#include "tinyxml2/tinyxml2.h"
#include "public.h"
#include <queue>

MapManager* MapManager::_instance = NULL;

MapManager::MapManager()
{

}

MapManager* MapManager::getInstance()
{
	if (!_instance)
	{
		_instance = new MapManager;
		_instance->init();
	}
	return _instance;
}

void MapManager::init()
{
	loadConfig();
}

void MapManager::loadConfig()
{
	loadTileConfig();

	loadMapConfig();
}

void MapManager::loadTileConfig()
{
	m_tileDataMaps.clear();
	tinyxml2::XMLDocument doc;
	doc.LoadFile("config/TileConfig.xml");
	auto rootNode = doc.RootElement();
	if (rootNode)
	{
		auto tileNode = rootNode->FirstChildElement("TileData");
		while (tileNode)
		{
			stTileData tileData;
			tileData.tileId = tileNode->UnsignedAttribute("id");
			tileData.imgPath = tileNode->Attribute("imgpath");
			tileData.row = tileNode->IntAttribute("row");
			tileData.col = tileNode->IntAttribute("col");
			m_tileDataMaps.insert(std::make_pair(tileData.tileId, tileData));
			tileNode = tileNode->NextSiblingElement();
		}
	}
}

void MapManager::loadMapConfig()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("config/Map.xml");
	auto rootNode = doc.RootElement();

	if (rootNode)
	{
		auto headerNode = rootNode->FirstChildElement("MapHeader");
		if (headerNode)
		{
			int rows = headerNode->IntAttribute("rows");
			int cols = headerNode->IntAttribute("cols");
			m_mapData = new MapData(rows, cols);
		}

		auto dataNode = rootNode->FirstChildElement("MapData");
		if (dataNode)
		{
			auto tileNode = dataNode->FirstChildElement("Tile");
			while (tileNode)
			{
				int row = tileNode->IntAttribute("row");
				int col = tileNode->IntAttribute("col");
				unsigned int id = tileNode->UnsignedAttribute("id");
				m_mapData->addData(row, col, id);
				tileNode = tileNode->NextSiblingElement();
			}
		}
	}
}

const stTileData* MapManager::getTileDataFromID(unsigned int id) const
{
	auto it = m_tileDataMaps.find(id);
	if (it != m_tileDataMaps.end())
	{
		return &(it->second);
	}
	return NULL;
}

unsigned int MapManager::getMapDataAt(int row, int col)
{
	return m_mapData->getTileIDAt(row, col);
}

Vec2 MapManager::getPositionInMap(int row, int col)
{
	float x = START_X;
	float y = START_Y;
	int numr = row / 2;
	int numc = col - 1;
	if (row % 2)
	{
		x += TILE_START_WIDTH_1 + numc * TILE_WIDTH_DISTANCE;
		y += TILE_START_HEIGHT_1 + numr * TILE_HEIGHT_DISTANCE;
	}
	else
	{
		x += TILE_START_WIDTH_2 + numc * TILE_WIDTH_DISTANCE;
		y += TILE_START_HEIGHT_2 + (numr - 1) * TILE_HEIGHT_DISTANCE;
	}
	return Vec2(x, y);
}

stMapPos MapManager::convertPositionToMapPos(Vec2& pos)
{
	int offset[6][2] = { { -1,-1 },{ -2,0 },{ -1,0 },{ 1,-1 },{ 2,0 },{ 1,0 } };
	float x = pos.x - START_X;
	float y = pos.y - START_Y;

	//ÆæÊýÐÐ
	int numc = (x - TILE_START_WIDTH_1) / TILE_WIDTH_DISTANCE;
	int numr = (y - TILE_START_HEIGHT_1) / TILE_HEIGHT_DISTANCE;
	int row1 = numr * 2 + 1;
	int col1 = numc + 1;

	std::vector<stMapPos> tmpvecMapPos;
	tmpvecMapPos.push_back(stMapPos(row1, col1));
	for (int i = 0; i < 6; ++i)
	{
		tmpvecMapPos.push_back(stMapPos(row1 + offset[i][0], col1 + offset[i][1]));
	}
	for (std::vector<stMapPos>::iterator it = tmpvecMapPos.begin();
	it != tmpvecMapPos.end(); ++it)
	{
		auto tile = getHexTileAt(*it);
		if (tile && tile->isContainPoint(pos))
			return (*it);
	}
	return stMapPos(0,0);
}

void MapManager::addHexTile(HexTile* mapPos)
{
	for (std::vector<HexTile*>::iterator it = m_vecHexTiles.begin();
	it != m_vecHexTiles.end(); ++it)
	{
	}
	m_vecHexTiles.push_back(mapPos);
}

HexTile* MapManager::getHexTileAt(stMapPos& mapPos)
{
	for (std::vector<HexTile*>::iterator it = m_vecHexTiles.begin();
	it != m_vecHexTiles.end(); ++it)
	{
		if ((*it)->getPosInMap() == mapPos)
		{
			return (*it);
		}
	}
	return NULL;
}

int MapManager::getTwoMapPosDist(stMapPos& mapPos1, stMapPos& mapPos2)
{
	int offset1[6][2] = { { -1,-1 },{ -2,0 },{ -1,0 },{ 1,-1 },{ 2,0 },{ 1,0 } };
	int offset2[6][2] = { { -1,0 },{ -2,0 },{ -1,1 },{ 1,0 },{ 2,0 },{ 1,1 } };
	
	bool posHash[MAX_MAP_SIZE][MAX_MAP_SIZE] = { 0 };
	std::priority_queue<stDistData> posQueue;
	stDistData srcData(mapPos1,0);
	posQueue.push(srcData);
	posHash[mapPos1.row][mapPos1.col] = true;
	while (!posQueue.empty())
	{
		auto curDistData = posQueue.top();
		posQueue.pop();
		if (curDistData.mapPos == mapPos2)
		{
			return curDistData.dist;
		}
		
		int (*offset)[2]  = offset1;
		if (curDistData.mapPos.row % 2 == 0)
			offset = offset2;
		for (int i = 0; i < 6; ++i)
		{
			int row = curDistData.mapPos.row + offset[i][0];
			int col = curDistData.mapPos.col + offset[i][1];
			stDistData nxtDistData(stMapPos(row, col), curDistData.dist + 1);
			if (isInMap(nxtDistData.mapPos) && !posHash[row][col])
			{
				posHash[row][col] = true;
				posQueue.push(nxtDistData);
			}
		}
	}
	return -1;
}

bool MapManager::isInMap(stMapPos& pos)
{
	if (pos.row > 0 && pos.row <= getMapRows() && pos.col > 0 && pos.col <= getMapCols())
		return true;
	return false;
}
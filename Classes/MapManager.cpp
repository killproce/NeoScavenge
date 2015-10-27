#include "MapManager.h"
#include "MapData.h"
#include "tinyxml2/tinyxml2.h"

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
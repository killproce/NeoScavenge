#include "MapManager.h"

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
}

void MapManager::loadTileConfig()
{
	m_tileDataMaps.clear();

	stTileData tileData;
	tileData.tileId = 1;
	tileData.imgPath = "HexSheetSummerDay.png";
	tileData.row = 2;
	tileData.col = 7;
	m_tileDataMaps.insert(std::make_pair(1, tileData));
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
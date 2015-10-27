#ifndef __MAP_MANAGER_H__
#define __MAP_MANAGER_H__

#include <string>
#include <map>
#include "MapData.h"

struct stTileData
{
	unsigned int tileId;
	std::string imgPath;
	unsigned int row;
	unsigned int col;
	/*以后添加事件*/
};

class MapManager
{
public:
	void init();
	void loadConfig();

	static MapManager* getInstance();

	void loadTileConfig();

	void loadMapConfig();
	const stTileData* getTileDataFromID(unsigned int id) const;

	int getMapRows(){ return m_mapData->getMapRow(); }
	int getMapCols(){ return m_mapData->getMapCol(); }
	unsigned int getMapDataAt(int row, int col);
private:
	MapManager();

private:
	static MapManager* _instance;
	typedef std::map<unsigned int, stTileData> TileDataMap;
	TileDataMap m_tileDataMaps;
	MapData* m_mapData;
};

#endif	// __MAP_MANAGER_H__
#ifndef __MAP_MANAGER_H__
#define __MAP_MANAGER_H__

#include <string>
#include <map>

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

	const stTileData* getTileDataFromID(unsigned int id) const;
private:
	MapManager();

private:
	static MapManager* _instance;
	typedef std::map<unsigned int, stTileData> TileDataMap;
	TileDataMap m_tileDataMaps;

};

#endif	// __MAP_MANAGER_H__
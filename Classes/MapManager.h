#ifndef __MAP_MANAGER_H__
#define __MAP_MANAGER_H__

#include <string>
#include <map>
#include "MapData.h"
#include "cocos2d.h"
#include "public.h"
#include "HexTile.h"

USING_NS_CC;

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

	Vec2 getPositionInMap(int row, int col);
	stMapPos convertPositionToMapPos(Vec2& pos);

	HexTile* getHexTileAt(stMapPos& mapPos);
	void addHexTile(HexTile* mapPos);

	struct stDistData
	{
		stDistData() :mapPos(), dist(0) {}
		stDistData(int row,int col,int d):mapPos(row,col),dist(d){}
		stDistData(stMapPos& pos,int d):mapPos(pos.row,pos.col),dist(d){}
		friend bool operator< (const stDistData& lhs,const stDistData& rhs)
		{
			return lhs.dist > rhs.dist;
		}
		stMapPos mapPos;
		int dist;
	};
	int getTwoMapPosDist(stMapPos& mapPos1, stMapPos& mapPos2);
	bool isInMap(stMapPos& pos);
private:
	MapManager();

private:
	static MapManager* _instance;
	typedef std::map<unsigned int, stTileData> TileDataMap;
	TileDataMap m_tileDataMaps;
	MapData* m_mapData;
	std::vector<HexTile*> m_vecHexTiles;
};

#endif	// __MAP_MANAGER_H__
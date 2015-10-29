#ifndef __HEX_TILE_H__
#define __HEX_TILE_H__

#include "ObjectBase.h"
#include "cocos2d.h"
#include "public.h"
USING_NS_CC;

class HexTile : public ObjectBase
{
public:
	HexTile();

	bool init();
	static HexTile* create();

	bool initWithID(unsigned int id);
	static HexTile* createWithID(unsigned int id);
	
	void setTileID(unsigned int id){ m_tileID = id; }
	unsigned int getTileID() const { return m_tileID; }

	void setPosInMap(stMapPos& mapPos);
	stMapPos getPosInMap() { return m_mapPos; }

	void refreshData();

	bool isContainPoint(Vec2& pos);
private:
	bool isGreater(Point& p1, Point& p2, Point& p) const;
	bool isLess(Point& p1, Point& p2, Point& p) const;
private:
	unsigned int m_tileID;
	stMapPos m_mapPos;
	Sprite* m_tileImg;

	///´¥Ãþ¼ì²âÓÃ
	Rect m_rectScope;
	Point m_leftTriangle[3];
	Point m_rightTriangle[3];
};

#endif	// __HEX_TILE_H__
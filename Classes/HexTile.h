#ifndef __HEX_TILE_H__
#define __HEX_TILE_H__

#include "ObjectBase.h"
#include "cocos2d.h"
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

private:
	unsigned int m_tileID;

	Sprite* m_tileImg;
};

#endif	// __HEX_TILE_H__
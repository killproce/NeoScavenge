#include "HexTile.h"
#include "MapManager.h"

HexTile::HexTile()
:m_tileImg(NULL)
{

}

HexTile* HexTile::create()
{
	auto pRet = new HexTile;
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool HexTile::init()
{
	if (!ObjectBase::init())
	{
		return false;
	}

	return true;
}

HexTile* HexTile::createWithID(unsigned int id)
{
	auto pRet = new HexTile;
	if (pRet && pRet->initWithID(id))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool HexTile::initWithID(unsigned int id)
{
	if (!ObjectBase::init())
	{
		return false;
	}

	auto tileData = MapManager::getInstance()->getTileDataFromID(id);
	if (tileData)
	{
		m_tileID = tileData->tileId;
		float srcx = tileData->col * 100.0;
		float srcy = tileData->row * 76.0;
		m_tileImg = Sprite::create(tileData->imgPath,Rect(srcx,srcy,100.0,76.0));
		if (m_tileImg)
		{
			addChild(m_tileImg);
		}
	}
	return true;
}
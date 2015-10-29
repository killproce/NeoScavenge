#include "HexTile.h"
#include "MapManager.h"

HexTile::HexTile()
:m_tileImg(NULL)
,m_mapPos(0,0)
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
			m_tileImg->setAnchorPoint(Vec2(0.0, 0.0));
			addChild(m_tileImg);
		}
	}

	refreshData();

	return true;
}

void HexTile::setPosInMap(stMapPos& mapPos)
{
	m_mapPos = mapPos;

	refreshData();
}

void HexTile::refreshData()
{
	auto pos = MapManager::getInstance()->getPositionInMap(m_mapPos.row, m_mapPos.col);
	setPosition(pos);

	///ÉèÖÃ´¥Ãþ¼ì²â·¶Î§

	//ÖÐ¼ä¾ØÐÎ
	m_rectScope = Rect(pos.x + 20.0, pos.y + 10.0, 60.0, 40.0);
	//×ó±ßÈý½ÇÐÎ
	m_leftTriangle[0] = Point(pos.x, pos.y + 30.0);
	m_leftTriangle[1] = Point(pos.x + 20.0, pos.y + 50.0);
	m_leftTriangle[2] = Point(pos.x + 20.0, pos.y + 10.0);
	//ÓÒ±ßÈý½ÇÐÎ
	m_rightTriangle[0] = Point(pos.x + 100.0, pos.y + 30.0);
	m_rightTriangle[1] = Point(pos.x + 80.0, pos.y + 10.0);
	m_rightTriangle[2] = Point(pos.x + 80.0, pos.y + 50.0);
}

bool HexTile::isLess(Point& p1, Point& p2, Point& p) const
{
	float k = (p2.y - p1.y) / (p2.x - p1.x);
	float b = p1.y - k * p1.x;
	float y = k * p.x + b;
	return y < p.y;
}

bool HexTile::isGreater(Point& p1, Point& p2, Point& p) const
{
	return !isLess(p1,p2,p);
}

bool HexTile::isContainPoint(Vec2& pos)
{
	Rect testRect = Rect(m_rectScope.origin.x - 20.0, m_rectScope.origin.y, 100.0, 40.0);
	if (!testRect.containsPoint(pos))
		return false;
	if (m_rectScope.containsPoint(pos))
		return true;

	// line 1
	if (m_leftTriangle[1].x >= pos.x)
	{
		if (isGreater(m_leftTriangle[0], m_leftTriangle[1], pos) &&
			isLess(m_leftTriangle[0], m_leftTriangle[2], pos))
		{
			return true;
		}
	}

	//line 2
	if (m_rightTriangle[1].x <= pos.x)
	{
		if (isGreater(m_rightTriangle[0], m_rightTriangle[2], pos) &&
			isLess(m_rightTriangle[0], m_rightTriangle[1], pos))
		{
			return true;
		}
	}
	return false;
}
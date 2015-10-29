#include "MapLayer.h"
#include "HexTile.h"
#include "MapManager.h"
#include "public.h"
#include "GameManager.h"
#include "MainCharacter.h"

MapLayer::MapLayer()
	:m_hexSelectValidBox(NULL)
	,m_hexSelectInvalidBox(NULL)
	,m_curHexSelectBoxPos(0,0)
{
}

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	// 触摸设置
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MapLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	initData();

	return true;
}

void MapLayer::initData()
{
	// 角色行动的选择框
	m_hexSelectValidBox = Sprite::create("HexHilight.png");
	m_hexSelectInvalidBox = Sprite::create("HexHilightInvalid.png");
	m_hexSelectValidBox->setAnchorPoint(Vec2(0.0, 0.0));
	m_hexSelectInvalidBox->setAnchorPoint(Vec2(0.0, 0.0));
	addChild(m_hexSelectValidBox,SELECT_BOX_ZORDER);
	addChild(m_hexSelectInvalidBox, SELECT_BOX_ZORDER);

	initMap();
}

void MapLayer::drawMap()
{

}

void MapLayer::initMap()
{
	auto mapMgr = MapManager::getInstance();
	int rows = mapMgr->getMapRows();
	int cols = mapMgr->getMapCols();
	for (int row = rows; row >= 1; --row)
	{
		for (int col = cols; col >= 1; --col)
		{
			int tileId = mapMgr->getMapDataAt(row, col);
			if (tileId)
			{
				auto tile = HexTile::createWithID(tileId);
				tile->setPosInMap(stMapPos(row, col));
				addChild(tile,HEX_TILE_ZORDER);
				mapMgr->addHexTile(tile);
			}
		}
	}
}


bool MapLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void MapLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void MapLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (eGameRunning != GameManager::getInstance()->getGameState())
		return;

	auto pos = touch->getLocation();
	pos = this->convertToNodeSpace(pos);

	auto mainCharacter = GameManager::getInstance()->getMainCharacter();
	auto mapMgr = MapManager::getInstance();
	auto mapPos = mapMgr->convertPositionToMapPos(pos);

	if (!(mapPos == stMapPos(0, 0)))
	{
		int dist = mapMgr->getTwoMapPosDist(mapPos, mainCharacter->getPosInMap());
		CCLOG("dist = %d\n", dist);
		if (dist <= mainCharacter->getStrength())
		{
			m_hexSelectInvalidBox->setVisible(false);
			m_hexSelectValidBox->setVisible(true);
			if (m_curHexSelectBoxPos == mapPos)
			{
				m_curHexSelectBoxPos = mapPos;
				m_hexSelectValidBox->setPosition(mapMgr->getPositionInMap(mapPos.row, mapPos.col));
				mainCharacter->setPosInMap(m_curHexSelectBoxPos);
			}
			else
			{
				m_curHexSelectBoxPos = mapPos;
				m_hexSelectValidBox->setPosition(mapMgr->getPositionInMap(mapPos.row, mapPos.col));
			}
		}
		else
		{
			m_hexSelectInvalidBox->setVisible(true);
			m_hexSelectValidBox->setVisible(false);
			m_curHexSelectBoxPos = mapPos;
			m_hexSelectInvalidBox->setPosition(mapMgr->getPositionInMap(mapPos.row, mapPos.col));
		}
		
		
	}
}
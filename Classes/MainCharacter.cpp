#include "MainCharacter.h"
#include "MapManager.h"
#include "public.h"

MainCharacter::MainCharacter()
:m_characterImg(NULL)
,m_strength(0)
{

}

MainCharacter* MainCharacter::create()
{
	auto pRet = new MainCharacter;
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool MainCharacter::init()
{
	if (!ObjectBase::init())
	{
		return false;
	}

	setPosInMap(stMapPos(2, 2));

	m_characterImg = Sprite::create("Human.png");
	m_characterImg->setAnchorPoint(Vec2(0.0, 0.0));
	addChild(m_characterImg);
	
	m_strength = 1;

	refreshData();

	return true;
}

void MainCharacter::refreshData()
{
	Vec2 curPos = MapManager::getInstance()->getPositionInMap(m_posInMap.row, m_posInMap.col);
	setPosition(curPos);
}
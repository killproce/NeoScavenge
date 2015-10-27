#include "MainCharacter.h"

MainCharacter::MainCharacter()
:m_characterImg(NULL)
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

	setPosInMap(stMapPos(3, 2));
	return true;
}

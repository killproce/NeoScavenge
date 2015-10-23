#include "Prop.h"
#include "FlawHint.h"

Prop* Prop::create(const std::string& filename)
{
	auto pRet = new Prop;
	if (pRet && pRet->init(filename))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool Prop::init(const std::string& filename)
{
	if (!ObjectBase::init())
	{
		return false;
	}

	auto img = Sprite::create(filename);
	addChild(img);

	return true;
}
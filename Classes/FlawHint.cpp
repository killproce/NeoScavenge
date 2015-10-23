#include "FlawHint.h"

FlawHint::FlawHint()
	:m_bgImg(NULL)
{

}

bool FlawHint::init()
{
	if (!LayerColor::init())
	{
		return false;
	}
	setPosition(Vec2(100, 100));
	auto pBgSprit = Sprite::create("x2_btn_inv_flaw.png");
	pBgSprit->setPosition(Vec2(62, 22));
	addChild(pBgSprit);

	return true;
}

bool FlawHint::initWithColor(const Color4B& color)
{
	if (!LayerColor::initWithColor(color))
	{
		return false;
	}

	return true;
}

FlawHint* FlawHint::create()
{
	auto pRet = new FlawHint;
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

FlawHint* FlawHint::create(const Color4B& color)
{
	auto pRet = new FlawHint;
	if (pRet && pRet->initWithColor(color))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

void FlawHint::AddHint(Node* hint)
{
	if (!hint)
		return;

	m_vecHints.push_back(hint);
	addChild(hint);
}

void FlawHint::ClearAllHints()
{
	for (std::vector<Node*>::iterator it = m_vecHints.begin();
		it != m_vecHints.end();)
	{
		removeChild(*it);
	}
	m_vecHints.clear();
}

void FlawHint::SetBackgroundImg(Sprite* bgImg)
{
	if (m_bgImg)
	{
		removeChild(m_bgImg);
	}
	m_bgImg = bgImg;
	addChild(m_bgImg);
}
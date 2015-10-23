#ifndef __FLAW_HINT_H__
#define __FLAW_HINT_H__

#include "cocos2d.h"


USING_NS_CC;


class FlawHint : public LayerColor
{
public:
	FlawHint();
	virtual bool init();
	virtual bool initWithColor(const Color4B& color);

	static FlawHint* create();
	static FlawHint* create(const Color4B& color);

	void AddHint(Node* hint);
	void ClearAllHints();
	void SetBackgroundImg(Sprite* bgImg);
private:
	Sprite* m_bgImg;
	std::vector<Node*> m_vecHints;
};

#endif	// __FLAW_HINT_H__
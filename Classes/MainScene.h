#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "public.h"
USING_NS_CC;

class Bag;

class MainScene : public cocos2d::Layer
{
public:
	MainScene();
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(MainScene);


private:
	void loadUi();
	Bag* createBag(stBagSize s);
	void initTalentBag();
	void initFlawBag();

private:
	Node* m_skillPanel;
};

#endif // __MAIN_SCENE_H__

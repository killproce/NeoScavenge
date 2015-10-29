#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "public.h"
USING_NS_CC;



class SelectSkillLayer;
class MainCharacter;
class MapLayer;

class MainScene : public cocos2d::Layer
{
public:
	MainScene();
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(MainScene);

	virtual void update(float delta);

private:
	void loadUi();
	void initData();
private:
	Node* m_skillPanel;
	SelectSkillLayer* m_selectSkillLayer;
	MainCharacter* m_mainCharacter;
	MapLayer* m_mapLayer;
};

#endif // __MAIN_SCENE_H__

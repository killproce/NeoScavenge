#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class MenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(MenuScene);
protected:
	void onNewGameCallback();
	void onExitGameCallback();
private:
	ui::Button* m_continueButton;
	ui::Button* m_newGameButton;
	ui::Button* m_exitGameButton;
};

#endif // __MENU_SCENE_H__

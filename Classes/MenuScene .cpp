#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MainScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("MenuScene/MenuScene.csb");

	addChild(rootNode);
	
	auto bgPanel = dynamic_cast<ui::Layout*>(rootNode->getChildByName("bgPanel"));
	m_continueButton = dynamic_cast<ui::Button*>(ui::Helper::seekWidgetByName(bgPanel,"continueButton"));
	m_newGameButton = dynamic_cast<ui::Button*>(ui::Helper::seekWidgetByName(bgPanel,"newGameButton"));
	m_exitGameButton = dynamic_cast<ui::Button*>(ui::Helper::seekWidgetByName(bgPanel,"exitGameButton"));

	m_newGameButton->addClickEventListener(CC_CALLBACK_0(MenuScene::onNewGameCallback, this));
	m_exitGameButton->addClickEventListener(CC_CALLBACK_0(MenuScene::onExitGameCallback, this));

	return true;
}

void MenuScene::onNewGameCallback()
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}

void MenuScene::onExitGameCallback()
{
	Director::getInstance()->end();
}
#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SelectSkillLayer.h"
USING_NS_CC;
using namespace cocostudio::timeline;
using namespace tinyxml2;

MainScene::MainScene()
	:m_skillPanel(NULL)
	,m_selectSkillLayer(NULL)
{

}

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
   
	loadUi();
	
	scheduleUpdate();
    return true;
}

void MainScene::loadUi()
{
	auto rootNode = CSLoader::createNode("SelectScene/SelectScene.csb");

	addChild(rootNode);

	auto bgPanel = dynamic_cast<ui::Layout*>(rootNode->getChildByName("BgPanel"));
	m_skillPanel = dynamic_cast<Node*>(bgPanel->getChildByName("SelectSkillPanel"));

	m_selectSkillLayer = SelectSkillLayer::create(m_skillPanel);
	addChild(m_selectSkillLayer);
}

void MainScene::update(float delta)
{

}

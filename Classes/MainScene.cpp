#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SelectSkillLayer.h"
#include "MainCharacter.h"
#include "GameManager.h"
#include "MapLayer.h"

USING_NS_CC;
using namespace cocostudio::timeline;
using namespace tinyxml2;

MainScene::MainScene()
	:m_skillPanel(NULL)
	,m_selectSkillLayer(NULL)
	,m_mapLayer(NULL)
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

	initData();

    return true;
}

void MainScene::loadUi()
{
	auto rootNode = CSLoader::createNode("SelectScene/SelectScene.csb");

	addChild(rootNode);

	// 地图层初始化
	m_mapLayer = MapLayer::create();
	rootNode->addChild(m_mapLayer, MAP_LAYER_ZORDER);

	auto bgPanel = dynamic_cast<ui::Layout*>(rootNode->getChildByName("BgPanel"));

	// 技能选择层初始化
	m_skillPanel = dynamic_cast<Node*>(bgPanel->getChildByName("SelectSkillPanel"));
	m_selectSkillLayer = SelectSkillLayer::create(m_skillPanel);
	addChild(m_selectSkillLayer);

}

void MainScene::initData()
{
	m_mainCharacter = MainCharacter::create();
	m_mapLayer->addChild(m_mainCharacter,CHARACTER_ZORDER);

	GameManager::getInstance()->setMainCharacter(m_mainCharacter);

	GameManager::getInstance()->setGameState(eSelectSkill);
}

void MainScene::update(float delta)
{

}

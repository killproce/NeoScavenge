#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Bag.h"
#include "Prop.h"
USING_NS_CC;

using namespace cocostudio::timeline;

MainScene::MainScene()
	:m_skillPanel(NULL)
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
	
	initTalentBag();

	initFlawBag();

    return true;
}

void MainScene::loadUi()
{
	auto rootNode = CSLoader::createNode("SelectScene/SelectScene.csb");

	addChild(rootNode);

	auto bgPanel = dynamic_cast<ui::Layout*>(rootNode->getChildByName("BgPanel"));
	m_skillPanel = dynamic_cast<Node*>(bgPanel->getChildByName("SelectSkillPanel"));
}

Bag* MainScene::createBag(stBagSize s)
{
	auto pRetBag = Bag::create(stBagSize(12, 24));
	float h = pRetBag->getRealSize().height;
	pRetBag->setPosition(Vec2(0, - h));
	return pRetBag;
}

void MainScene::initTalentBag()
{
	auto bagSelTalentNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("SelectTalent_BagPos"));
	auto bagUseTalentNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("UsedTalent_BagPos"));
	
	auto selectTalentBag = createBag(stBagSize(12, 24));
	bagSelTalentNode->addChild(selectTalentBag);
	bagSelTalentNode->setScale(BAG_SCALE);

	auto useTalentBag = createBag(stBagSize(12, 24));
	bagUseTalentNode->addChild(useTalentBag);
	bagUseTalentNode->setScale(BAG_SCALE);

	// 设置关联包裹
	selectTalentBag->setRelatedBag(useTalentBag);
	useTalentBag->setRelatedBag(selectTalentBag);

	// 
	// 添加技能flag
	//
	auto prop = Prop::create("ItmSkillAth.png");
	prop->SetObjectSize(Size(6, 2));
	selectTalentBag->addItem(prop);

	auto prop1 = Prop::create("ItmSkillBotany.png");
	prop1->SetObjectSize(Size(6, 2));
	selectTalentBag->addItem(prop1);
}

void MainScene::initFlawBag()
{
	auto bagSelFlawNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("SelectFlaw_BagPos"));
	auto bagUseFlawNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("UsedFlaw_BagPos"));

	auto selectFlawBag = createBag(stBagSize(12, 24));
	bagSelFlawNode->addChild(selectFlawBag);
	bagSelFlawNode->setScale(BAG_SCALE);

	auto useFlawBag = createBag(stBagSize(12, 24));
	bagUseFlawNode->addChild(useFlawBag);
	bagUseFlawNode->setScale(BAG_SCALE);

	// 设置关联包裹
	selectFlawBag->setRelatedBag(useFlawBag);
	useFlawBag->setRelatedBag(selectFlawBag);

	// 
	// 添加技能flag
	//
	auto prop = Prop::create("ItmFlawEnervated.png");
	prop->SetObjectSize(Size(6, 2));
	selectFlawBag->addItem(prop);

	auto prop1 = Prop::create("ItmFlawFbl.png");
	prop1->SetObjectSize(Size(6, 2));
	selectFlawBag->addItem(prop1);
}
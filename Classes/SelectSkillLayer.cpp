#include "SelectSkillLayer.h"
#include "Bag.h"
#include "tinyxml2/tinyxml2.h"
#include "Skill.h"

SelectSkillLayer::SelectSkillLayer()
:m_skillPanel(NULL)
, m_usedSkillPoint(0)
, m_leftSkillPoint(15)
, m_usedSkillPointText(NULL)
, m_leftSkillPointText(NULL)
, m_confirmButton(NULL)
, m_randomButton(NULL)
{

}

SelectSkillLayer* SelectSkillLayer::create(Node* panel)
{
	auto pRet = new SelectSkillLayer;
	if (pRet && pRet->init(panel))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool SelectSkillLayer::init(Node* panel)
{
	if (!Layer::init())
	{
		return false;
	}
	m_skillPanel = panel;

	loadUi();

	loadSelectSkillConfig();

	initTalentBag();
	initFlawBag();

	scheduleUpdate();

	return true;
}

void SelectSkillLayer::loadUi()
{
	if (!m_skillPanel)
	{
		return;
	}

	m_usedSkillPointText = dynamic_cast<ui::Text*>(m_skillPanel->getChildByName("UsedSkillPointText"));
	m_leftSkillPointText = dynamic_cast<ui::Text*>(m_skillPanel->getChildByName("LeftSkillPointText"));

	m_confirmButton = dynamic_cast<ui::Button*>(m_skillPanel->getChildByName("ConfirmButton"));
	m_randomButton = dynamic_cast<ui::Button*>(m_skillPanel->getChildByName("RandomButton"));
	m_confirmButton->addClickEventListener(CC_CALLBACK_0(SelectSkillLayer::onConfirmCallback, this));
	m_randomButton->addClickEventListener(CC_CALLBACK_0(SelectSkillLayer::onRandomSelectCallback, this));

}


Bag* SelectSkillLayer::createBag(stBagSize s)
{
	auto pRetBag = Bag::create(stBagSize(12, 24));
	float h = pRetBag->getRealSize().height;
	pRetBag->setPosition(Vec2(0, -h));
	return pRetBag;
}

void SelectSkillLayer::initTalentBag()
{
	auto bagSelTalentNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("SelectTalent_BagPos"));
	auto bagUseTalentNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("UsedTalent_BagPos"));

	m_selectTalentBag = createBag(stBagSize(12, 24));
	bagSelTalentNode->addChild(m_selectTalentBag);
	bagSelTalentNode->setScale(BAG_SCALE);

	m_useTalentBag = createBag(stBagSize(12, 24));
	bagUseTalentNode->addChild(m_useTalentBag);
	bagUseTalentNode->setScale(BAG_SCALE);

	// 设置关联包裹
	m_selectTalentBag->setRelatedBag(m_useTalentBag);
	m_useTalentBag->setRelatedBag(m_selectTalentBag);

	// 
	// 添加技能flag
	//

	for (std::vector<stSelectSkillItem>::iterator it = m_talentSkillItemContainer.begin();
		it != m_talentSkillItemContainer.end(); ++it)
	{
		auto skill = Skill::create(it->skillPoint, it->imgpath);
		skill->SetObjectSize(Size(6, 2));
		m_selectTalentBag->addItem(skill);
	}
}

void SelectSkillLayer::initFlawBag()
{
	auto bagSelFlawNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("SelectFlaw_BagPos"));
	auto bagUseFlawNode = dynamic_cast<Node*>(m_skillPanel->getChildByName("UsedFlaw_BagPos"));

	m_selectFlawBag = createBag(stBagSize(12, 24));
	bagSelFlawNode->addChild(m_selectFlawBag);
	bagSelFlawNode->setScale(BAG_SCALE);

	m_useFlawBag = createBag(stBagSize(12, 24));
	bagUseFlawNode->addChild(m_useFlawBag);
	bagUseFlawNode->setScale(BAG_SCALE);

	// 设置关联包裹
	m_selectFlawBag->setRelatedBag(m_useFlawBag);
	m_useFlawBag->setRelatedBag(m_selectFlawBag);

	// 
	// 添加技能flag
	//

	for (std::vector<stSelectSkillItem>::iterator it = m_flawSkillItemContainer.begin();
		it != m_flawSkillItemContainer.end(); ++it)
	{
		auto skill = Skill::create(it->skillPoint, it->imgpath);
		skill->SetObjectSize(Size(6, 2));
		m_selectFlawBag->addItem(skill);
	}
}

void SelectSkillLayer::setUsedSkillPoint(int usePoint)
{
	m_usedSkillPoint = usePoint;
}

void SelectSkillLayer::addUsedSkillPoint(int num)
{
	m_usedSkillPoint += num;
}

void SelectSkillLayer::setLeftSkillPoint(int leftPoint)
{
	m_leftSkillPoint = leftPoint;
}

void SelectSkillLayer::addLeftSkillPoint(int num)
{
	m_leftSkillPoint += num;
}

void SelectSkillLayer::refreshSkillPoint()
{
	auto usedTalentContainers = m_useTalentBag->getItemContainers();
	auto usedFlawContainers = m_useFlawBag->getItemContainers();
	int usedTalentPoint = 0;
	int usedFlawPoint = 0;
	for (Bag::ItemContainer::const_iterator it = usedTalentContainers.begin();
		it != usedTalentContainers.end(); ++it)
	{
		usedTalentPoint += dynamic_cast<Skill*>(*it)->getSkillPoint();
	}

	for (Bag::ItemContainer::const_iterator it = usedFlawContainers.begin();
		it != usedFlawContainers.end(); ++it)
	{
		usedFlawPoint += dynamic_cast<Skill*>(*it)->getSkillPoint();
	}

	setUsedSkillPoint(usedTalentPoint);
	int leftPoint = 15 + usedFlawPoint - usedTalentPoint;
	setLeftSkillPoint(leftPoint);

	char str[100];
	sprintf(str, "%d", getUsedSkillPoint());
	m_usedSkillPointText->setText(str);
	sprintf(str, "%d", getLeftSkillPoint());
	m_leftSkillPointText->setText(str);
}

void SelectSkillLayer::update(float delta)
{
	refreshSkillPoint();
}

void SelectSkillLayer::loadSelectSkillConfig()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("config/SelectSkillConfig.xml");
	auto rootNode = doc.RootElement();

	m_talentSkillItemContainer.clear();
	auto talentNode = rootNode->FirstChildElement("TalentSkill");
	if (talentNode)
	{
		auto skillNode = talentNode->FirstChildElement("Skill");
		while (skillNode)
		{
			stSelectSkillItem item;
			item.id = skillNode->UnsignedAttribute("id");
			item.skillPoint = skillNode->IntAttribute("point");
			item.imgpath = skillNode->Attribute("imgpath");
			m_talentSkillItemContainer.push_back(item);

			skillNode = skillNode->NextSiblingElement();
		}
	}

	m_flawSkillItemContainer.clear();
	auto flawNode = rootNode->FirstChildElement("FlawSkill");
	if (flawNode)
	{
		auto skillNode = flawNode->FirstChildElement("Skill");
		while (skillNode)
		{
			stSelectSkillItem item;
			item.id = skillNode->UnsignedAttribute("id");
			item.skillPoint = skillNode->IntAttribute("point");
			item.imgpath = skillNode->Attribute("imgpath");
			m_flawSkillItemContainer.push_back(item);

			skillNode = skillNode->NextSiblingElement();
		}
	}
}

void SelectSkillLayer::onConfirmCallback()
{

}

void SelectSkillLayer::onRandomSelectCallback()
{

}
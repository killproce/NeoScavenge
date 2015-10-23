#ifndef __SELECT_SKILL_LAYER_H__
#define __SELECT_SKILL_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "public.h"
USING_NS_CC;


struct stSelectSkillItem
{
	stSelectSkillItem()
	:id(0)
	, skillPoint(0)
	, imgpath("")
	{
	}
	unsigned int id;
	int skillPoint;
	std::string imgpath;
};

class Bag;

class SelectSkillLayer : public Layer
{
public:
	SelectSkillLayer();
	bool init(Node* panel);
	static SelectSkillLayer* create(Node* panel);

	virtual void update(float delta);
	void loadUi();

	Bag* createBag(stBagSize s);
	void initTalentBag();
	void initFlawBag();

	void setUsedSkillPoint(int usePoint);
	int getUsedSkillPoint(){ return m_usedSkillPoint; }
	void addUsedSkillPoint(int num);
	void setLeftSkillPoint(int leftPoint);
	int getLeftSkillPoint(){ return m_leftSkillPoint; }
	void addLeftSkillPoint(int num);
	void refreshSkillPoint();

	void loadSelectSkillConfig();
protected:
	void onConfirmCallback();
	void onRandomSelectCallback();
private:
	Bag* m_selectTalentBag;
	Bag* m_useTalentBag;
	Bag* m_selectFlawBag;
	Bag* m_useFlawBag;

	std::vector<stSelectSkillItem> m_talentSkillItemContainer;
	std::vector<stSelectSkillItem> m_flawSkillItemContainer;

	int m_usedSkillPoint;
	int m_leftSkillPoint;
	ui::Text* m_usedSkillPointText;
	ui::Text* m_leftSkillPointText;

	Node* m_skillPanel;

	ui::Button* m_confirmButton;
	ui::Button* m_randomButton;
};

#endif	// __SELECT_SKILL_LAYER_H__
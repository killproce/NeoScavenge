#include "Skill.h"

Skill::Skill()
	:m_skillPoint(0)
{

}

Skill::~Skill()
{

}

Skill* Skill::create(int skillPoint /* = 0 */,const std::string& filename /* = "" */)
{
	auto pRet = new Skill;
	if (pRet && pRet->init(skillPoint,filename))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool Skill::init(int skillPoint,const std::string& filename)
{
	if (!Prop::init(filename))
	{
		return false;
	}

	m_skillPoint = skillPoint;

	return true;
}

Skill* Skill::create(unsigned int skillId)
{
	auto pRet = new Skill;
	if (pRet && pRet->init(skillId))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool Skill::init(unsigned int skillPonit)
{
	
	return true;
}
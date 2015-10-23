#ifndef __SKILL_H__
#define __SKILL_H__

#include "Prop.h"

class Skill: public Prop
{
public:
	Skill();
	~Skill();

	bool init(int skillPoint,const std::string& filename);
	static Skill* create(int skillPoint = 0,const std::string& filename = "");

	bool init(unsigned int skillId);
	static Skill* create(unsigned int skillId);


	void setSkillPoint(int num){ m_skillPoint = num; }
	int getSkillPoint()const{ return m_skillPoint; }

	void setSkillID(int id){ m_skillID = id; }
	unsigned int getSkillID() const { return m_skillID; }
private:
	int m_skillPoint;
	unsigned int m_skillID;
};

#endif	// __SKILL_H__
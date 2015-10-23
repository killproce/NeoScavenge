#ifndef __PROP_H__
#define __PROP_H__

#include "ObjectBase.h"
#include "FlawHint.h"

enum PropType
{
	eSkillFlag,
	ePropTypeNum
};

class FlawHint;

class Prop : public ObjectBase
{
public:
	virtual bool init(const std::string& filename);
	static Prop* create(const std::string& filename);

	void SetPropType(PropType type){ m_propType = type; }
	PropType GetPropType(){ return m_propType; }
	void SetPropImg(Sprite* img){ m_pImg = img; }
	const Sprite* GetPropImg()const{ return m_pImg; }
	void SetFlawHint(FlawHint* hints){ m_hints = hints; }
	const FlawHint* GetFlawHint()const{ return m_hints; }
private:
	PropType m_propType;
	Sprite* m_pImg;
	
	FlawHint* m_hints;
};

#endif	// __PROP_H__
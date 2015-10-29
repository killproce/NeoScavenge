#ifndef __MAIN_CHARACTER_H__
#define __MAIN_CHARACTER_H__

#include "ObjectBase.h"
#include "cocos2d.h"
#include "public.h"
USING_NS_CC;

class MainCharacter : public ObjectBase
{
public:
	MainCharacter();

	virtual bool init();
	static MainCharacter* create();

	stMapPos getPosInMap(){ return m_posInMap; }
	void setPosInMap(stMapPos& pos) { m_posInMap = pos; refreshData(); }

	void refreshData();
	void setStrength(int strength) { m_strength = strength; }
	int getStrength() { return m_strength; }
private:
	stMapPos m_posInMap; // 用行列表示主角在地图上的位置
	Sprite* m_characterImg;
	int m_strength; // 体力
};

#endif	// __MAIN_CHARACTER_H__
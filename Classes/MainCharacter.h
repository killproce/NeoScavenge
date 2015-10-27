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

	const stMapPos& getPosInMap() const { return m_posInMap; }
	void setPosInMap(stMapPos& pos){ m_posInMap = pos; }
private:
	stMapPos m_posInMap; // �����б�ʾ�����ڵ�ͼ�ϵ�λ��
	Sprite* m_characterImg;
};

#endif	// __MAIN_CHARACTER_H__
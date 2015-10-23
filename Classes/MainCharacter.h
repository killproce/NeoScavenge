#ifndef __MAIN_CHARACTER_H__
#define __MAIN_CHARACTER_H__

#include "ObjectBase.h"
USING_NS_CC;

class MainCharacter : public ObjectBase
{
public:
	virtual bool init();
	static MainCharacter* create();

};

#endif	// __MAIN_CHARACTER_H__
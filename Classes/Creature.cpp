#include "Creature.h"

bool Creature::init()
{
	if (!ObjectBase::init())
	{
		return false;
	}

	return true;
}
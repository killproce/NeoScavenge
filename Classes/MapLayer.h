#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class MapLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);

};

#endif	// __MAP_LAYER_H__
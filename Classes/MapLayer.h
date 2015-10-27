#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

const float START_X = 300;
const float START_Y = 400;
const float OFFSET_Y = 36.0;

class MapLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);

	void drawMap();
	
	void initMap();
};

#endif	// __MAP_LAYER_H__
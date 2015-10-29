#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__

#include "cocos2d.h"
#include "public.h"
USING_NS_CC;

class MapLayer : public Layer
{
public:
	MapLayer();

	virtual bool init();
	CREATE_FUNC(MapLayer);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void initData();

	void drawMap();
	
	void initMap();
private:
	Sprite* m_hexSelectValidBox;
	Sprite* m_hexSelectInvalidBox;
	stMapPos m_curHexSelectBoxPos;
};

#endif	// __MAP_LAYER_H__
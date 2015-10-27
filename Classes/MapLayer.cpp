#include "MapLayer.h"
#include "HexTile.h"

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto tile1 = HexTile::createWithID(1);
	tile1->setPosition(Vec2(500, 400));
	addChild(tile1);

	auto pos = tile1->convertToWorldSpace(Vec2(0, 0));
	CCLOG("tile Pos: x = %f, y = %f\n", pos.x, pos.y);
	return true;
}
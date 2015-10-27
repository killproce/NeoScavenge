#include "MapLayer.h"
#include "HexTile.h"
#include "MapManager.h"
#include "public.h"

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initMap();
	return true;
}

void MapLayer::drawMap()
{

}

void MapLayer::initMap()
{
	auto mapMgr = MapManager::getInstance();
	int rows = mapMgr->getMapRows();
	int cols = mapMgr->getMapCols();
	for (int row = rows; row >= 1; --row)
	{
		for (int col = cols; col >= 1; --col)
		{
			int tileId = mapMgr->getMapDataAt(row, col);
			if (tileId)
			{
				auto tile = HexTile::createWithID(tileId);

				float x = START_X;
				float y = START_Y ;
				int numr = row / 2;
				int numc = col - 1;
				if (row % 2)
				{
					x += TILE_START_WIDTH_1 + numc * TILE_WIDTH_DISTANCE;
					y += TILE_START_HEIGHT_1 + numr * TILE_HEIGHT_DISTANCE;
				}
				else
				{
					x += TILE_START_WIDTH_2 + numc * TILE_WIDTH_DISTANCE;
					y += TILE_START_HEIGHT_2 + (numr - 1) * TILE_HEIGHT_DISTANCE;
				}
				tile->setPosition(Vec2(x, y));
				addChild(tile);
			}
		}
	}
}
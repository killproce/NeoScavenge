#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#define MAX_BAG_SIZE 100
#define CELL_SIZE 10

#define BAG_SCALE 1.8

struct stBagSize
{
	stBagSize() :row(0), col(0)
	{
	}
	stBagSize(int r, int c):row(r),col(c)
	{
	}
	int row;
	int col;
};

struct stMapPos
{
	int row;
	int col;
	stMapPos() :row(0), col(0){}
	stMapPos(int r,int c) :row(r), col(c){}

	bool operator==(const stMapPos& rh)
	{
		return row == rh.row && col == rh.col;
	}
};

#define TILE_WIDTH 100.0
#define TILE_HEIGHT 50.0
#define TILE_WIDTH_DISTANCE 160.0
#define TILE_HEIGHT_DISTANCE 40.0
#define TILE_START_WIDTH_1 0.0
#define TILE_START_WIDTH_2 80.0
#define TILE_START_HEIGHT_1 0.0
#define TILE_START_HEIGHT_2 20.0


const float START_X = 300;
const float START_Y = 400;
const float OFFSET_Y = 36.0;


enum eGameState
{
	eNone,
	eSelectSkill,
	eGameRunning,
};

#define MAP_LAYER_ZORDER -10
#define HEX_TILE_ZORDER 5
#define SELECT_BOX_ZORDER 10
#define CHARACTER_ZORDER 20

#define MAX_MAP_SIZE 1000

#endif	// __PUBLIC_H__
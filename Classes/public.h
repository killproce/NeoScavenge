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
};

#define TILE_WIDTH 100.0
#define TILE_HEIGHT 50.0
#define TILE_WIDTH_DISTANCE 160.0
#define TILE_HEIGHT_DISTANCE 40.0
#define TILE_START_WIDTH_1 0.0
#define TILE_START_WIDTH_2 80.0
#define TILE_START_HEIGHT_1 0.0
#define TILE_START_HEIGHT_2 20.0

#endif	// __PUBLIC_H__
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

#endif	// __PUBLIC_H__
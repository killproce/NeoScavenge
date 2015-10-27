#ifndef __MAP_DATA_H__
#define __MAP_DATA_H__

#include <vector>

class MapData
{
public:
	MapData(int row,int col);

	~MapData();

	int getMapRow() { return m_row; }
	int getMapCol() { return m_col; }
	unsigned int getTileIDAt(int row, int col);
	void addData(int row, int col, unsigned int id);
private:
	int m_row;
	int m_col;
	std::vector<int> m_vecTileIDs;
};

#endif	// __MAP_DATA_H__
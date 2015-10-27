#include "MapData.h"

MapData::MapData(int row, int col)
: m_row(row)
, m_col(col)
{
	m_vecTileIDs.resize((row + 1) * (col + 1));
	for (std::vector<int>::iterator it = m_vecTileIDs.begin();
		it != m_vecTileIDs.end(); ++it)
	{
		(*it) = 0;
	}
}

MapData::~MapData()
{
	
}

unsigned int MapData::getTileIDAt(int row, int col)
{
	int pos = (row - 1) * m_col + col;
	if (pos < m_vecTileIDs.size())
	{
		return m_vecTileIDs.at(pos);
	}
	return 0;
}

void MapData::addData(int row, int col, unsigned int id)
{
	if (row <= 0 || row > m_row || col <= 0 || col > m_col)
	{
		return;
	}

	int pos = (row - 1) * m_col + col;
	m_vecTileIDs[pos] = id;
}
#include "ObjectBase.h"

bool ObjectBase::init()
{
	static unsigned int curId = 0;

	if (!Node::init())
		return false;

	m_uid = curId++;

	return true;
}

bool ObjectBase::isContainPoint(Point p)
{
	if (m_pos.x <= p.x && m_pos.y <= p.y &&
		p.x < m_pos.x + m_size.height && p.y < m_pos.y + m_size.width)
	{
		return true;
	}
	return false;
}
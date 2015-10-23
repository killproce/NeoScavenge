#ifndef __OBJECT_BASE_H__
#define __OBJECT_BASE_H__

#include "cocos2d.h"
USING_NS_CC;

class ObjectBase : public Node
{
public:
	virtual bool init();

	void SetObjectID(unsigned int uid){ m_uid = m_uid; }
	unsigned int GetObjectID() { return m_uid; }
	void SetObjectPos(Vec2 pos){ m_pos = pos; }
	Vec2 GetObjectPos(){ return m_pos; }
	void SetObjectSize(Size s){ m_size = s; }
	Size GetObjectSize(){ return m_size; }

	bool isContainPoint(Point p);
protected:
	unsigned int m_uid;		// 物体id
	Vec2 m_pos;				// 位置
	Size m_size;			// 大小
};

#endif	// __OBJECT_BASE_H__
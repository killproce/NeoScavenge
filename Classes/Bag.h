#ifndef __BAG_H__
#define __BAG_H__

#include "cocos2d.h"
#include "public.h"
USING_NS_CC;

enum eBagCellState
{
	eBagCellFree,
	eBagCellOccupy
};

class ObjectBase;

class Bag : public Layer
{
public:
	Bag();
	~Bag();

	virtual bool initWithSize(stBagSize s);
	static Bag* create(stBagSize s);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

	virtual void refreshBag();

	void setBagSize(stBagSize s){
		m_bagSize = s;
		refreshBag();
	}
	stBagSize getBagSize(){
		return m_bagSize;
	}

	void clearAllItem();
	bool findPositionForItem(ObjectBase* obj,Point& p);
	bool addItem(ObjectBase* obj);
	ObjectBase* getItemAt(Point& p);
	void removeItem(ObjectBase* obj);
	void removeItem(Point& p);
	void settleBag();

	void setBagCellStateWithRect(Rect& r,eBagCellState state);
	bool isCanPutDow(Point& p, Size& s);

	void setRelatedBag(Bag* bag){
		m_relatedBag = bag;
	}
	Bag* getRelatedBag(){
		return m_relatedBag;
	}
	
	void setRealSize(Size& s){
		m_realSize = s;
	}
	Size getRealSize(){
		return m_realSize;
	}


public:
	
	typedef std::vector<ObjectBase*> ItemContainer;
	typedef ItemContainer::iterator ItemConIter;

public:
	const ItemContainer& getItemContainers() const { return m_itemContainers; }
protected:
	Sprite* m_bgImg;
	stBagSize m_bagSize; //格子数
	eBagCellState m_bagCellState[MAX_BAG_SIZE][MAX_BAG_SIZE]; // 包裹占用状态
	ItemContainer m_itemContainers;
	Bag* m_relatedBag; // 关联的包裹，两者之间的物品可以互相转移
	Size m_realSize;  // 真实像素大小
};

#endif	// __BAG_H__
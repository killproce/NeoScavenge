#include "Bag.h"
#include "ObjectBase.h"

Bag::Bag()
	:m_bgImg(NULL),
	m_relatedBag(NULL)
{

}

Bag::~Bag()
{

}

Bag* Bag::create(stBagSize s)
{
	auto pRet = new Bag;
	if (pRet && pRet->initWithSize(s))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;
}

bool Bag::initWithSize(stBagSize s)
{
	if (!Layer::init())
	{
		return false;
	}

	// ÉèÖÃ°ü¹ü±³¾°Í¼
	m_bagSize = s;
	float w = CELL_SIZE * s.col;
	float h = CELL_SIZE * s.row;
	m_bgImg = Sprite::create("GUIGrid.png",Rect(0,0,w,h));
	m_bgImg->setPosition(Vec2(w / 2, h / 2));
	addChild(m_bgImg);

	m_realSize = Size(w, h);

	// ´¥ÃþÉèÖÃ
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Bag::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Bag::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Bag::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool Bag::onTouchBegan(Touch *touch, Event *unused_event)
{

	return true;
}

void Bag::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Bag::onTouchEnded(Touch *touch, Event *unused_event)
{
	auto bagPos = this->getPosition();
	auto pos = touch->getLocation();
	pos = this->convertToNodeSpace(pos);
	CCLOG("Bag position: x = %d,y = %d\n", pos.x, pos.y);

	float x = pos.x;
	float y = m_bagSize.row * CELL_SIZE - pos.y;
	int row = y / CELL_SIZE;
	int col = x / CELL_SIZE;
	auto touchedObj = getItemAt(Point(row, col));
	if (touchedObj)
	{
		this->removeItem(touchedObj);
		if (!m_relatedBag)
			return;
		m_relatedBag->addItem(touchedObj);
	}
}

void Bag::clearAllItem()
{
	setBagCellStateWithRect(Rect(0, 0, m_bagSize.col, m_bagSize.row),eBagCellFree);
	
	for (ItemConIter it = m_itemContainers.begin();
		it != m_itemContainers.end();)
	{
		(*it)->removeFromParent();
		it = m_itemContainers.erase(it);
	}
}

bool Bag::findPositionForItem(ObjectBase* obj,Point& p)
{
	for (int r = 0; r < m_bagSize.row; ++r)
	{
		for (int c = 0; c < m_bagSize.col; ++c)
		{
			if (isCanPutDow(Point(r, c), obj->GetObjectSize()))
			{
				p = Point(r, c);
				return true;
			}
		}
	}
	return false;
}

bool Bag::addItem(ObjectBase* obj)
{
	Point objPos;
	if (!findPositionForItem(obj, objPos))
		return false;

	obj->SetObjectPos(objPos);
	setBagCellStateWithRect(Rect(objPos, obj->GetObjectSize()), eBagCellOccupy);
	
	Size objSize = obj->GetObjectSize();
	float x = objPos.y * CELL_SIZE;
	float y = objPos.x * CELL_SIZE;
	float totalX = m_bagSize.col * CELL_SIZE;
	float totalY = m_bagSize.row * CELL_SIZE;
	x += objSize.width * CELL_SIZE / 2.0;
	y = totalY - (y + objSize.height * CELL_SIZE / 2.0);
	obj->setPosition(Vec2(x, y));
	addChild(obj);

	m_itemContainers.push_back(obj);

	return true;
}

ObjectBase* Bag::getItemAt(Point& p)
{
	for (auto it : m_itemContainers)
	{
		if (it->isContainPoint(p))
		{
			return it;
		}
	}
	return NULL;
}

void Bag::removeItem(ObjectBase* obj)
{
	for (ItemConIter it = m_itemContainers.begin();
		it != m_itemContainers.end(); ++it)
	{
		if ((*it)->GetObjectID() == obj->GetObjectID())
		{
			setBagCellStateWithRect(Rect(obj->GetObjectPos(), obj->GetObjectSize()),eBagCellFree);
			obj->retain();
			obj->removeFromParent();
			m_itemContainers.erase(it);
			return;
		}
	}
}

void Bag::removeItem(Point& p)
{
	for (ItemConIter it = m_itemContainers.begin();
		it != m_itemContainers.end(); ++it)
	{
		if ((*it)->isContainPoint(p))
		{
			setBagCellStateWithRect(Rect((*it)->GetObjectPos(), (*it)->GetObjectSize()), eBagCellFree);
			(*it)->removeFromParent();
			m_itemContainers.erase(it);
		}
	}
}

void Bag::settleBag()
{

}

void Bag::setBagCellStateWithRect(Rect& r,eBagCellState state)
{
	Point p = r.origin;
	Size s = r.size;
	for (int i = p.x; i < p.x + s.height; ++i)
		for (int j = p.y; j < p.y + s.width; ++j)
			m_bagCellState[i][j] = state;
}

bool Bag::isCanPutDow(Point& p, Size& s)
{
	for (int i = p.x; i < p.x + s.height; ++i)
		for (int j = p.y; j < p.y + s.width; ++j)
			if (m_bagCellState[i][j] == eBagCellOccupy)
				return false;
	return true;
}

void Bag::refreshBag()
{
	// ÉèÖÃ°ü¹ü±³¾°Í¼
	float w = CELL_SIZE * m_bagSize.col;
	float h = CELL_SIZE * m_bagSize.row;
	if (m_bgImg)
	{
		m_bgImg->setTextureRect(Rect(0, 0, w, h));
	}

	m_realSize = Size(w, h);
}
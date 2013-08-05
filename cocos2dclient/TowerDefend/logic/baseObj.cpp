#include "StdAfx.h"
#include "baseObj.h"


baseObj::baseObj(void)
	:_objType(ObjType_NULL),_isInWorld(false),
	_enLifeState(ObjLifeState_Alife),_maxLife(0),
	_currentLife(0),
	_canbeAttack(false),
	_block(false)
{
	_createPos.x = 0.f;
	_createPos.y = 0.f;
}


baseObj::~baseObj(void)
{
}


void baseObj::onAddToWorld()
{
	_isInWorld = true;
}

void baseObj::onRemoveFromWorld()
{
	_isInWorld = false;
}

void baseObj::set_createPos(const CCPoint& pos)
{
	_createPos = pos;
}

void baseObj::setPosition(float x, float y)
{
	_currentPoint.x = x;
	_currentPoint.y = y;
	CCNode::setPosition(_currentPoint);
}

void baseObj::actionChange()
{

}

void baseObj::set_lifeState(enObjLifeState en)
{
	if (_enLifeState != en)
	{
		_enLifeState = en;
		if (_isInWorld)
		{
			actionChange();
		}
	}
	

}


CCPoint baseObj::get_createPos()
{
	return _createPos;
}
#include "StdAfx.h"
#include "baseObj.h"


baseObj::baseObj(void)
	:_objType(ObjType_NULL),_isInWorld(false),
	_enLifeState(ObjLifeState_Alife),_maxLife(0),
	_currentLife(0)
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

void baseObj::set_lifeState(enObjLifeState en)
{
	_enLifeState = en;

}


CCPoint baseObj::get_createPos()
{
	return _createPos;
}
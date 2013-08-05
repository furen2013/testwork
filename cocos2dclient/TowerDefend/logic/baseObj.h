#pragma once
#ifndef BASE_OBJ_H
#define BASE_OBJ_H
//#include "cocos2d.h"
using namespace cocos2d;
//NS_CC_BEGIN
enum enObjType
{
	ObjType_NULL,
	ObjType_Creature,
	ObjType_MapComponent,
	ObjType_MapStaticComponent,
};

enum enObjLifeState
{
	ObjLifeState_Alife,
	ObjLifeState_Die,
	ObjLifeState_Dead,
};

class baseObj : public CCNode
{
public:
	baseObj(void);
	virtual ~baseObj(void);
public:
	virtual void LoadResource(const char* config){};
	virtual void onAddToWorld();
	virtual void onRemoveFromWorld();
public:
	virtual void set_createPos(const CCPoint& pos);
	virtual void setPosition(float x, float y);
	virtual void actionChange();
	virtual CCPoint get_createPos();
	enObjType getObjType(){return _objType;}
	virtual void set_lifeState(enObjLifeState en);
	enObjLifeState get_lfieState()
	{
		return _enLifeState;
	}

public:
	void set_maxLife(int maxlife)
	{
		_maxLife = maxlife;
	}
	int get_maxLife()
	{
		return _maxLife;
	}
	void set_currentLife(int currentlife)
	{
		_currentLife = currentlife;
	}
	int get_currentLife()
	{
		return _currentLife;
	}
protected:
	CCPoint			_createPos;
	enObjType		_objType;
	bool			_isInWorld;
	enObjLifeState	_enLifeState;
	int			   	_maxLife;
	int				_currentLife;
	CCPoint			_currentPoint;
	bool			_canbeAttack;
	bool			_block;
};

#endif


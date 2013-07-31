#pragma once
#ifndef BASE_CREATURE_H
#define BASE_CREATURE_H
#include "baseObj.h"
enum enCreatureDir
{
	CreatureDir_Up,
	CreatureDir_Left,
	CreatureDir_Down,
	CreatureDir_Right,
	CreatureDir_Max
};


enum enCreatureActionState
{
	CreatureState_Stop,
	CreatureState_Move,
	CreatureState_Dead,
	CreatureState_Max
};
class baseCreature :
	public baseObj
{
public:
	baseCreature(void);
	virtual ~baseCreature(void);
public:
	virtual void LoadResource(const char* config);
	virtual void onAddToWorld();
	virtual void onRemoveFromWorld();
	virtual void onEnter();
	virtual void setPosition(float x, float y);


public:
	virtual void setDir(enCreatureDir en);
	inline enCreatureDir getDir()
	{
		return _enDir;
	}

	virtual void setCreatureState(enCreatureActionState en);
	inline enCreatureActionState getCreatureState()
	{
		return _enState;
	}
	virtual void set_speed(float speed)
	{
		_speed = speed;
	}

	virtual void set_configSpeed(float speed)
	{
		_configSpeed = speed;
	}
	float get_speed()
	{
		return _speed;
	}

	float get_configSpeed()
	{
		return _configSpeed;
	}

protected:
	virtual void onSpriteChange();
protected:
	enCreatureDir		  _enDir;
	enCreatureActionState _enState;
	float				  _speed;
	float				  _configSpeed;
	//CCAnimation*		  _Animation[CreatureDir_Max][CreatureState_Max];
	std::vector<CCAnimation*> _SourceAni;
	std::string			  _name;

	std::string		      _resourseName;
	CCAnimation*		  _currentAnimation;
	CCAnimate*			  _currentAnimate;
	CCSprite*			  _currentSprite;
	CCActionInterval*	  _actionInterval[CreatureDir_Max][CreatureState_Max];



};

#endif
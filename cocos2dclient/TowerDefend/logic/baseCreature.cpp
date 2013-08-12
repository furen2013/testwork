#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "TDWorld.h"
#include "CreatureStorage.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop),
	_currentAnimate(NULL),_currentSprite(NULL),
	_isArriver(false)
{

	_currentAnimation = NULL;
	_currentAction = NULL;


}

baseCreature::~baseCreature(void)
{

}

void baseCreature::LoadResource(const char* config)
{
	_currentPoint = _createPos;
	_resourseName = config;
	//std::string imgae;
	//for (int i = 0; i < CreatureDir_Max; i ++)
	//{
	//	for (int j = 0; j < CreatureState_Max; j ++)
	//	{
	//		imgae = _defaultDirImageKey[i] + "_" + _defaultStateImageKey[j] + "_" +_resourseName  ;
	//		CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(imgae.c_str());
	//		_actionInterval[i][j] = CCRepeat::create(CCAnimate::create(animation), 111);
	//		
	//	}
	//}
	_currentSprite =  CCSprite::create();
	addChild(_currentSprite);


}


void baseCreature::onEnter()
{
	baseObj::onEnter();
	onAddToWorld();

}


void baseCreature::onRemoveFromWorld()
{
	baseObj::onRemoveFromWorld();
}


void baseCreature::onAddToWorld()
{
	baseObj::onAddToWorld();


}

void baseCreature::setDir(enCreatureDir en)
{
	if (_enDir != en)
	{
		_enDir = en;
		if (_isInWorld)
		{
			actionChange();
		}
	}
}


void baseCreature::actionChange()
{

	if (_currentSprite->isRunning())
	{
		_currentSprite->stopAllActions();
	}

	string imgae = _defaultDirImageKey[_enDir] + "_" + _defaultStateImageKey[_enState] + "_" +_resourseName  ;
	CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(imgae.c_str());
	_currentAction = _currentSprite->runAction(CCRepeat::create(CCAnimate::create(animation), 50));

}


bool baseCreature::isHaveWay()
{
	return _isHaveWay;
}

bool baseCreature::isArriver()
{
	if (_isArriver == true)
	{
		return true;
	}
	gameMap* map = TDWorld::getSingleton().get_gameMap();
	if (map)
	{
		_isArriver = map->isArrived(_currentPoint);
	}
	return _isArriver;
}

void baseCreature::createWay()
{
	if (_isArriver)
	{
		return;
	}
	_mapWay.reset();
	gameMap* map =TDWorld::getSingleton().get_gameMap();
	if (map)
	{
		_isHaveWay = map->getFullWay(_currentPoint, _mapWay._vcFullWay);
	}
}

void baseCreature::setCreatureState(enCreatureActionState en)
{
	if (_enState != en)
	{
		_enState = en;
		if (_isInWorld)
		{
			actionChange();
		}
	}

}

void baseCreature::setPosition(float x, float y)
{
	baseObj::setPosition(x,y);
	if (_currentSprite)
	{
		_currentSprite->setPosition(_currentPoint);
	}

}

void baseCreature::update(float dt)
{
	baseObj::update(dt);
	if (_enState == CreatureState_Move)
	{
		float movedistance = dt * _speed;
		float overmoverdistance = 0.f;
		CCPoint pos = _currentPoint;
		switch(_enDir)
		{
		case CreatureDir_Down:
			{
				pos.y += movedistance;
				overmoverdistance = pos.y - _nextCellCenterPoint.y
			}
			break;
		case CreatureDir_Up:
			{
				pos.y -= movedistance;
				overmoverdistance = _nextCellCenterPoint.y - pos.y;
			}
			break;
		case CreatureDir_Left:
			{
				pos.x -= movedistance;
				overmoverdistance = _nextCellCenterPoint.x - pos.x;
			}
			break;
		case CreatureDir_Right:
			{
				pos.x += movedistance;
				overmoverdistance = pos.x - _nextCellCenterPoint.x;
			}
			break;
		}
		if (overmoverdistance > 0)
		{
			if (_mapWay.mapWay)
			{
			}
		}
	}

}
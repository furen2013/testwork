#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "TDWorld.h"
#include "CreatureStorage.h"
#include "mapComponent/gameMap.h"

bool bfirst = true;
baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop),
	_currentAnimate(NULL),_currentSprite(NULL),
	_isArriver(false),
	_isHaveWay(false)
{

	_currentAnimation = NULL;
	_currentAction = NULL;


}

baseCreature::~baseCreature(void)
{

}


void baseCreature::createCreature(creatureInfo* info)
{
	_configSpeed = info->_speed;
	_speed = info->_speed;
	_name = info->_name;
	_resourseName = info->_resourceName;
	_maxLife = _currentLife = info->_life;
	LoadResource(_resourseName.c_str());
	gameMap* map = TDWorld::getSingleton().get_gameMap();
	_currentPoint = _createPos = map->getStartPt();
	_endPos = map->getEndPt();
	createWay();
	//if (bfirst == true)
	//{
	//	bfirst = false;
	//	for (int i = 0; i < _mapWay._vcFullWay.size(); i ++)
	//	{
	//		baseCreature* p = CreatureStorage::getSingleton().CreateCreature(1);
	//		if (p)
	//		{
	//			p->setPosition(_mapWay._vcFullWay[i].x, _mapWay._vcFullWay[i].y);
	//			TDWorld::getSingleton().addChild(p);
	//		}

	//	}
	//}
	if (_mapWay._vcFullWay.empty() == false)
	{
		_nextCellCenterPoint = _mapWay._vcFullWay[_mapWay.generateNextIndex()];
	}
	

	setPosition(_currentPoint.x, _currentPoint.y);
	setDir(GetNaxtPointDir());
	setCreatureState(CreatureState_Move);
	scheduleUpdate();
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
	actionChange();

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
	_currentAction = _currentSprite->runAction(CCRepeat::create(CCAnimate::create(animation), 500));

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
		_mapWay._index = _mapWay._vcFullWay.size() - 1;
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
	//if (_currentSprite)
	//{
	//	_currentSprite->setPosition(_currentPoint);
	//}

}


enCreatureDir baseCreature::GetNaxtPointDir()
{
	if (_currentPoint.x < _nextCellCenterPoint.x)
	{
		return CreatureDir_Right;
	}
	else if (_currentPoint.x > _nextCellCenterPoint.x)
	{
		return CreatureDir_Left;
	}
	else if (_currentPoint.y > _nextCellCenterPoint.y)
	{
		return CreatureDir_Up;
	}
	else if (_currentPoint.y < _nextCellCenterPoint.y)
	{
		return CreatureDir_Down;
	}
	return CreatureDir_Max;
}


CCPoint baseCreature::moveDistance(CCPoint curPoint, float& movedistance, enCreatureDir dir)
{

	//float movedistance = dt * _speed;
	float overmoverdistance = 0.f;
	CCPoint pos = curPoint;
	switch(_enDir)
	{
	case CreatureDir_Down:
		{
			pos.y += movedistance;
			overmoverdistance = pos.y - _nextCellCenterPoint.y;
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
	if (overmoverdistance > 0.f)
	{
		pos = _nextCellCenterPoint;
	}

	movedistance = overmoverdistance;
	return pos;
}

void baseCreature::update(float dt)
{
	baseObj::update(dt);
	if (_enState == CreatureState_Move)
	{
		float movedistance = dt * _speed;

		CCPoint pos = moveDistance(_currentPoint, movedistance, _enDir);

		if (movedistance > 0)
		{
			if (_isHaveWay)
			{
				if (_mapWay.isArrive() == false)
				{
					_nextCellCenterPoint = _mapWay._vcFullWay[_mapWay.generateNextIndex()];
					setDir(GetNaxtPointDir());
					pos = moveDistance(pos, movedistance, _enDir);
				
				}
			
			}
			else
			{
				gameMap* map = TDWorld::getSingleton().get_gameMap();
				if (map)
				{
					_isArriver = map->isArrived(pos);
					_currentPoint = pos;
					
				}
			}
		}

		setPosition(pos.x, pos.y);
	}

}
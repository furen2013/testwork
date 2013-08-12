#include "StdAfx.h"
#include "mapStaticCell.h"
#include "../ResourceManager/TDResourceManager.h"
#include "mapComponentStorage.h"


mapStaticCell::mapStaticCell(void)
	:_currentSprite(NULL)
{
}


mapStaticCell::~mapStaticCell(void)
{
}



void mapStaticCell::CreateCell(mapComponentTG* tg)
{
	_maxLife = tg->_life;
	_currentLife = _maxLife;
	_objType = ObjType_MapStaticComponent;
	_deadanimation  = tg->_deadanimation;
	_animation = tg->_animation;
	_block = tg->_block;
	_canbeAttack = tg->_canattack;
	if (_currentSprite == NULL)
	{
		_currentSprite =  CCSprite::create();
		addChild(_currentSprite);
	}
	
}

void mapStaticCell::LoadResource(const char* config)
{
	baseMapCell::LoadResource(config);

	_currentPoint = _createPos;
	//_resourseName = config;
	CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(config);
	if (_currentSprite == NULL)
	{
		_currentSprite =  CCSprite::create();
		
		addChild(_currentSprite);
	}
}


void mapStaticCell::onAddToWorld()
{
	baseMapCell::onAddToWorld();
	//_currentSprite->setPosition(_currentPoint);
}


void mapStaticCell::setPosition(float x, float y)
{
	baseMapCell::setPosition(x, y);
	//_currentSprite->setPosition(_currentPoint);
}


void mapStaticCell::actionChange()
{
	if (_currentSprite->isRunning())
	{
		_currentSprite->stopAllActions();
	}
	switch(_enLifeState)
	{
	case ObjLifeState_Alife:
		{
			CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(_animation.c_str());
			_currentSprite->runAction(CCRepeat::create(CCAnimate::create(animation), 50));
			//_currentSprite->setPosition(_currentPoint);
		}
		break;
	case ObjLifeState_Die:
		{
			CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(_deadanimation.c_str());
			_currentSprite->runAction(CCRepeat::create(CCAnimate::create(animation), 50));
			//_currentSprite->setPosition(_currentPoint);
		}
		break;
	case ObjLifeState_Dead:
		{

		}
		break;
	}
}


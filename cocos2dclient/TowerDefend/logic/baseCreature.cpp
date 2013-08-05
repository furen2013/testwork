#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "CreatureStorage.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop),
	_currentAnimate(NULL),_currentSprite(NULL)
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
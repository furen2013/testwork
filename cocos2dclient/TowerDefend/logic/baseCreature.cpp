#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "CreatureStorage.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop),
	_currentAnimate(NULL),_currentSprite(NULL)
{
	for (int i = 0; i < CreatureDir_Max; i ++)
	{
		for (int j = 0; j < CreatureState_Max; j ++)
		{
	
			_actionInterval[i][j] = NULL;
		}
	}

	_currentAnimation = NULL;


}

baseCreature::~baseCreature(void)
{
}

void baseCreature::LoadResource(const char* config)
{
	_currentPoint = _createPos;
	_resourseName = config;
	std::string imgae;
	for (int i = 0; i < CreatureDir_Max; i ++)
	{
		for (int j = 0; j < CreatureState_Max; j ++)
		{
			imgae = _resourseName + "_" + _defaultDirImageKey[i] + "_" + _defaultStateImageKey[j];
			CCAnimation* animation = TDResourceManager::getSingletonPtr()->getAnimation(imgae.c_str());
			_actionInterval[i][j] = CCRepeat::create(CCAnimate::create(animation), 111);
			
		}
	}
	_currentSprite =  CCSprite::create();


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
		onSpriteChange();
	}
}


void baseCreature::onSpriteChange()
{
	if (_actionInterval[_enDir][_enState])
	{
		if (_currentSprite->isRunning())
		{
			_currentSprite->stopAllActions();
		}

		_currentSprite->runAction(_actionInterval[_enDir][_enState]);

	}
}


void baseCreature::setCreatureState(enCreatureActionState en)
{
	if (_enState != en)
	{
		_enState = en;
		onSpriteChange();
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
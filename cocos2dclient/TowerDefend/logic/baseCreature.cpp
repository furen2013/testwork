#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "CreatureStorage.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
<<<<<<< HEAD
	_speed(0.f),_enState(CreatureState_Stop)
=======
	_speed(0.f),_enState(CreatureState_Stop),
	_currentAnimate(NULL)
>>>>>>> rollbackerrors
{
	for (int i = 0; i < CreatureDir_Max; i ++)
	{
		for (int j = 0; j < CreatureState_Max; j ++)
		{
	
			_Animation[i][j] = NULL;
		}
	}

	_currentAnimation = NULL;
}

baseCreature::~baseCreature(void)
{
}

void baseCreature::LoadResource(const char* config)
{
	_resourseName = config;
	std::string imgae;
	for (int i = 0; i < CreatureDir_Max; i ++)
	{
		for (int j = 0; j < CreatureState_Max; j ++)
		{
			imgae = _resourseName + "_" + _defaultDirImageKey[i] + "_" + _defaultStateImageKey[j];
			_Animation[i][j] = TDResourceManager::getSingletonPtr()->getAnimation(imgae.c_str());
		}
	}
}

<<<<<<< HEAD
=======
void baseCreature::onEnter()
{
	onAddToWorld();
	
}

>>>>>>> rollbackerrors

void baseCreature::onRemoveFromWorld()
{
	baseObj::onRemoveFromWorld();
}


void baseCreature::onAddToWorld()
{
	baseObj::onAddToWorld();
<<<<<<< HEAD
=======
	if (!_currentAnimation)
	{
		_currentAnimation = _Animation[_enDir][_enState];
	}
	if (_currentAnimation)
	{
		_currentAnimate = CCAnimate::create(_currentAnimation);
							
		CCActionInterval* p =CCRepeat::create(_currentAnimate, 111);
		
		_currentSprite = CCSprite::create();
		_currentSprite->runAction(p);
		addChild(_currentSprite);
	}
>>>>>>> rollbackerrors

}

void baseCreature::setDir(enCreatureDir en)
{
	_enDir = en;
}


void baseCreature::setCreatureState(enCreatureActionState en)
{
	_enState = en;
}
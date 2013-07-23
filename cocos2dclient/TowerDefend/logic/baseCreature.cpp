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
	_currentPoint = _createPos;
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

	if (!_currentAnimation)
	{
		_currentAnimation = _Animation[_enDir][_enState];
	}
	if (_currentAnimation)
	{
		_currentAnimate = CCAnimate::create(_currentAnimation);

		CCActionInterval* p =CCRepeat::create(_currentAnimate, 111);

		_currentSprite = CCSprite::create();
		addChild(_currentSprite);
		_currentSprite->runAction(p);
		_currentSprite->setPosition(_currentPoint);



	}

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
	_enDir = en;
}


void baseCreature::setCreatureState(enCreatureActionState en)
{
	_enState = en;
}

void baseCreature::setPosition(float x, float y)
{
	baseObj::setPosition(x,y);
	if (_currentSprite)
	{
		_currentSprite->setPosition(_currentPoint);
	}

}
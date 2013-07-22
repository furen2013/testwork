#include "StdAfx.h"
#include "baseCreature.h"
#include "ResourceManager/TDResourceManager.h"
#include "CreatureStorage.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop)
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
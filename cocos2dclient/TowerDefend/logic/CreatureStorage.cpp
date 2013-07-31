#include "StdAfx.h"
#include "CreatureStorage.h"
#include "baseCreature.h"
std::string _defaultStateImageKey[CreatureState_Max];
std::string _defaultDirImageKey[CreatureDir_Max];
initialiseSingleton(CreatureStorage);

CreatureStorage::CreatureStorage(void)
{
	_defaultDirImageKey[CreatureDir_Up] = "up";
	_defaultDirImageKey[CreatureDir_Down] = "down";
	_defaultDirImageKey[CreatureDir_Left] = "left";
	_defaultDirImageKey[CreatureDir_Right] = "right";


	_defaultStateImageKey[CreatureState_Stop] = "stop";
	_defaultStateImageKey[CreatureState_Move] = "walk";
	_defaultStateImageKey[CreatureState_Dead] = "dead";
}


CreatureStorage::~CreatureStorage(void)
{
}



baseCreature* CreatureStorage::CreateCreature(const char* name)
{
	baseCreature* creature = new baseCreature();
	creature->LoadResource(name);
	
	return creature;
}
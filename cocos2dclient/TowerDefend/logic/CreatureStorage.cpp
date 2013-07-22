#include "StdAfx.h"
#include "CreatureStorage.h"
#include "baseCreature.h"
std::string _defaultStateImageKey[CreatureState_Max];
std::string _defaultDirImageKey[CreatureDir_Max];
initialiseSingleton(CreatureStorage);

CreatureStorage::CreatureStorage(void)
{
	_defaultDirImageKey[CreatureDir_Up] = "Up";
	_defaultDirImageKey[CreatureDir_Down] = "Down";
	_defaultDirImageKey[CreatureDir_Left] = "Left";
	_defaultDirImageKey[CreatureDir_Right] = "Right";


	_defaultStateImageKey[CreatureState_Stop] = "Stop";
	_defaultStateImageKey[CreatureState_Move] = "Move";
	_defaultStateImageKey[CreatureState_Dead] = "Dead";
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
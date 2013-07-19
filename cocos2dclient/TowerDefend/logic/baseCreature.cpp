#include "StdAfx.h"
#include "baseCreature.h"


baseCreature::baseCreature(void)
	:_enDir(CreatureDir_Up),_configSpeed(0.f),
	_speed(0.f),_enState(CreatureState_Stop)
{
}

baseCreature::~baseCreature(void)
{
}

void baseCreature::LoadResource()
{

}

void baseCreature::setDir(enCreatureDir en)
{
	_enDir = en;
}


void baseCreature::setCreatureState(enCreatureActionState en)
{
	_enState = en;
}
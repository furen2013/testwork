#include "stdafx.h"
#include "TechSkillStorage.h"
initialiseSingleton(TechSkillStorage);
TechSkillStorage::TechSkillStorage()
{

}

TechSkillStorage::~TechSkillStorage()
{

}

bool TechSkillStorage::Load()
{


	return true;
}

TechSkillInfo* TechSkillStorage::FindSkillInfo(int32 id)
{
	TechSkillInfo* Info = NULL;
	MAPTECHSKILLINFO::iterator it = _mapTechInfo.find(id);
	if (it != _mapTechInfo.end())
	{
		Info = it->second;
	}
	return Info;
}
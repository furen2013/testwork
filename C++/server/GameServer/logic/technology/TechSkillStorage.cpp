#include "stdafx.h"
#include "TechSkillStorage.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
#include "TechSkillInfo.h"
initialiseSingleton(TechSkillStorage);
TechSkillStorage::TechSkillStorage()
{

}

TechSkillStorage::~TechSkillStorage()
{

}

bool TechSkillStorage::Load()
{
	QueryResult* result;
	result = CharacterDatabase.Query("select * from techskillinfo");
	Field * fields = result->Fetch();
	if (result->GetRowCount() > 0)
	{
		do 
		{
			Field * fields = result->Fetch();
			TechSkillInfo* info = new TechSkillInfo();
			info->id = fields[0].GetUInt32();
			info->effect = fields[1].GetUInt32();
			info->parameter = fields[2].GetUInt32();
			info->parameter1 = fields[3].GetUInt32();
			_mapTechInfo.insert(MAPTECHSKILLINFO::value_type(info->id,info));
		} while (result->NextRow());
	}

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
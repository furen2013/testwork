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

bool TechSkillStorage::init()
{
	QueryResult* result = phoneDatabase->Query("select * from %s","techskillinfo");
	int count = 0;
	if (result)
	{

		if (result->GetRowCount() > 0)
		{
			do 
			{
				count ++;
				Field * fields = result->Fetch();
				TechSkillInfo* info = new TechSkillInfo();
				info->id = fields[0].GetUInt32();
				info->effect = fields[1].GetUInt32();
				info->parameter = fields[2].GetUInt32();
				info->parameter1 = fields[3].GetUInt32();
				_mapTechInfo.insert(MAPTECHSKILLINFO::value_type(info->id,info));
			} while (result->NextRow());
		}

		result->Delete();
		MyLog::log->notice("%d techskillinfo be loaded", count);
	}
	else
	{
		MyLog::log->warn("no techskillinfo be loaded");
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
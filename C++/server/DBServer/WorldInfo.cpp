#include "stdafx.h"

initialiseSingleton(WorldInfo);


void WorldInfo::LoadPlayerCreateInfo()
{
	QueryResult *result = WorldDatabase.Query( "SELECT * FROM playercreateinfo" );

	if( !result )
	{
		MyLog::log->error("Query failed: SELECT * FROM playercreateinfo");
		return;
	}

	PlayerCreateInfo *pPlayerCreateInfo;

	do
	{
		Field *fields = result->Fetch();

		pPlayerCreateInfo = new PlayerCreateInfo;

		pPlayerCreateInfo->index = fields[0].GetUInt8();
		pPlayerCreateInfo->race = fields[1].GetUInt8();
		pPlayerCreateInfo->factiontemplate = fields[2].GetUInt32();
		pPlayerCreateInfo->class_ = fields[3].GetUInt8();
		pPlayerCreateInfo->mapId = fields[4].GetUInt32();
		pPlayerCreateInfo->zoneId = fields[5].GetUInt32();
		pPlayerCreateInfo->positionX = fields[6].GetFloat();
		pPlayerCreateInfo->positionY = fields[7].GetFloat();
		pPlayerCreateInfo->positionZ = fields[8].GetFloat();
		pPlayerCreateInfo->displayId = fields[9].GetUInt32();
		pPlayerCreateInfo->strength = fields[10].GetUInt8();
		pPlayerCreateInfo->ability = fields[11].GetUInt8();
		pPlayerCreateInfo->stamina = fields[12].GetUInt8();
		pPlayerCreateInfo->intellect = fields[13].GetUInt8();
		pPlayerCreateInfo->spirit = fields[14].GetUInt8();
		pPlayerCreateInfo->vitality = fields[15].GetUInt8();
		pPlayerCreateInfo->health = fields[16].GetUInt32();
		pPlayerCreateInfo->mana = fields[17].GetUInt32();
		pPlayerCreateInfo->rage = fields[18].GetUInt32();
		pPlayerCreateInfo->focus = fields[19].GetUInt32();
		pPlayerCreateInfo->energy = fields[20].GetUInt32();
		pPlayerCreateInfo->attackpower = fields[21].GetUInt32();
		pPlayerCreateInfo->mindmg = fields[22].GetFloat();
		pPlayerCreateInfo->maxdmg = fields[23].GetFloat();

		QueryResult *sk_sql = WorldDatabase.Query(
			"SELECT * FROM playercreateinfo_skills WHERE indexid=%u",pPlayerCreateInfo->index);

		if(sk_sql)
		{
			do 
			{
				Field *fields = sk_sql->Fetch();
				CreateInfo_SkillStruct tsk;
				tsk.skillid = fields[1].GetUInt32();
				tsk.currentval = fields[2].GetUInt32();
				tsk.maxval = fields[3].GetUInt32();
				pPlayerCreateInfo->skills.push_back(tsk);
			} while(sk_sql->NextRow());
			delete sk_sql;
		}
		QueryResult *sp_sql = WorldDatabase.Query(
			"SELECT * FROM playercreateinfo_spells WHERE indexid=%u",pPlayerCreateInfo->index);

		if(sp_sql)
		{
			do 
			{
				pPlayerCreateInfo->spell_list.insert(sp_sql->Fetch()[1].GetUInt32());
			} while(sp_sql->NextRow());
			delete sp_sql;
		}

		QueryResult *items_sql = WorldDatabase.Query(
			"SELECT * FROM playercreateinfo_items WHERE indexid=%u",pPlayerCreateInfo->index);

		if(items_sql)
		{
			do 
			{
				Field *fields = items_sql->Fetch();
				CreateInfo_ItemStruct itm;
				itm.protoid = fields[1].GetUInt32();
				itm.slot = fields[2].GetUInt8();
				itm.amount = fields[3].GetUInt32();
				pPlayerCreateInfo->items.push_back(itm);
			} while(items_sql->NextRow());
			delete items_sql;
		}

		QueryResult *bars_sql = WorldDatabase.Query(
			"SELECT * FROM playercreateinfo_bars WHERE class=%u and race=%u",pPlayerCreateInfo->class_, pPlayerCreateInfo->race );

		if(bars_sql)
		{
			do 
			{
				Field *fields = bars_sql->Fetch();
				CreateInfo_ActionBarStruct bar;
				bar.button = fields[2].GetUInt32();
				bar.action = fields[3].GetUInt32();
				bar.type = fields[4].GetUInt32();
				bar.misc = fields[5].GetUInt32();
				pPlayerCreateInfo->actionbars.push_back(bar);
			} while(bars_sql->NextRow());			
			delete bars_sql;
		}

		mPlayerCreateInfo[pPlayerCreateInfo->index] = pPlayerCreateInfo;
	} while( result->NextRow() );

	delete result;

	MyLog::log->notice("WorldInfo : %u player create infos loaded.", mPlayerCreateInfo.size());
}

PlayerCreateInfo* WorldInfo::GetPlayerCreateInfo(uint8 race, uint8 class_) const
{
	PlayerCreateInfoMap::const_iterator itr;
	for (itr = mPlayerCreateInfo.begin(); itr != mPlayerCreateInfo.end(); itr++)
	{
		if( (itr->second->race == race) && (itr->second->class_ == class_) )
			return itr->second;
	}
	return NULL;
}
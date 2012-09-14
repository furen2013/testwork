#include "stdafx.h"
#include "DataInterface.h"
#include "crc32.h"
ui64	MySqlAccess::m_hiPlayerGuid;

HM_NAMESPACE::hash_set<int> MySqlAccess::m_hashname;
bool MySqlAccess::Init()
{
	smart_ptr<QueryResult> result = CharacterDatabase.Query( "SELECT MAX(guid) FROM characters" );
	if( result )
	{
		m_hiPlayerGuid = result->Fetch()[0].GetUInt32();
		LoadAllName();
		return true;
	}

	return false;
}

bool MySqlAccess::LoadRole(ui64 guid, RoleInfo& info)
{
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT guid, level, race, class, gender, name, positionX, positionY, positionZ, mapId, banned, restState, deathstate FROM characters WHERE guid=%u and del <> 1", guid);

	if( result )
	{
		return false;
	}

	Field *fields = result->Fetch();
	info.guid	= fields[0].GetUInt64();
	info.nLevel	= fields[1].GetInt32();
	info.nRace	= fields[2].GetUInt8();
	info.nClass = fields[3].GetUInt8();
	info.nGender = fields[4].GetUInt8();
	info.name	= fields[5].GetString();
	info.nMapID	= fields[9].GetUInt32();
	info.nGS	= CConfig::m_nGSID;

	PlayerCreateInfo *create_info = sWorldInfo.GetPlayerCreateInfo(info.nRace, info.nClass);
	if(!create_info)
	{
		// info not found... disconnect
		MyLog::log->alert("player[%u] tried to load invalid player with race %u and class %u", guid, info.nRace, info.nClass);
		return NULL;
	}
	info.displayid = info.nGender == GENDER_MALE ? create_info->displayId : create_info->displayId + 100000000;

	return LoadRoleEquip(guid, info);
}

bool MySqlAccess::CreateRole(ui32 nAccountID, const string& strName, ui8 nGender, ui8 nClass, ui8 nRace, RoleInfo& roleinfo)
{
	PlayerCreateInfo *info = sWorldInfo.GetPlayerCreateInfo(nRace, nClass);
	if(!info)
	{
		// info not found... disconnect
		MyLog::log->error("account[%d] tried to create invalid player with race %u and class %u", nAccountID, nRace, nClass);
		return false;
	}

	roleinfo.name = strName;
	roleinfo.guid = ++m_hiPlayerGuid;
	roleinfo.nClass = nClass;
	roleinfo.nRace = nRace;
	roleinfo.nGender = nGender;
	roleinfo.nGS = CConfig::m_nGSID;
	roleinfo.nLevel = 1;
	roleinfo.nMapID = info->mapId;
	roleinfo.displayid = roleinfo.nGender == GENDER_MALE ? info->displayId : info->displayId + 100000000;
	string Name = CharacterDatabase.EscapeString(strName);
	std::stringstream ss;
	ss << "REPLACE INTO characters VALUES ("
		<< m_hiPlayerGuid << ", "
		<< nAccountID << ","
		<< "'" << Name << "', "
		<< (ui32)nRace << ","
		<< (ui32)nClass << ","
		<< (ui32)nGender << ",";
	if(info->factiontemplate != info->factiontemplate)
		ss << info->factiontemplate << ",";
	else
		ss << "0,";
	ss << (ui32)1 << ","
		<< 0/*xp*/ << ","

		// dump exploration data
		<< "'";
	ss << "0,";
	ss << "','";

	for(std::list<CreateInfo_SkillStruct>::iterator itr = info->skills.begin(); itr != info->skills.end(); ++itr)
	{
		if(itr->skillid)
		{
			ss << (ui32)itr->skillid << ";"
				<< (ui32)itr->currentval << ";"
				<< (ui32)itr->maxval << ";";
		}
	}
	ss << "', "

		<< 0xEEEEEEEE << ","
		<< 0 << ","
		<< 0 << ","
		<< 250 << ","
		<< 0 << ","
		<< 0 << ",";

	ss << 0 << ","
		<< info->health << ","
		<< info->mana << ","
		<< 1<< ","
		<< 0 << ","
		<< 0 << ","
		<< 0 << ","
		<< 0 << ",";

	// save the normal position
	ss << info->positionX << ", "
		<< info->positionY << ", "
		<< info->positionZ << ", "
		<< 0.0f << ", "
		<< info->mapId << ", ";

	ss << info->zoneId << ", '";

	for(uint32 i = 0; i < 8; i++ )
		ss << 0 << " ";
	ss << "', "

		<< 0 << ", '"
		<< "" << "', "
		<< (uint32)UNIXTIME << ",";

	//online state
	ss << "0,";

	ss << info->positionX	<< ", "
		<< info->positionY	<< ", "
		<< info->positionZ	<< ", "
		<< info->mapId		<< ", "
		<< info->zoneId		<< ", "

		//rest
		<< 0	  << ", "		//isResting
		<< 0	  << ", "		//	restState
		<< 0	 << ", '"		//	restTime

		<< 0  << " "			//playedtime
		<< 0  << " "			//playedtime
		<< 0  << " ', "			//playedtime
		<< 0  << ", "			//deathstate

		<< 0	   << ", "	//TalentResetTimes
		<< 1			 << ", "//FirstLogin
		<< 0<< "," //rename_pending
		<< 0 << ","//arenaPoints
		<< 2 << ",";//totalstableslots

	// instances
	{
		ss << 0		   << ", ";
	}

	ss << /*m_bgEntryPointMap*/0	  << ", "
		<< /*m_bgEntryPointX*/0		<< ", "
		<< /*m_bgEntryPointY*/0		<< ", "
		<< /*m_bgEntryPointZ*/0		<< ", "
		<< /*m_bgEntryPointO*/0		<< ", "
		<< /*m_bgEntryPointInstance*/0 << ", ";

	// taxi
	ss << "0, 0, 0";

	ss << "," << /*m_CurrentTransporter*/ (uint32)0;
	ss << ",'" << 0 << "','" << 0 << "','" << 0 << "'";
	ss << ",'";

	// Dump spell data to stringstream
	std::set<uint32>::iterator spellItr = info->spell_list.begin();
	for(; spellItr != info->spell_list.end(); ++spellItr)
	{
		ss << uint32(*spellItr) << ",";
	}
	ss << "','";
	// Dump deleted spell data to stringstream
	// 	spellItr = mDeletedSpells.begin();
	// 	for(; spellItr != mDeletedSpells.end(); ++spellItr)
	// 	{
	// 		ss << uint32(*spellItr) << ",";
	// 	}
	ss << "";
	ss << "','";
	// Dump reputation data
	// 	ReputationMap::iterator iter = m_reputation.begin();
	// 	for(; iter != m_reputation.end(); ++iter)
	// 	{
	// 		ss << int32(iter->first) << "," << int32(iter->second->flag) << "," << int32(iter->second->baseStanding) << "," << int32(iter->second->standing) << ",";
	// 	}
	ss << "";
	ss << "','";

	// Add player action bars
	info->actionbars;
	for(uint32 i = 0; i < 120; ++i)
	{
		bool bHasAction = false;
		for(std::list<CreateInfo_ActionBarStruct>::iterator itr = info->actionbars.begin(); itr != info->actionbars.end() ; itr++)
		{
			if( i == itr->button )
			{
				bHasAction = true;
				ss << uint32(itr->action) << ","
					<< uint32(itr->misc) << ","
					<< uint32(itr->type) << ",";
			}
		}
		if( !bHasAction )
		{
			ss << 0 << ","
				<< 0 << ","
				<< 0 << ",";
		}
	}
	ss << "','";
	//	ss << LoadAuras;
	ss << "";
	ss << "','";

	// Add player finished quests
	{
		ss << 0 << ",";
	}

	ss << "', ";
	ss << /*m_honorRolloverTime*/0 << ", ";
	ss << /*m_killsToday*/0 << ", " << /*m_killsYesterday*/0 << ", " << /*m_killsLifetime*/0 << ", ";
	ss << /*m_honorToday*/0 << ", " << /*m_honorYesterday*/0 << ", ";
	ss << /*m_honorPoints*/0 << ", ";
	ss << /*iInstanceType*/0 << ", 0, 0, 0, 0, 0,";
	std::transform( Name.begin(), Name.end(), Name.begin(), ::toupper );
	ss << crc32((const unsigned char*)Name.c_str(),Name.length()) << ",0,'','')";

	bool bSuc = CharacterDatabase.WaitExecute(ss.str().c_str());
	if(!bSuc)
	{
		MyLog::log->error("sql excute error while Acct[%u] creating role[%s]!", nAccountID, Name.c_str());
		return false;
	}

	for(std::list<CreateInfo_ItemStruct>::iterator itr = info->items.begin(); itr != info->items.end(); ++itr)
	{
		CreateInfo_ItemStruct& item = *itr;
		if( item.slot >= EQUIPMENT_SLOT_START && item.slot < EQUIPMENT_SLOT_END )
		{
			roleinfo.equipdisplay[item.slot]	= item.protoid;
		}
	}

	m_hashname.insert(crc32((const unsigned char*)Name.c_str(),Name.length()));
	return true;
}

bool MySqlAccess::LoadAllName()
{
	///MyLog::log->info("读取所有名字信息");
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT name FROM characters"/*WHERE del <> 1*/);
	if(!result)
		return true;
	for (ui32 i=0; i < result->GetRowCount(); i++)
	{
		RoleInfo info;
		Field *fields = result->Fetch();
		string name	= fields[0].GetString();

		std::transform( name.begin(), name.end(), name.begin(), ::toupper );
		m_hashname.insert(crc32((const unsigned char*)name.c_str(),name.length()));
		result->NextRow();
	}
	MyLog::log->info("读取所有名字信息--------ok");
	return true;
}

bool MySqlAccess::LoadAcctRoles(ui32 nAccountID, vector<RoleInfo>& vInfos)
{
	vInfos.clear();
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT guid, level, race, class, gender, name, positionX, positionY, positionZ, mapId, banned, restState, deathstate, first_login FROM characters WHERE acct =%u and del <> 1", nAccountID);
	if(!result)
		return true;
	for (ui32 i=0; i < result->GetRowCount(); i++)
	{
		RoleInfo info;
		Field *fields = result->Fetch();
		info.guid	= fields[0].GetUInt64();
		info.nLevel	= fields[1].GetInt32();
		info.nRace	= fields[2].GetUInt8();
		info.nClass = fields[3].GetUInt8();
		info.nGender = fields[4].GetUInt8();
		info.name	= fields[5].GetString();
		info.nMapID	= fields[9].GetUInt32();
		info.bFirstLogin = fields[13].GetUInt8();
		info.nGS	= CConfig::m_nGSID;

		PlayerCreateInfo *create_info = sWorldInfo.GetPlayerCreateInfo(info.nRace, info.nClass);
		if(!create_info)
		{
			// info not found... disconnect
			MyLog::log->error("account[%d] tried to load invalid player with race %u and class %u", nAccountID, info.nRace, info.nClass);
			return NULL;
		}
		info.displayid = info.nGender == GENDER_MALE ? create_info->displayId : create_info->displayId + 100000000;

		if(info.bFirstLogin)
		{
			for(std::list<CreateInfo_ItemStruct>::iterator itr = create_info->items.begin(); itr != create_info->items.end(); ++itr)
			{
				CreateInfo_ItemStruct& item = *itr;
				if( item.slot >= EQUIPMENT_SLOT_START && item.slot < EQUIPMENT_SLOT_END )
				{
					info.equipdisplay[item.slot]	= item.protoid;
				}
			}
		}

		vInfos.push_back(info);
		string tempname = info.name;
		std::transform( tempname.begin(), tempname.end(), tempname.begin(), ::toupper );
		m_hashname.insert(crc32((const unsigned char*)tempname.c_str(),tempname.length()));
		result->NextRow();
	}

	vector<RoleInfo>::iterator itr = vInfos.begin();
	for(; itr != vInfos.end(); ++itr)
	{
		if(!LoadRoleEquip(itr->guid, *itr))
		{
			MyLog::log->error("player[%u] load equip info error", itr->guid);
			return false;
		}
	}
	return true;
}

bool MySqlAccess::LoadRoleEquip(ui64 guid, RoleInfo& info)
{
	if( info.bFirstLogin )
	{
		PlayerCreateInfo *create_info = sWorldInfo.GetPlayerCreateInfo(info.nRace, info.nClass);
		if(!create_info)
		{
			// info not found... disconnect
			MyLog::log->error("role[%u] tried to load invalid player with race %u and class %u while loadequip", guid, info.nRace, info.nClass);
			return false;
		}

		for(std::list<CreateInfo_ItemStruct>::iterator is = create_info->items.begin(); is!=create_info->items.end(); is++)
		{
			if ( (*is).slot >= 0 && (*is).slot <= EQUIPMENT_SLOT_END-EQUIPMENT_SLOT_START && (*is).protoid != 0)
			{
				info.equipdisplay[(*is).slot] = (*is).protoid;
			}
		}
		return true;
	}
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT entry, slot FROM playeritems WHERE ownerguid=%u and containerslot =255 and slot >= 0 and slot < 20", guid);

	if( !result )
	{
		return true;
	}

	for (ui32 i=0; i < result->GetRowCount(); i++)
	{
		Field *fields = result->Fetch();
		info.equipdisplay[fields[1].GetInt32()]	= fields[0].GetInt32();
		result->NextRow();
	}
	return true;
}

bool MySqlAccess::DelRole(ui32 nAccountID, ui64 guid)
{
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT guid, name FROM characters WHERE guid = %u and acct = %u", (uint32)guid, nAccountID);

	if( !result )
	{
		MyLog::log->alert("acct[%d] try to delete a role[%u] who is created by other", nAccountID, (uint32)guid);
		return false;
	}

	if(!result->GetRowCount())
	{
		MyLog::log->alert("acct[%d] try to delete a role[%u] who is created by other", nAccountID, (uint32)guid);
		return false;
	}

	Field *fields = result->Fetch();
	string name = fields[1].GetString();
	std::transform( name.begin(), name.end(), name.begin(), ::toupper );

	//HM_NAMESPACE::hash_set<int>::iterator itr = m_hashname.find(crc32((const unsigned char*)name.c_str(),name.length()));
	//if(itr!=m_hashname.end())
    //    m_hashname.erase(itr);

	CharacterDatabase.Query("update characters set del = 1 WHERE guid = %u and acct = %u", (uint32)guid, nAccountID);
	return true;

	scoped_sql_transaction_proc sstp( &CharacterDatabase );

	CharacterDatabase.TransactionExecute("DELETE FROM characters WHERE guid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM playeritems WHERE ownerguid=%u",(uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM gm_tickets WHERE guid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM playerpets WHERE ownerguid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM playerpetspells WHERE ownerguid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM tutorials WHERE playerId = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM questlog WHERE player_guid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM playercooldowns WHERE player_guid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM mailbox WHERE player_guid = %u", (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM social_friends WHERE character_guid = %u OR friend_guid = %u", (uint32)guid, (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM social_ignores WHERE character_guid = %u OR ignore_guid = %u", (uint32)guid, (uint32)guid);
	CharacterDatabase.TransactionExecute("DELETE FROM tutorials WHERE playerid = %u", (uint32)guid );
	CharacterDatabase.TransactionExecute("DELETE FROM refine_item_container WHERE guid = %u", (uint32)guid );
	sstp.success();
	return true;
}

//¼ì²é½ÇÉ«ÃûÔÚ±¾×éÄÚÊÇ·ñÊµÓÃ¹ý
//return 0Î´Ê¹ÓÃ¹ý£¬1Ê¹ÓÃ¹ý£¬2·þÎñÆ÷Òì³£,
int MySqlAccess::IsRoleNameUsed(const string& strRoleName)
{
	std::string name = CharacterDatabase.EscapeString(strRoleName).c_str();
	/*
#ifdef _WIN32
#else
	size_t from,to;
    char szASCII[128] = {0};
    char szUTF8[128] = {0};
    char** pszASCII = (char**)&szASCII;
    char** pszUTF8 = (char**)&szUTF8;
    sprintf(szASCII, name.c_str());
    iconv_t t = iconv_open("utf8", "ascii");
    iconv(t, pszASCII, &from, pszUTF8, &to);
    iconv_close(t);
    name = szUTF8;
#endif
*/
	//smart_ptr<QueryResult> resultř = CharacterDatabase.Query("SELECT COUNT(*) FROM characters WHERE name = '%s'", CharacterDatabase.EscapeString(strRoleName).c_str());
	//smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT COUNT(*) FROM characters WHERE name='%s'", name.c_str());
//	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT COUNT(*) FROM characters WHERE STRCMP(LOWER(CONVERT(name USING gbk)), LOWER(CONVERT(\'%s\' USING gbk))) = 0", name.c_str());
//
	//smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT COUNT(*) FROM characters WHERE LOWER(CONVERT(name USING gbk)) = LOWER(CONVERT('%s' USING utf8))", name.c_str());
	std::transform( name.begin(), name.end(), name.begin(), ::toupper );
// 	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT COUNT(*) FROM characters WHERE namecrc=%d", crc32((const unsigned char*)name.c_str(), name.length()));
// 	if(result)
// 	{
// 		if(result->Fetch()[0].GetUInt32() > 0)
// 		{
// 			// That name is banned!
// 			return 1;
// 		}
// 	}
	if(m_hashname.find(crc32((const unsigned char*)name.c_str(),name.length())) != m_hashname.end())
		return 1;
	return 0;
}

bool MySqlAccess::CanUseName(const string& strName)
{
	if( !is_valid_string( strName ) )
		return false;
	smart_ptr<QueryResult> result = CharacterDatabase.Query("SELECT COUNT(*) FROM banned_names WHERE name = '%s'", CharacterDatabase.EscapeString(strName).c_str());
	if(result)
	{
		if(result->Fetch()[0].GetUInt32() > 0)
		{
			// That name is banned!
			MyLog::log->error("CRoleDataManager::CreateRole name[%s] is banned!!!", strName.c_str());
			return false;
		}
		return true;
	}
	return true;
}

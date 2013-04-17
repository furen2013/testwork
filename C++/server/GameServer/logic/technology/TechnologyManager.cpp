#include "stdafx.h"
#include "TechnologyManager.h"
#include "Technology.h"
#include "share/Database/Database.h"
#include "share/Database/DatabaseEnv.h"
#include "boost/lexical_cast.hpp"
initialiseSingleton(TechnologyManager);
bool techconf::LoadFromStr(string str)
{
	vector<string> strs = StrSplit(str,";");
	vector<string>::iterator it = strs.begin();
	for (; it != strs.end(); ++ it)
	{
		vector<string> reqstrs = StrSplit(*it, ":");
		reqtech* req = new reqtech();
		req->id = boost::lexical_cast<int>(reqstrs[0]);
		req->reqcount = boost::lexical_cast<int>(reqstrs[1]);
		
	}
	return true;
}
TechnologyManager::TechnologyManager()
{

}
TechnologyManager::~TechnologyManager()
{

}

bool TechnologyManager::Load()
{

	QueryResult * result;
	result = CharacterDatabase.Query("SELECT * FROM %s", "Technology");
	if (!result)
		return false;
	Field * fields = result->Fetch();
	if (result->GetRowCount() > 0)
	{
		do 
		{
			Technology* technology = new Technology();
			technology->LoadFromStr(fields[1].GetString());
			technology->setAccount(fields[0].GetUInt64());
			_technologys.insert(maptechnology::value_type(technology->getAccount(), technology));

		} while (result->NextRow());
	}

	result = CharacterDatabase.Query("SELECT * FROM %s","techconf");
	fields = result->Fetch();
	if (result->GetRowCount() > 0)
	{
		do 
		{
			techLevelconf* conf = NULL;
			int level = fields[2].GetInt32();
			maptechLevelconf::iterator it = _techLevelconfs.find(level);
			if (it == _techLevelconfs.end())
			{
				conf = new techLevelconf();
				conf->level = level;
				_techLevelconfs.insert(maptechLevelconf::value_type(conf->level, conf));
			}
			else
			{
				conf = it->second;
			}

			int id = fields[0].GetInt32();

			techLevelconf::maptechinfo::iterator itinfo = conf->techinfos.find(id);
			if (itinfo == conf->techinfos.end())
			{
				techconf* info = new techconf();
				info->id = id;
				info->maxCount = fields[1].GetInt32();
				info->LoadFromStr(fields[3].GetString());
				conf->techinfos.insert(techLevelconf::maptechinfo::value_type(info->id, info));
			}

		} while (result->NextRow());
	}
	return true;
}


Technology* TechnologyManager::GetTech(DWORD account)
{
	Technology* p = NULL;
	maptechnology::iterator it = _technologys.find(account);
	if (it != _technologys.end())
	{
		p = it->second;
	}
	else
	{
		p = new Technology();
		p->setAccount(account);
		_technologys.insert(maptechnology::value_type(account, p));
	}
	return p;
}
enTechResult TechnologyManager::OpenTechLevel(DWORD account, int level)
{
	enTechResult en = TechResult_OK;
	//const techLevelconf* pconf = FindTechConfLevel(level);
	//if (pconf == NULL)
	//{
	//	en = TechResult_NotHaveTechLevel;
	//}
	//else
	//{
	//	maptechnology::iterator ittechnology = _technologys.find(account);
	//	if (ittechnology == _technologys.end())
	//	{
	//		en =  TechResult_NotFoundUser;
	//	}
	//	else
	//	{
	//		Technology* pTechnology = ittechnology->second;
	//		if (!pTechnology->openTechLevel(level))
	//		{
	//			en = TechResult_AlreadyOpenTechLevel;
	//		}
	//		
	//	}
	//}
	return en;
}

const techLevelconf* TechnologyManager::FindTechConfLevel(int level)
{
	maptechLevelconf::iterator it = _techLevelconfs.find(level);
	if (it == _techLevelconfs.end())
	{
		return NULL;
	}
	return it->second;
}
enTechResult TechnologyManager::AddTechCount(DWORD account, int level, int id, int count /* = 1 */)
{
	enTechResult en = TechResult_OK;
	//const techLevelconf* pconf = TechnologyManager::gFindTechConfLevel(level);
	//
	//if (pconf == NULL)
	//{
	//	en = TechResult_NotHaveTechLevel;
	//}
	//else
	//{
	//	techLevelconf::maptechinfo::const_iterator itconf = pconf->techinfos.find(id);
	//	if (itconf == pconf->techinfos.end())
	//	{
	//		en = TechResult_NotHaveTech;
	//	}
	//	else
	//	{
	//		techconf* ptechconf = itconf->second;
	//		maptechnology::iterator ittechnology = _technologys.find(account);
	//		if (ittechnology == _technologys.end())
	//		{
	//			en =  TechResult_NotFoundUser;
	//		}
	//		else
	//		{
	//			Technology* p = ittechnology->second;
	//			en = p->addTech(level, id,count, ptechconf);;
	//		}
	//	}
	//}

	return en;
}

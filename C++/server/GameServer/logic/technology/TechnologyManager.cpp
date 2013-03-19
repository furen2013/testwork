#include "stdafx.h"
#include "TechnologyManager.h"
#include "Technology.h"

TechnologyManager::TechnologyManager()
{

}
TechnologyManager::~TechnologyManager()
{

}

bool TechnologyManager::Load()
{
	return true;
}

enTechResult TechnologyManager::OpenTechLevel(DWORD account, int level)
{
	enTechResult en = TechResult_OK;
	const techLevelconf* pconf = FindTechConfLevel(level);
	if (pconf == NULL)
	{
		en = TechResult_NotHaveTechLevel;
	}
	else
	{
		maptechnology::iterator ittechnology = technologys.find(account);
		if (ittechnology == technologys.end())
		{
			en =  TechResult_NotFoundUser;
		}
		else
		{
			Technology* pTechnology = ittechnology->second;
			if (!pTechnology->openTechLevel(level))
			{
				en = TechResult_AlreadyOpenTechLevel;
			}
			
		}
	}
	return en;
}

const techLevelconf* TechnologyManager::FindTechConfLevel(int level)
{
	maptechLevelconf::iterator it = techLevelconfs.find(level);
	if (it == techLevelconfs.end())
	{
		return NULL;
	}
	return it->second;
}
enTechResult TechnologyManager::AddTechCount(DWORD account, int level, int id, int count /* = 1 */)
{
	enTechResult en = TechResult_OK;
	const techLevelconf* pconf = FindTechConfLevel(level);
	
	if (pconf == NULL)
	{
		en = TechResult_NotHaveTechLevel;
	}
	else
	{
		techLevelconf::maptechinfo::const_iterator itconf = pconf->techinfos.find(id);
		if (itconf == pconf->techinfos.end())
		{
			en = TechResult_NotHaveTech;
		}
		else
		{
			techconf* ptechconf = itconf->second;
			maptechnology::iterator ittechnology = technologys.find(account);
			if (ittechnology == technologys.end())
			{
				en =  TechResult_NotFoundUser;
			}
			else
			{
				Technology* p = ittechnology->second;
				en = p->addTech(level, id,count, ptechconf);;
			}
		}
	}

	return en;
}

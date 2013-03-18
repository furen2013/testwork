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

TechnologyManager::enAddTechResult TechnologyManager::IsCanAddTechCount(DWORD account, int level, int id, int count /* = 1 */)
{
	enAddTechResult en = AddTechResult_OK;
	maptechLevelconf::iterator it = techLevelconfs.find(level);
	if (it == techLevelconfs.end())
	{
		en = AddTechResult_NotHaveTechLevel;
	}
	else
	{
		techLevelconf* pconf =  it->second;
		techLevelconf::maptechinfo::iterator itconf = pconf->techinfos.find(id);
		if (itconf == pconf->techinfos.end())
		{
			en = AddTechResult_NotHaveTech;
		}
		else
		{
			techconf* ptechconf = itconf->second;
			maptechnology::iterator ittechnology = technologys.find(account);
			if (ittechnology == technologys.end())
			{
				en =  AddTechResult_NotFoundUser;
			}
			else
			{
				Technology* pTechnology = ittechnology->second;
				if (pTechnology->GetTechValue() < count)
				{

				}
				else
				{
					techconf::vcreqtechs::iterator ittechs = ptechconf->reqtechs.begin();
					for (; ittechs != ptechconf->reqtechs.end(); ++ ittechs)
					{

						reqtech* preqtech = (*ittechs);
						if (pTechnology->GetTechCount(level, preqtech->id) < preqtech->reqcount)
						{
							en = AddTechResult_NotHaveReqTech;
							break;
						}
					}
				}

				
			}
		}
	}

	return en;
}

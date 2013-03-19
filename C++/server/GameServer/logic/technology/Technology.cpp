#include "stdafx.h"
#include "Technology.h"
#include "TechnologyManager.h"
Technology::Technology()
{
	techvalue = 0;
}

Technology::~Technology()
{

}

bool Technology::openTechLevel(int level)
{
	bool b = true;
	maptechlevel::iterator it = techlevels.find(level);
	if (it == techlevels.end())
	{
		b = false;
	}
	else
	{
		TechLevel* p = new TechLevel();
		p->level = level;
		techlevels.insert(maptechlevel::value_type(level,p));
		b = true;
	}
	return b;
}

bool Technology::IsHaveTechLevel(int level)
{
	maptechlevel::iterator it = techlevels.find(level);
	if (it != techlevels.end())
	{
		return true;
	}
	return false;
}

int Technology::GetTechCount(int level,int id)
{
	int nCount = 0;
	maptechlevel::iterator it = techlevels.find(level);
	if (it != techlevels.end())
	{
		TechLevel* p = it->second;
		TechLevel::maptechinfo::iterator it  = p->TechInfos.find(id);
		nCount = it->second->currentCount;
	}
	
	return nCount;
}

int Technology::GetTechValue()
{
	return techvalue;
}

bool Technology::addTechValue(int nValue)
{
	techvalue = nValue;
	return true;
}

enTechResult Technology::addTech(int level, int id, int ncount,  const techconf* pconf )
{
	enTechResult en = TechResult_OK;
	maptechlevel::iterator it = techlevels.find(level);
	if (it == techlevels.end())
	{
		en = TechResult_NotHaveTechLevel;
	}
	else
	{
		TechLevel* pTechLevel = it->second;
		if (techvalue < ncount)
		{
			en = TechResult_NotHaveOwnerTechValue;
		}
		else
		{
			techconf::vcreqtechs::const_iterator ittechs = pconf->reqtechs.begin();
			for (; ittechs != pconf->reqtechs.end(); ++ ittechs)
			{
				reqtech* preqtech = (*ittechs);
				TechLevel::maptechinfo::iterator itInfos= pTechLevel->TechInfos.find(preqtech->id);
				if (itInfos == pTechLevel->TechInfos.end())
				{
					en = TechResult_NotHaveReqTech;
					break;
				}
				else
				{
					TechInfo* pcurrentinfo = itInfos->second;
					if (pcurrentinfo->currentCount < preqtech->reqcount)
					{
						en = TechResult_NotHaveReqTech;
						break;
					}
				}
			}

			if (en == TechResult_OK)
			{
				TechInfo* info = NULL;
				TechLevel::maptechinfo::iterator itinfo = pTechLevel->TechInfos.find(id);
				if (itinfo == pTechLevel->TechInfos.end())
				{
					info = new TechInfo;
					info->id = id;
					pTechLevel->TechInfos.insert(TechLevel::maptechinfo::value_type(id, info));
				}
				else
				{
					info = itinfo->second;
				}
				info->currentCount += ncount;
				techvalue -= ncount;
			}
		}
	}

	return en;
}
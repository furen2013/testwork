#include "stdafx.h"
#include "Technology.h"
#include "TechnologyManager.h"
#include "Util.h"
#include "boost/lexical_cast.hpp"

Technology::Technology()
{
	_techvalue = 0;
}

Technology::~Technology()
{

}
string Technology::toString()
{
	string temp;
	maptechlevel::iterator it = _techlevels.begin();
	for (int i = 0; it != _techlevels.end();  ++ it, i ++)
	{
		if (i != 0)
		{
			temp += ";";
		}
		TechLevel* plevel = it->second;
		temp += boost::lexical_cast<string>(plevel->level);
		TechLevel::maptechinfo::iterator itInfo = plevel->TechInfos.begin();
		temp += "*";
		for (int n = 0; itInfo != plevel->TechInfos.end(); ++ itInfo, n ++)
		{
			if (n != 0)
			{
				temp += ",";
			}
			TechInfo* p = itInfo->second;
			temp += boost::lexical_cast<string>(p->id);
			temp += ":";
			temp += boost::lexical_cast<string>(p->currentCount);

		}

	}

	return temp;
}
bool Technology::LoadFromStr(string str)
{
	vector<string> techlevels = StrSplit(str,";");
	vector<string>::iterator it = techlevels.begin();
	for (; it != techlevels.end(); ++ it)
	{
		TechLevel* techlevel = new TechLevel();
		string level = (*it);
		vector<string> tech = StrSplit(level,"*");
		techlevel->level = boost::lexical_cast<int>(tech[0]);

		vector<string> infos = StrSplit(tech[2], ",");
		vector<string>::iterator infoit = infos.begin();
		for (; infoit != infos.end(); ++ infoit)
		{
			TechInfo* info = new TechInfo();
			vector<string> temps = StrSplit(*it,":");
			info->id = boost::lexical_cast<int>(temps[0]);
			info->currentCount = boost::lexical_cast<int>(temps[1]);
			techlevel->TechInfos.insert(TechLevel::maptechinfo::value_type(info->id, info));
		}

		_techlevels.insert(maptechlevel::value_type(techlevel->level,techlevel));
	}

	return true;
}

bool Technology::openTechLevel(int level)
{
	bool b = true;
	maptechlevel::iterator it = _techlevels.find(level);
	if (it == _techlevels.end())
	{
		b = false;
	}
	else
	{
		TechLevel* p = new TechLevel();
		p->level = level;
		_techlevels.insert(maptechlevel::value_type(level,p));
		b = true;
	}
	return b;
}

bool Technology::IsHaveTechLevel(int level)
{
	maptechlevel::iterator it = _techlevels.find(level);
	if (it != _techlevels.end())
	{
		return true;
	}
	return false;
}

int Technology::GetTechCount(int level,int id)
{
	int nCount = 0;
	maptechlevel::iterator it = _techlevels.find(level);
	if (it != _techlevels.end())
	{
		TechLevel* p = it->second;
		TechLevel::maptechinfo::iterator it  = p->TechInfos.find(id);
		nCount = it->second->currentCount;
	}
	
	return nCount;
}

int Technology::GetTechValue()
{
	return _techvalue;
}

bool Technology::addTechValue(int nValue)
{
	_techvalue = nValue;
	return true;
}

enTechResult Technology::addTech(int level, int id, int ncount,  const techconf* pconf )
{
	enTechResult en = TechResult_OK;
	maptechlevel::iterator it = _techlevels.find(level);
	if (it == _techlevels.end())
	{
		en = TechResult_NotHaveTechLevel;
	}
	else
	{
		TechLevel* pTechLevel = it->second;
		if (_techvalue < ncount)
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
				_techvalue -= ncount;
			}
		}
	}

	return en;
}
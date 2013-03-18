#include "stdafx.h"
#include "Technology.h"
Technology::Technology()
{
	techvalue = 0;
}

Technology::~Technology()
{

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
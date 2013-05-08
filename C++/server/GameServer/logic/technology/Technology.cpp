#include "stdafx.h"
#include "Technology.h"
#include "TechnologyManager.h"
#include "MessageTechnologyG2C.pb.h"
#include "../Player.h"
#include "Util.h"
#include "boost/lexical_cast.hpp"
#include "TechSkillStorage.h"
#include "TechSkill.h"

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
void Technology::addTechValue(int Techvalue)
{	
	if (_player)
	{
		_addTechValue(Techvalue);
		MsgAddTechValueACK ACK;
		ACK.set_en(Technology_OK);
		ACK.set_currentvalue(_techvalue);
		_player->sendMessage(&ACK, GS2C_MsgAddTechValueACK);
	}
	
	
	
}
void Technology::openTechLevel(int level)
{
	if (_player)
	{

		MsgOpenTechLevelACK ACK;
		const techLevelconf* pconf = TechnologyManager::getSingleton().FindTechConfLevel(level);
		ACK.set_level(level);
		if (pconf == NULL)
		{
			ACK.set_en(Technology_ErrorNotFindLevel);
			ACK.set_level(level);
		}
		else
		{

			if (_openTechLevel(level))
			{
				ACK.set_en(Technology_OK);
			}
			else
			{
				ACK.set_en(Technology_ErrorAlreadyHaveLevel);
			}
		}
		_player->sendMessage(&ACK, GS2C_MsgOpenTechLevelACK);
	}
	
}
void Technology::addTech(int level, int id, int count)
{
	MsgApplyAddTechInfoACK ack;
	ack.set_level(level);
	ack.set_id(id);
	ack.set_en(Technology_OK);
	const techLevelconf* pconf = TechnologyManager::getSingleton().FindTechConfLevel(level);
	if (pconf == NULL)
	{
		ack.set_en(Technology_ErrorNotFindLevel);
	}
	else
	{

		techLevelconf::maptechinfo::const_iterator itconf = pconf->techinfos.find(id);
		if (itconf == pconf->techinfos.end())
		{
			ack.set_en(Technology_ErrorNotHaveTech);
		}
		else
		{
			_addTech(level, id, count, itconf->second);
		}
	}

	if (ack.en() != Technology_OK)
	{
		_player->sendMessage(&ack, GS2C_MsgApplyAddTechInfoACK);
	}
	
}
bool Technology::_openTechLevel(int level)
{
	bool b = true;
	maptechlevel::iterator it = _techlevels.find(level);
	if (it != _techlevels.end())
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

bool Technology::_addTechValue(int nValue)
{
	_techvalue = nValue;
	return true;
}



void Technology::_addTech(int level, int id, int ncount,  const techconf* pconf )
{
	if (_player)
	{
		MsgApplyAddTechInfoACK ACK;
		ACK.set_level( level);
		ACK.set_id(id);
		ACK.set_en(Technology_OK);
		maptechlevel::iterator it = _techlevels.find(level);
		if (it == _techlevels.end())
		{
			ACK.set_en(Technology_ErrorNotFindLevel);
		}
		else
		{
			TechLevel* pTechLevel = it->second;
			if (_techvalue < ncount)
			{		
				ACK.set_en(Technology_ErrorNotEnoughValueAddTech);
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
						ACK.set_en(Technology_ErrorNotHaveReqTech);
						break;
					}
					else
					{
						TechInfo* pcurrentinfo = itInfos->second;
						if (pcurrentinfo->currentCount < preqtech->reqcount)
						{
							ACK.set_en(Technology_ErrorNotHaveReqTech);
							break;
						}
					}
				}

				if (ACK.en() == Technology_OK)
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
					int skillid = TechnologyManager::getSingleton().FindTechSkill(info->id, info->currentCount);
					if (skillid != -1)
					{
						TechSkillInfo* info = TechSkillStorage::getSingleton().FindSkillInfo(skillid);
						TechSkill* skill = new TechSkill(info,this);

					}
					
					_techvalue -= ncount;

					ACK.set_current(info->currentCount);
				}
			}
		}
		_player->sendMessage(&ACK, GS2C_MsgApplyAddTechInfoACK);
	}
	

}

void Technology::sendTechnologyState()
{

	if (_player)
	{
		MsgTechnologyStateACK ACK;
		MsgTechnologyInfo* info = ACK.mutable_info();
		maptechlevel::const_iterator it = itTechBegin();
		for (; it != itTechEnd(); ++ it)
		{
			TechLevel* level = it->second;
			MsgTechLevelInfo* levelinfo = info->add_levels();
			levelinfo->set_level(level->level);
			TechLevel::maptechinfo::iterator Infoit = level->TechInfos.begin();
			for (; Infoit != level->TechInfos.end(); ++ Infoit)
			{
				TechInfo* techInfo = Infoit->second;
				MsgTechInfo* Info = levelinfo->add_techs();
				Info->set_id(techInfo->id);
				Info->set_currentcount(techInfo->currentCount);
			}
		}
		_player->sendMessage(&ACK, GS2C_MsgTechnologyStateACK);
	}
	

}

Technology::maptechlevel::const_iterator Technology::itTechBegin()
{
	return _techlevels.begin();
}

Technology::maptechlevel::const_iterator Technology::itTechEnd()
{
	return _techlevels.end();
}



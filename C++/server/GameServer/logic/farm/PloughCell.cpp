#include "stdafx.h"
#include "PloughCell.h"
#include "EventMgr.h"
#include "boost/lexical_cast.hpp"
#include "PloughWaterWay.h"
#include "PloughMill.h"
#include "FarmLogic.h"
#include "../Player.h"
#include "../PlayerResourceManager.h"
#include "FarmComponentStorage.h"

PloughCell::PloughCell()
{
	_waterPercentageMax = 100;
	_waterPercentage = _waterPercentageMax;
	_decreaseWaterPerHour = 1;
	_manurelevel = 0;
	enType =  growstate_null;
	_farm = NULL;
	_mill = NULL;
	_WaterWay = NULL;
	//BecomeSeeding();

}
PloughCell::~PloughCell()
{

}



string PloughCell::ToString()
{
#define MaxNumber  8
	string str[MaxNumber];
	str[0] = boost::lexical_cast<string>((int32)enType);
	str[1] = boost::lexical_cast<string>(_waterPercentageMax);
	str[2] = boost::lexical_cast<string>(_waterPercentage);
	str[3] = boost::lexical_cast<string>(_manurelevel);
	str[4] = boost::lexical_cast<string>(_lastStateTime);
	str[5] = boost::lexical_cast<string>(_decreaseWaterPerHour);
	str[6] = boost::lexical_cast<string>(_ID);
	str[7] = boost::lexical_cast<string>(_seedLevel);
	string Temp;
	for (int i = 0; i < MaxNumber; i ++)
	{
		if (i != 0)
		{
			Temp += ",";
		}
		Temp += str[i];		
	}
	return Temp;
}
bool PloughCell::LoadFromString(string sz)
{
	std::vector<string> tokens = StrSplit(sz,",");
	int strNumber = tokens.size();
	bool b = true;
	if (strNumber == 8)
	{
		
		enType = (growstate)boost::lexical_cast<int32>(tokens[0].c_str());
		_waterPercentageMax = boost::lexical_cast<int32>(tokens[1].c_str());
		_waterPercentage = boost::lexical_cast<int32>(tokens[2].c_str());
		_manurelevel = boost::lexical_cast<int32>(tokens[3].c_str());
		_lastStateTime = boost::lexical_cast<DWORD>(tokens[4].c_str());
		_decreaseWaterPerHour = boost::lexical_cast<int32>(tokens[5].c_str());
		_ID = boost::lexical_cast<int32>(tokens[6].c_str());
		_seedLevel = boost::lexical_cast<int32>(tokens[7].c_str());
		b = true;
	}
	else
	{
		MyLog::log->debug("error load bad ploughcell. ");
		b = false;
	}
	return b;
}


void PloughCell::BecomeYoung()
{
	if (enType != growstate_seeding)
	{
	
	}
	changeState();
	enType = growstate_young;
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeGrown, PLOUGHCELL_BECOME_GROWN, time[growstate_grown], 0, 0);
	
}

void PloughCell::BecomeGrown()
{
	changeState();
	enType = growstate_grown;
}

bool PloughCell::BecomeSeeding(int seedlevel)
{
	if (enType != growstate_null)
	{
		return false;
	}
	changeState();
	enType = growstate_seeding;
	_seedLevel = seedlevel;
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeYoung, PLOUGHCELL_BECOME_YOUNG, time[growstate_young], 0, 0);
	return true;
}

void PloughCell::DecreaseWaterPercentagePerHour()
{
	int decreasePerHour = _decreaseWaterPerHour;
	if (_WaterWay)
	{
		decreasePerHour = _WaterWay->DecreaseWater(decreasePerHour);
	}
	
	int32 currentwater =_waterPercentage - decreasePerHour;

	if (currentwater > 0)
	{
		_waterPercentage = currentwater;
	}
}

void PloughCell::WateringCell()
{
	_waterPercentage = _waterPercentageMax;
}

bool PloughCell::SpreadManure(int Manurelevel)
{
	if (_manurelevel != 0)
	{
		return false;
	}
	_manurelevel = Manurelevel;
	return true;
}


int PloughCell::gather()
{
	int resource = 0;
	if (getgrowstate()== growstate_grown)
	{
		
		resource = 50; // wait to modify;
		enType = growstate_null;
		if (_mill)
		{
			resource = _mill->GatherModify(resource);
		}
		
	}
	
	return resource;
	
}

void PloughCell::changeState()
{
	_lastStateTime = getMSTime();
 
}


bool PloughCell::BuildMill(int millLevel)
{
	if (millLevel > _farm->getAllowBuildMill())
	{
		_farm->sendFarmError(_ID, FarmError_THEMILLLEVELTOOHIGH);
		return false;
	}
	else
	{
		
		MillConf* conf = FarmComponentStorage::getSingleton().getMillConf(millLevel);
		if (!conf)
		{
			_farm->sendFarmError(_ID, FarmError_ERRORMILLLEVEL);
		
		}
		else
		{
			PlayerResource* resource = _farm->getPlayer()->getResource();
			if (conf->spendgold > resource->_gold)
			{
				_farm->sendFarmError(_ID, FarmError_BUILDMILLNOTHAVEENOUGHMONEY);
			}
			else
			{
				if (!_mill)
				{
					_mill = new PloughMill();
				}
				if (_mill->getLevel() >= millLevel)
				{
					_farm->sendFarmError(_ID, FarmError_MILLISALREADYINTHISLEVEL);
				}
				else
				{
					_mill->setLevel(millLevel);
					MsgBuildMillACK ACK;
					ACK.set_currentlevel(_mill->getLevel());
					ACK.set_cellid(_ID);
					ACK.set_spendgold(conf->spendgold);//½«À´²¹³ä£»
					resource->_gold -= conf->spendgold;
					_farm->sendMessage(&ACK, GS2C_MsgBuildMillACK);
				}
				

			}
			

		}

		
	}
	return true;
	
}

bool PloughCell::buildWaterWay(int waterwayLevel)
{
	if (waterwayLevel > _farm->getAllowBuildWaterWay())
	{
		_farm->sendFarmError(_ID, enFarmErrorResult::FarmError_THEWATERWAYLEVELTOOHIGH);
		return false;
	}
	else
	{
		WaterWayConf* conf = FarmComponentStorage::getSingleton().getWaterWayConf(waterwayLevel);
		if (!conf)
		{
			_farm->sendFarmError(_ID, FarmError_ERRORWATERWAYLEVEL);
		}
		else
		{
			PlayerResource* resource = _farm->getPlayer()->getResource();
			if (resource->_gold < conf->spendgold)
			{
				_farm->sendFarmError(_ID, FarmError_BUILDWATERWAYNOTHAVEENOUGHMONEY);
			}
			else
			{

				if (!_WaterWay)
				{
					_WaterWay = new PloughWaterWay();
				}
				if (_WaterWay->getLevel() >= waterwayLevel)
				{
					_farm->sendFarmError(_ID, FarmError_WATERWAYALREADYINTHISLEVEL);
				}
				else
				{
					resource->_gold -= conf->spendgold;
					_WaterWay->setLevel(waterwayLevel);
					MsgBuildWaterWayACK ack;
					ack.set_currentlevel(_WaterWay->getLevel());
					ack.set_cellid(_ID);
					ack.set_spendgold(conf->spendgold);
				}
				
			}
			
		}
		

	}

	return true;
	
}
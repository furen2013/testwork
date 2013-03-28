#include "stdafx.h"
#include "PloughCell.h"
#include "EventMgr.h"
#include "boost/lexical_cast.hpp"

PloughCell::PloughCell()
{
	_waterPercentageMax = 100;
	_waterPercentage = _waterPercentageMax;
	_decreaseWaterPerHour = 1;
	_manurelevel = 0;
	
	BecomeSeeding();

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
	changeState();
	enType = growstate_young;
	
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeGrown, PLOUGHCELL_BECOME_GROWN, time[growstate_grown], 0, 0);

}

void PloughCell::BecomeGrown()
{
	changeState();
	enType = growstate_grown;
}

void PloughCell::BecomeSeeding()
{
	changeState();
	enType = growstate_seeding;
	EventMgr::getSingleton().AddEvent(this,&PloughCell::BecomeYoung, PLOUGHCELL_BECOME_YOUNG, time[growstate_young], 0, 0);
}

void PloughCell::DecreaseWaterPercentagePerHour()
{
	int32 currentwater =_waterPercentage - _decreaseWaterPerHour;
	if (currentwater > 0)
	{
		_waterPercentage = currentwater;
	}
}

void PloughCell::WateringCell()
{
	_waterPercentage = _waterPercentageMax;
}


int PloughCell::gather()
{
	int resource = 0;
	if (getgrowstate()== growstate_grown)
	{
		
		resource = 50; // wait to modify;
		enType = growstate_null;
	}
	
	return resource;
	
}

void PloughCell::changeState()
{
	_lastStateTime = getMSTime();
 
}
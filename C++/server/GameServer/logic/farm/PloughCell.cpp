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

bool PloughCell::LoadFromString(string sz)
{
	std::vector<string> tokens = StrSplit(sz,",");
	int strNumber = tokens.size();
	bool b = true;
	if (strNumber == 5)
	{
		id
		enType = (growstate)boost::lexical_cast<int>(tokens[0].c_str());
		_waterPercentageMax = boost::lexical_cast<int>(tokens[1].c_str());
		_waterPercentage = boost::lexical_cast<int>(tokens[2].c_str());
		_manurelevel = boost::lexical_cast<int>(tokens[3].c_str());
		_lastStateTime = boost::lexical_cast<DWORD>(tokens[4].c_str());
		
	}
	else
	{

	}
	
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

void PloughCell::changeState()
{
	_lastStateTime = getMSTime();
 
}
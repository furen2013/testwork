#include "stdafx.h"
#include "PloughWaterWay.h"
#include "FarmComponentStorage.h"
#include "PloughCell.h"
#include "FarmLogic.h"
PloughWaterWay::PloughWaterWay()
	:_ploughCell(NULL),
	_decreaseWater(0),
	_modifydecreasePct(0),
	_modifydecrease(0)
{

}

PloughWaterWay::~PloughWaterWay()
{

}

int PloughWaterWay::DecreaseWater(int decrease)
{
	FarmLogic* pfarm = _ploughCell->getFarm();
	int tempWater = 0;
	tempWater = float(decrease) / 100.f * (1.f + float(_modifydecreasePct)) +
		float(_modifydecrease) * (float)(100 + pfarm->getWaterWayEffectModify()) / 100.f;
	return tempWater;
}

void PloughWaterWay::setLevel(int level)
{
	_level = level;
	changeLevel();
}

void PloughWaterWay::changeLevel() //È±ÉÙË®µÀÅäÖÃ
{
	const WaterWayConf* conf = FarmComponentStorage::getSingleton().getWaterWayConf(_level);
	if (!conf)
	{
		MyLog::log->fatal("not found waterway conf [%d]", _level);
	}
	else
	{
		_modifydecreasePct = conf->modifyPct;
		_modifydecrease = conf->modify;
		
	}
}


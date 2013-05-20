#include "stdafx.h"
#include "PloughWaterWay.h"
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

int PloughWaterWay::DecreaseWater(int currentwater)
{
	int tempWater = 0;
	tempWater = float(_decreaseWater) / 100.f * (1.f + float(_modifydecreasePct)) + _modifydecrease;
	return tempWater;
}

void PloughWaterWay::setLevel(int level)
{
	_level = level;
	changeLevel();
}

void PloughWaterWay::changeLevel() //»±…ŸÀÆµ¿≈‰÷√
{

}


#pragma once
#ifndef PLOUGHWATERWAY_H
#define PLOUGHWATERWAY_H
class PloughCell;
class PloughWaterWay
{
public:
	PloughWaterWay();
	~PloughWaterWay();
	int DecreaseWater(int currentwater);
protected:
	PloughCell* _ploughCell;
	int32 _decreaseWater;
	int32 _modifydecreasePct;
	int32 _modifydecrease;
};
#endif
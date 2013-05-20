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
	inline int getLevel()
	{
		return _level;
	}
	void setLevel(int level);
protected:
	void changeLevel();
protected:
	PloughCell* _ploughCell;
	int32 _decreaseWater;
	int32 _modifydecreasePct;
	int32 _modifydecrease;
	int32 _level;
};
#endif
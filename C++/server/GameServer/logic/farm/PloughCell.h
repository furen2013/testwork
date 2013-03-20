#pragma once
#ifndef PLOUGHCELL_H
#define PLOUGHCELL_H
#include "EventableObject.h"
class FarmLogic;
enum growstate
{
	growstate_seeding,
	growstate_young,
	growstate_grown,
	growstate_max
};
class PloughCell : public EventableObject
{
public:
	PloughCell();
	~PloughCell();
public:
	bool LoadFromString(string sz);
	
	void BecomeYoung();
	void BecomeGrown();
	void BecomeSeeding();
	void DecreaseWaterPercentagePerHour();
	void WateringCell();
	inline int getgrowstate(){return enType;}
	inline int getID(){return _ID;}
	inline FarmLogic* getFarm(){return _farm;}
	inline void setFarm(FarmLogic* pfarm){_farm = pfarm;}
protected:
	void changeState();
protected:
	int32 _level;
	growstate enType;
	int time[growstate_max];
	int32 _waterPercentage;
	int32 _manurelevel;
	DWORD _lastStateTime;
protected:
	int32 _decreaseWaterPerHour;
	int32 _waterPercentageMax;
	int32 _ID;

	FarmLogic* _farm; 
};

#endif
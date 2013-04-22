#pragma once
#ifndef PLOUGHCELL_H
#define PLOUGHCELL_H
#include "EventableObject.h"
class FarmLogic;
class PloughMill;
class PloughWaterWay;

enum growstate
{
	growstate_null,
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
	string ToString();
	
	void BecomeYoung();
	void BecomeGrown();
	bool BecomeSeeding(int seedlevel);
	void DecreaseWaterPercentagePerHour();
	void WateringCell();
	bool SpreadManure(int Manurelevel);
	int32 gather();
	inline growstate getgrowstate(){return enType;}
	inline int32 getID(){return _ID;}
	inline FarmLogic* getFarm(){return _farm;}
	inline void setFarm(FarmLogic* pfarm){_farm = pfarm;}
	inline int32 getLevel(){return _level;}
	inline int32 getWaterPercentage(){return _waterPercentage;}
	inline int32 getManureLevel(){return _manurelevel;}
	inline int32 getSeedLevel(){return _seedLevel;}
	inline DWORD getLastStateTime(){return _lastStateTime;}
	inline int32 getDecreaseWaterPerhour(){return _decreaseWaterPerHour;}
	inline int32 getWaterPercentageMax(){return _waterPercentageMax;}
protected:
	void changeState();
protected:
	int32 _level;
	growstate enType;
	int time[growstate_max];
	int32 _waterPercentage;
	int32 _manurelevel;
	int32 _seedLevel;
	DWORD _lastStateTime;
protected:
	int32 _decreaseWaterPerHour;
	int32 _waterPercentageMax;
	int32 _ID;

	FarmLogic*		_farm; 
	PloughMill*		_mill;
	PloughWaterWay* _WaterWay;
};

#endif
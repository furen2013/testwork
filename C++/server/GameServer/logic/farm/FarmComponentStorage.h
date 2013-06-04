#ifndef FARMCOMPONENTSTORAGE_H
#define FARMCOMPONENTSTORAGE_H
#include <iostream>
#include <map>


struct  WaterWayConf
{
	int level;
	int spendgold;
	int modify;
	int modifyPct;
};
struct MillConf
{
	int level;
	int spendgold;
	int modify;
	int modifyPct;
};

class FarmComponentStorage: public Singleton<FarmComponentStorage>
{
	typedef map<int, WaterWayConf*> WATERWAYCONFS;
	typedef map<int, MillConf*> MILLCONFS;
public:
	FarmComponentStorage();
	~FarmComponentStorage();
public:
	void Load();
	const WaterWayConf* getWaterWayConf(int level);
	const MillConf* getMillConf(int level);
protected:
	WATERWAYCONFS _waterWays;
	MILLCONFS     _millConfs;

};
#endif
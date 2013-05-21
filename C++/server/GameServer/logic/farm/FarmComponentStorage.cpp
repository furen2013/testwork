#include "stdafx.h"
#include "FarmComponentStorage.h"
initialiseSingleton(FarmComponentStorage);
FarmComponentStorage::FarmComponentStorage()
{
	Load();
}

FarmComponentStorage::~FarmComponentStorage()
{

}


void FarmComponentStorage::Load()
{

}

MillConf* FarmComponentStorage::getMillConf(int level)
{

	MillConf* p = NULL;
	MILLCONFS::iterator it = _millConfs.find(level);
	if (it != _millConfs.end())
	{
		p = it->second;
	}
	return p;
}

WaterWayConf* FarmComponentStorage::getWaterWayConf(int level)
{
	WaterWayConf* p = NULL;
	WATERWAYCONFS::iterator it = _waterWays.find(level);
	if (it != _waterWays.end())
	{
		p = it->second;
	}
	return p;
}


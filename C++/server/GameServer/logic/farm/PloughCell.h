#pragma once
#ifndef PLOUGHCELL_H
#define PLOUGHCELL_H
enum growstate
{
	growstate_seeding,
	growstate_young,
	growstate_grown,
	growstate_max
};
class PloughCell
{
public:
	PloughCell();
	~PloughCell();
public:
	void BecomeYoung();
	void BecomeGrown();
	void BecomeSeeding();
	
protected:
	int32 level;
	growstate enType;
	int time[growstate_max];
};

#endif
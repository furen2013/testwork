#pragma once
#ifndef PLOUGHMILL_H
#define PLOUGHMILL_H
class PloughCell;
class PloughMill
{
public:
	PloughMill();
	~PloughMill();
	int GatherModify(int gather);
protected:
	PloughCell* _ploughCell;
	int32 _modifyHavestPct;
	int32 _modifyHavest;
	int32 _modify;
	
};
#endif
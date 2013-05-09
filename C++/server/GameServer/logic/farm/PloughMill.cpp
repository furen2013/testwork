#include "stdafx.h"
#include "PloughMill.h"
PloughMill::PloughMill()
	:_ploughCell(NULL),
	_modifyHavest(0),
	_modifyHavestPct(0)
{

}

PloughMill::~PloughMill()
{

}

int PloughMill::GatherModify(int gather)
{
	int temp = gather;
	
	temp = (float(gather) / 100.f * float(_modifyHavestPct)) + float(_modifyHavest);
	return temp;
}
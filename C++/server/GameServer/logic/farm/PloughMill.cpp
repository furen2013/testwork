#include "stdafx.h"
#include "PloughMill.h"
#include "FarmLogic.h"
#include "PloughCell.h"
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
	FarmLogic* pfarm = _ploughCell->getFarm();
	temp = (float(gather) / 100.f * float(_modifyHavestPct)) + (float(_modifyHavest) * (100.f + float(pfarm->getMillEffectModify())));
	return temp;
}
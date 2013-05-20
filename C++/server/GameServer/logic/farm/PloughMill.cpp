#include "stdafx.h"
#include "PloughMill.h"
#include "FarmLogic.h"
#include "PloughCell.h"
PloughMill::PloughMill()
	:_ploughCell(NULL),
	_modifyHavest(0),
	_modifyHavestPct(0),
	_level(0)
{

}

PloughMill::~PloughMill()
{

}

int PloughMill::GatherModify(int gather)
{
	int temp = gather;
	FarmLogic* pfarm = _ploughCell->getFarm();
	temp = (float(gather) / 100.f * float(_modifyHavestPct)) +
		(float(_modifyHavest) * (100.f + float(pfarm->getMillEffectModify())));
	return temp;
}

int PloughMill::getLevel()
{
	return _level;
}

void PloughMill::setLevel(int level)
{
	_level = level;
	changeLevel();
}

// »±…Ÿ∏ˆ≈‰÷√
void PloughMill::changeLevel()
{

}

#include "stdafx.h"
#include "PloughMill.h"
#include "FarmLogic.h"
#include "PloughCell.h"
#include "FarmComponentStorage.h"
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

// È±ÉÙ¸öÅäÖÃ
void PloughMill::changeLevel()
{
	const MillConf* conf = FarmComponentStorage::getSingleton().getMillConf(_level);
	if (!conf)
	{
		MyLog::log->fatal("not found mill conf [%d]", _level);
	}
	else
	{
		_modifyHavest = conf->modify;
		_modifyHavestPct = conf->modifyPct;
	}
}

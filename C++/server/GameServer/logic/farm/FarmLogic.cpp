#include "stdafx.h"
#include "FarmLogic.h"
#include "boost/lexical_cast.hpp"
#include "PloughCell.h"
#include "../Player.h"
#include "../PlayerManager.h"
FarmLogic::FarmLogic()
{
	_modify = true;
}

FarmLogic::~FarmLogic()
{

}

void FarmLogic::modify()
{
	_modify = true;
}

string FarmLogic::MakeCellsStr()
{
	string Temp;
	PLOUGHCELL::iterator it = _cells.begin();
	for (int i = 0; it != _cells.end(); ++ it, i ++)
	{
		if (i != 0)
		{
			Temp += ";";
		}
		PloughCell* p = it->second;
		Temp += p->ToString();
	}
	return Temp;
}

void FarmLogic::start()
{

}

bool FarmLogic::LoadCells(string str)
{
	vector<string> cellsinfo = StrSplit(str, ";");
	vector<string>::iterator it = cellsinfo.begin();
	for (; it != cellsinfo.end(); ++ it)
	{
		PloughCell* cell = new PloughCell();
		cell->LoadFromString(*it);
		_cells.insert(PLOUGHCELL::value_type(cell->getID(), cell));

	}
	return true;
}

int FarmLogic::gatherPloughCell(int id)
{
	int resorce = 0;
	PloughCell* p = getPloughCell(id);
	if (p &&p->getgrowstate() == growstate_grown)
	{
		resorce = p->gather();
	}
	return resorce;
}

PloughCell* FarmLogic::getPloughCell(int id)
{
	PloughCell* cell = NULL;
	PLOUGHCELL::iterator it = _cells.find(id);
	if (it != _cells.end())
	{
		cell = it->second;
	}
	
	return cell;
}
#include "stdafx.h"
#include "FarmLogic.h"
#include "boost/lexical_cast.hpp"
#include "PloughCell.h"
#include "../Player.h"
#include "../PlayerManager.h"
#include "../../Net/NetSession.h"
#include "MessageFarmG2C.pb.h"
FarmLogic::FarmLogic()
{
	_NetSession = NULL;
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

void FarmLogic::sendFarmState()
{
	if (_NetSession != NULL)
	{
		PloughCell* cell = NULL;
		MsgFarmInfoACK MsgSend;
		MsgFarmInfo* info = MsgSend.mutable_info();
		PLOUGHCELL::iterator it = _cells.begin();
		for (; it != _cells.end(); ++ it)
		{
			cell = it->second;
			MsgPloughCellInfo* cellInfo = info->add_cells();
			cellInfo->set_level(cell->getLevel());
			cellInfo->set_manurelevel(cell->getManureLevel());
			cellInfo->set_waterpercentage(cell->getWaterPercentage());
			cellInfo->set_decreasewaterperhour(cell->getDecreaseWaterPerhour());
			cellInfo->set_laststatetime(cell->getLastStateTime());
			cellInfo->set_waterpercentagemax(cell->getDecreaseWaterPerhour());
			cellInfo->set_id(cell->getID());
			switch(cell->getgrowstate())
			{
			case growstate_grown:
				{
					cellInfo->set_state(MsgPloughCellInfo_GrowState_State_Grown);
				}
				break;
			case growstate_null:
				{
					cellInfo->set_state(MsgPloughCellInfo_GrowState_State_NULL);
				}
				break;
			case growstate_seeding:
				{
					cellInfo->set_state(MsgPloughCellInfo_GrowState_State_Seeding);
				}
				break;
			case growstate_young:
				{
					cellInfo->set_state(MsgPloughCellInfo_GrowState_State_Young);
				}
				break;
			}
		}
		_NetSession->sendMessage(&MsgSend,GS2C_MsgFarmInfoACK);
	}
	else
	{
		MyLog.log->warn("send farm info failed _NetSession is null");
	}
	
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
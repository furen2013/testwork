#include "stdafx.h"
#include "FarmLogic.h"
#include "boost/lexical_cast.hpp"
#include "PloughCell.h"
#include "../Player.h"
#include "../PlayerManager.h"
#include "../PlayerResourceManager.h"
#include "../../Net/NetSession.h"
#include "MyLog.h"

FarmLogic::FarmLogic()
	:_allowBuildWaterWay(0),
	_modify(true),
	_allowBuildMill(0),
	_waterWayEffectModify(0),
	_millEffectModify(0),
	_Player(NULL)
{
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


bool FarmLogic::wateringCell(int id)
{
	bool b = false;
	PloughCell* p = getPloughCell(id);
	if (!p)
	{
		sendFarmError(id, FarmError_NOTFOUNDCELL);
	}
	else
	{
		MsgWaterCellACK ACK;
		ACK.set_cellid(id);
		p->WateringCell();
		sendMessage(&ACK, GS2C_MsgWaterCellACK);
		b = true;
	}
	return b;
}


void FarmLogic::modifyMillEffect(int m)
{
	_millEffectModify += m;
	
}
void FarmLogic::modifyWaterWayEffect(int m)
{
	_waterWayEffectModify += m;
}

void FarmLogic::modifyCellBaseHavest(int m)
{
	_modifyBaseHavest += m;
}

bool FarmLogic::gatherPloughCell(int id)
{
	bool b = false;
	//MsgGatherPloughCellACK
	PloughCell* p = getPloughCell(id);
	if (!p)
	{
		sendFarmError(id, FarmError_NOTFOUNDCELL);
	}
	else
	{
		if (p->getgrowstate() != growstate_grown)
		{
			sendFarmError(id, FarmError_GATHERNOTGROWNCELL);
		}
		else
		{
			PlayerResource* playeresource =  _Player->getResource();
			if (playeresource)
			{
				MsgGatherPloughCellACK gatherACK;
				int resource = 0;
				resource = p->gather();
				gatherACK.set_cellid(id);
				gatherACK.set_resource(resource);
				playeresource->_petfood += resource;
				MyLog::log->info("player name[%s] account [%lu] gather cell[%d] success gains [%d] petfood so have [%d] petfoods",_Player->getName(),
					_Player->getAccount(), id, resource, playeresource->_petfood);
				sendMessage(&gatherACK,GS2C_MsgGatherPloughCellACK);
				b = true;
			}
			else
			{
				MyLog::log->warn("player name[%s] account [%lu] not fond resource");
				sendFarmError(id, FarmError_UKNOWN);
			}
			
		}
		
	}
	return b;

}

void FarmLogic::modifyallowBuildMill(int m)
{
	_allowBuildMill += m;
}
void FarmLogic::modifyallowBuildWaterWay(int m)
{
	_allowBuildWaterWay +=m;
}

void FarmLogic::allowBuildMill(int n)
{
	_allowBuildMill = n;
}
void FarmLogic::allowBuildWaterWay(int n)
{
	_allowBuildWaterWay = n;
}

void FarmLogic::sendFarmError(int id, enFarmErrorResult error)
{
	MsgFarmErrorACK errorack;
	errorack.set_cellid(id);
	errorack.set_en(error);
	sendMessage(&errorack, GS2C_MsgFarmErrorACK);
}

void FarmLogic::sendMessage(::google::protobuf::Message* message, MsgType type)
{
	if (GetNetSession())
	{
		GetNetSession()->sendMessage(message, type);
	}
	
}

NetSession* FarmLogic::GetNetSession()
{
	if (_Player)
	{
		_Player->getNetSession();
	}
	return NULL;
}

bool FarmLogic::seedCell(int id, int seedlevel)
{
	bool b = false;
	PloughCell* p = getPloughCell(id);
	if (!p)
	{
		sendFarmError(id, FarmError_NOTFOUNDCELL);

	}
	else
	{
		if (p->getgrowstate() != growstate_null)
		{
			sendFarmError(id, FarmError_CELLCANNOTSEED);
		}
		else
		{
			if (seedlevel > 0)
			{
				if (p->BecomeSeeding(seedlevel))
				{
					MyLog::log->info("player name[%s] account [%lu] seed cell [%d] with seedcell [%d] success",_Player->getName(),_Player->getAccount(),
						id, seedlevel);
					MsgSeedCellACK ACK;
					ACK.set_cellid(id);
					ACK.set_seedlevel(seedlevel);
					sendMessage(&ACK, GS2C_MsgSeedCellACK);
					b = true;
				}
				else
				{
					sendFarmError(id, FarmError_CELLCANNOTSEED);
				}
			}
			
			
		}
	}

	return b;
}

void FarmLogic::sendFarmState()
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
		cellInfo->set_waterpercentagemax(cell->getWaterPercentageMax());
		cellInfo->set_realdecreasewaterperhour(cell->getRealDecreaseWaterPerhour());
		cellInfo->set_realhavest(cell->getRealHavest());
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
	sendMessage(&MsgSend,GS2C_MsgFarmInfoACK);

	
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

bool FarmLogic::spreadManure(int cellid, int Spreadmanure)
{
	bool b = false;
	PloughCell* p = getPloughCell(cellid);
	if (!p)
	{
		sendFarmError(cellid, FarmError_NOTFOUNDCELL);
	}
	else
	{
		if (p->SpreadManure(Spreadmanure))
		{
			MsgSpreadManureACK ACK;
			sendMessage(&ACK, GS2C_MsgSpreadManureACK);
			MyLog::log->info("player name[%s] account [%lu] spread manure cellid[%d] success with manure level [%d]" ,
				_Player->getName(), _Player->getAccount(), cellid,Spreadmanure);
			b = true;
		}
		else
		{
			sendFarmError(cellid, FarmError_ISHAVEMANURE);
		}
	}
	return b;
	

}
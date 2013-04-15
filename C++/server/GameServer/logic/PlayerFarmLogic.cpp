#include "stdafx.h"
#include "Player.h"
#include "MessageFarmG2C.pb.h"
#include "farm/FarmLogic.h"
void Player::sendFarmState()
{
	if (_farm)
	{
		_farm->sendFarmState();

	}
}


void Player::spreadManure(int cellid, int Spreadmanure)
{
	if (_PlayerResource->_manure > 0)
	{
		if (_farm->spreadManure(cellid, Spreadmanure))
		{
			_PlayerResource->_manure -= 1;
		}
	}
	else
	{
		_farm->sendFarmError(cellid, FarmError_NOTHAVEMANURE);
	}


}
void Player::gatherPloughCell(int id)
{
	_farm->gatherPloughCell(id);
}
void Player::wateringCell(int id)
{
	_farm->wateringCell(id);
}
void Player::seedCell(int id, int seedlevel)
{
	if (seedlevel > SeedType_NULL && seedlevel < SeedType_Max)
	{

		if (_PlayerResource->_seeds[seedlevel] > 0)
		{
			if (_farm->seedCell(id, seedlevel))
			{
				_PlayerResource->_seeds[seedlevel] --;
			}
		}
		else
		{
			_farm->sendFarmError(id, FarmError_NOTHAVESEED);
		}

	}
	else
	{
		_farm->sendFarmError(id, FarmError_ERRORSEED);
	}

}
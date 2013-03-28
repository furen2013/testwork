#include "stdafx.h"
#include "Player.h"
void Player::spreadManure(int Manurelevel)
{
	if (!IsValid())
	{
		return;
	}

	if (_PlayerResource)
	{
		if (_PlayerResource->_manure > 0)
		{

		}
		else
		{

		}
		
	}
}

void Player::gatherFarm(int cell, DWORD account)
{
	if (!IsValid())
	{
		return;
	}
}
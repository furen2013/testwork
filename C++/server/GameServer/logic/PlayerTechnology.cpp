#include "stdafx.h"
#include "Player.h"
#include "technology/Technology.h"
void Player::sendTechnologyState()
{
	if (_technology)
	{
		_technology->sendTechnologyState();
	}
}

void Player::openTechLevel(int level)
{
	if (_technology)
	{
		_technology->openTechLevel(level);
	}
}

void Player::addTechValue(int value)
{
	if (_technology)
	{
		_technology->addTechValue(value);
	}
}

void Player::addTechInfo(int level, int id, int count /* = 1 */)
{
	if (_technology)
	{
		_technology->addTech(level, id, count);
	}
}
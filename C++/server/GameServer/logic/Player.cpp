#include "stdafx.h"
#include "Player.h"
//#include "MyLog.h"
Player::Player()
{
	_Info = NULL;
}

Player::~Player()
{

}
DWORD Player::getAccount()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getAccount()");
		return 0;
	}
	return _Info->_account;
}
int Player::getLevel()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getLevel()");
		return 0;
	}
	return _Info->_level;
}
int Player::getIcon()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getIcon()");
		return 0;
	}
	return _Info->_icon;
}
const char* Player::getName()
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when getName()");
		return NULL;
	}

	return _Info->_name.c_str();
}
void Player::setAccount(DWORD account)
{
	if (!IsValid())
	{
		MyLog::log->warn("Player is invalid when setAccount()");
		return;
	}
	_Info->_account = account;
}

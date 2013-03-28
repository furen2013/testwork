#include "stdafx.h"
#include "PlayerManager.h"
#include "Player.h"

initialiseSingleton(PlayerManager);
PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}
Player* PlayerManager::getPlayer(DWORD account)
{
	Player* p = NULL;
	mapPlayer::iterator it = _players.find(account);
	if (it != _players.end())
	{
		p = it->second;
	}
	return p;
}

bool PlayerManager::addPlayer(Player* p)
{
	if (p == NULL)
	{
		return false;
	}

	mapPlayer::iterator it = _players.find(p->getAccount());
	if (it == _players.end())
	{
		_players.insert(mapPlayer::value_type(p->getAccount(), p));
	}
	return p;
}


bool PlayerManager::delPlayer(DWORD account)
{
	bool b = false;
	mapPlayer::iterator it = _players.find(account);
	if (it != _players.end())
	{
		Player* p = NULL;
		p = it->second;
		_players.erase(it);
		delete p;
		b = true;
	}
	return b;

}

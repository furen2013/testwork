#include "stdafx.h"
#include "PlayerResourceManager.h"
#include "Player.h"
initialiseSingleton(PlayerResourceManager);
PlayerResourceManager::PlayerResourceManager()
{

}

PlayerResourceManager::~PlayerResourceManager()
{

}

void PlayerResourceManager::Init()
{

}

PlayerResource* PlayerResourceManager::GetPlayerResource(DWORD account)
{
	PlayerResource* resource = NULL;
	mapPlayerResource::iterator it = _playerResources.find(account);
	if (it != _playerResources.end())
	{
		resource = it->second;
	}
	return resource;

}

PlayerResource* PlayerResourceManager::CreateResource(DWORD account)
{
	PlayerResource* resource = NULL;
	mapPlayerResource::iterator it = _playerResources.find(account);
	if (it == _playerResources.end())
	{
		resource = new PlayerResource();
		resource->_account = account;
		_playerResources.insert(mapPlayerResource::value_type(account, resource));
	}
	return resource;
}

bool PlayerResourceManager::addPlayerResource(PlayerResource* p)
{
	bool B = true;
	mapPlayerResource::iterator it = _playerResources.find(p->_account);
	if (it == _playerResources.end())
	{
		_playerResources.insert(mapPlayerResource::value_type(p->_account, p));
	}
	else
	{
		B = false;
	}
	return B;
}
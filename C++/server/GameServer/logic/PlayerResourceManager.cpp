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
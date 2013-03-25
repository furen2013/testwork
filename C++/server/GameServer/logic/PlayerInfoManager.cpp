#include "stdafx.h"
#include "PlayerInfoManager.h"
#include "Player.h"
initialiseSingleton(PlayerInfoManager);
PlayerInfoManager::PlayerInfoManager()
{

}

PlayerInfoManager::~PlayerInfoManager()
{

}

bool PlayerInfoManager::LoadFromDB()
{
	return true;
}

PlayerInfo* PlayerInfoManager::GetPlayerInfo(DWORD account)
{
	PlayerInfo* info = NULL;
	mapPlayerInfo::iterator it = _PlayerInfos.find(account);
	if (it != _PlayerInfos.end())
	{
		info = it->second;
	}
	return info;
}

PlayerInfo* PlayerInfoManager::CreatePlayerInfo(DWORD account)
{
	PlayerInfo* info = NULL;
	mapPlayerInfo::iterator it = _PlayerInfos.find(account);
	if (it == _PlayerInfos.end())
	{
		info = new PlayerInfo();
		info->_account = account;
		_PlayerInfos.insert(mapPlayerInfo::value_type(account, info));
	}
	return info;
}
#pragma once
#ifndef PLAYERRESOURCEMANAGER_H
#define PLAYERRESOURCEMANAGER_H
class PlayerResource;
class PlayerResourceManager : public Singleton<PlayerResourceManager>
{
public:
	typedef map<DWORD, PlayerResource*> mapPlayerResource;
public:
	PlayerResourceManager();
	~PlayerResourceManager();
	PlayerResource* GetPlayerResource(DWORD account);
	PlayerResource* CreateResource(DWORD account);
protected:
	mapPlayerResource _playerResources;
};
#endif
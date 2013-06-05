#pragma once
#ifndef PLAYERRESOURCEMANAGER_H
#define PLAYERRESOURCEMANAGER_H
struct PlayerResource;
class PlayerResourceManager : public Singleton<PlayerResourceManager>
{
public:
	typedef map<DWORD, PlayerResource*> mapPlayerResource;
public:
	PlayerResourceManager();
	~PlayerResourceManager();
public:
	void Init();
	PlayerResource* GetPlayerResource(DWORD account);
	PlayerResource* CreateResource(DWORD account);
	bool addPlayerResource(PlayerResource* p);
protected:
	mapPlayerResource _playerResources;
};
#endif
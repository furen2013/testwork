#pragma once
#ifndef PLAYERINFOMANAGER_H
#define PLAYERINFOMANAGER_H
struct PlayerInfo;
class PlayerInfoManager: public Singleton<PlayerInfoManager>
{
public:
	typedef map<DWORD, PlayerInfo*> mapPlayerInfo;
public:
	PlayerInfoManager();
	~PlayerInfoManager();
	bool LoadFromDB();
	PlayerInfo* GetPlayerInfo(DWORD account);
	PlayerInfo* CreatePlayerInfo(DWORD account);
protected:
	mapPlayerInfo _PlayerInfos;
};

#endif
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
enum enSeedType
{
	SeedType_Copper,
	SeedType_Silver,
	SeedType_Gold,
	SeedType_Max
};
struct PlayerInfo
{
	PlayerInfo()
	{

	}
	DWORD _account;
	int _level;
	int _icon;
	string _name;
	long _CreateTime;

};

struct PlayerResource
{
	PlayerResource()
	{

	}
	DWORD _account;
	int _gold;
	int _ruby;
	int _manure;
	int _seeds[SeedType_Max];
};

class Player : public Unit
{
public:
	Player();
	~Player();
public:
	DWORD getAccount();
	int getLevel();
	int getIcon();
	const char* getName();
	void setAccount(DWORD account);
	inline bool IsValid()
	{
		if (_Info == NULL)
		{
			return false;
		}
		return true;
	}
	inline void setPlayerInfo(PlayerInfo* info){_Info = info;}
	inline void setPlayerResource(PlayerResource* resource){_PlayerResource = resource;}
protected:
	PlayerInfo* _Info;
	PlayerResource* _PlayerResource;

};
#endif
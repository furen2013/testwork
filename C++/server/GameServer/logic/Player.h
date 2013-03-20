#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
struct PlayerInfo
{
	DWORD _account;
	int _level;
	int _icon;
	string _name;
	long CreateTime;
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
protected:
	PlayerInfo* _Info;

};
#endif
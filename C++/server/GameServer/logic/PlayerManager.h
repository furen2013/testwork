#pragma once
#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
class Player;
class PlayerManager: public Singleton<PlayerManager>
{
public:
	typedef map<DWORD , Player*> mapPlayer;
public:
	PlayerManager();
	~PlayerManager();
	Player* getPlayer(DWORD account);
	bool addPlayer(Player* p);
	bool delPlayer(DWORD account);

protected:
	mapPlayer _players;
};

#endif
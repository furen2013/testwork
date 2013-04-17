#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "MsgHead.pb.h"
class Database;
class NetSession;
class Technology;
class FarmLogic;

enum enSeedType
{	SeedType_NULL,
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
	string _icon;
	string _name;
	long _CreateTime;

};

struct PlayerResource
{
	PlayerResource()
	{
		_account = 0;
		_gold = 0;
		_ruby = 0;
		_manure = 0;
		_petfood = 0;
		for (int i = 0; i < SeedType_Max; i ++)
		{
			_seeds[i] = 0;
		}
	}
	DWORD _account;
	int32 _gold;
	int32 _ruby;
	int32 _manure;
	int32 _seeds[SeedType_Max];
	int32 _petfood;
};

class Player : public Unit
{
public:
	Player();
	~Player();
public:
	bool Load(DWORD account);
	void LoadFromDBProc(QueryResultVector & results);
	DWORD getAccount();
	int getLevel();
	const char* getIcon();
	const char* getName();
	void setAccount(DWORD account);
	NetSession* getSession();
	void setSession(NetSession* p);
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
public: // farm
	void spreadManure(int cellid, int Spreadmanure);
	void gatherPloughCell(int id);
	void wateringCell(int id);
	void sendFarmState();
	void seedCell(int id, int seedlevel);
public: //technology
	void sendTechnologyState();
	void openTechLevel(int level);
	void addTechValue(int value);
	void addTechInfo(int level, int id, int count = 1);
public:
	void sendMessage(::google::protobuf::Message* message, MsgType type);
	

public:
	inline FarmLogic* getFarm(){return _farm;}
	inline Technology* getTechnology(){return _technology;}	
	inline NetSession* getNetSession(){return _session;}
	inline PlayerResource* getResource(){return _PlayerResource;}


protected:
	PlayerInfo* _Info;
	PlayerResource* _PlayerResource;
	Database* _db;
	NetSession* _session;
	Technology* _technology;
	FarmLogic* _farm;
protected:
	DWORD _TempAccount;
	DWORD getTempAccount();
};
#endif
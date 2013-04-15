#pragma once
#ifndef FARMLOGIC_H
#define FARMLOGIC_H
#include "EventableObject.h"
#include "MsgHead.pb.h"
#include "MessageFarmG2C.pb.h"
class NetSession;
class PloughCell;
class Player;
typedef map<int, PloughCell*> PLOUGHCELL;
class FarmLogic : public EventableObject
{
public:
	FarmLogic();
	virtual ~FarmLogic();
public:
	inline void setAccount(DWORD account){_account = account;}
	inline DWORD getAccount(){return _account;}
	bool LoadCells(string str);
	void start();
public:
	string MakeCellsStr();
	void modify();
	bool spreadManure(int cellid, int Spreadmanure);
	bool gatherPloughCell(int id);
	bool wateringCell(int id);
	PloughCell* getPloughCell(int id);
	void sendFarmState();
	bool seedCell(int id, int seedlevel);
	void sendFarmError(int id, enFarmErrorResult error);
protected:
	NetSession* GetNetSession();
	void sendMessage(::google::protobuf::Message* message, MsgType type);
	
	
protected:
	DWORD _account;
	PLOUGHCELL _cells;
	bool _modify;
	//NetSession* _NetSession;
	Player* _Player;
};

#endif
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
	void modifyallowBuildMill(int m);
	void modifyallowBuildWaterWay(int m);
	void allowBuildMill(int n);
	void allowBuildWaterWay(int n);
	void modifyMillEffect(int m);
	void modifyWaterWayEffect(int m);
	void modifyCellBaseHavest(int m);
	inline int getMillEffectModify()
	{
		return _millEffectModify;
	}

	inline int getAllowBuildMill()
	{
		return _allowBuildMill;
	}
	inline int getAllowBuildWaterWay()
	{
		return _allowBuildWaterWay;
	}
	inline Player* getPlayer()
	{
		return _Player;
	}
	void sendMessage(::google::protobuf::Message* message, MsgType type);
protected:
	NetSession* GetNetSession();

	
	
protected:
	DWORD _account;
	PLOUGHCELL _cells;
	bool _modify;
	int _allowBuildMill;
	int _allowBuildWaterWay;
	int _millEffectModify;
	int _waterWayEffectModify;
	int _modifyBaseHavest;
	Player* _Player;
};

#endif
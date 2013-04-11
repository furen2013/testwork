#pragma once
#ifndef FARMLOGIC_H
#define FARMLOGIC_H
#include "EventableObject.h"
class NetSession;
class PloughCell;
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
	void spreadManure();
	int gatherPloughCell(int id);
	PloughCell* getPloughCell(int id);
	void sendFarmState();
	
protected:
	DWORD _account;
	PLOUGHCELL _cells;
	bool _modify;
	NetSession* _NetSession;
};

#endif
#pragma once
#ifndef NETSESSIONMANAGER_H
#define NETSESSIONMANAGER_H
#include "TypeDef.h"
#include "Singleton.h"
class NetSession;
class NetSessionManager : public Singleton<NetSessionManager>
{
	typedef map<DWORD, NetSession*> mapsession;
public:
	NetSessionManager();
	~NetSessionManager();
public:
	NetSession* FindSession(DWORD account);
	NetSession* CreateSession(DWORD account);
	void update(int time);
protected:
	mapsession _sessions;
	boost::mutex _mutex;

};
#endif
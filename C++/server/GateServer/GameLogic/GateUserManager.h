#pragma once
#ifndef GATEUSERMANAGER_H
#define GATEUSERMANAGER_H
#include <map>
#include <boost/thread.hpp>
#include "Singleton.h"
class CCProtoSocket;
typedef std::map<DWORD, CCProtoSocket*> MAPPROTOSOCKET;

class GateUserManager  : public Singleton<GateUserManager>
{
public:
	GateUserManager(void);
	~GateUserManager(void);
public:
	void AddClient(CCProtoSocket* pProtoSocket);
	void DelClient(DWORD dw);

	bool Add2LoginClient(CCProtoSocket* p);
	bool DelFromLoginClient(DWORD dw);
	CCProtoSocket* GetClient(DWORD dw);
	CCProtoSocket* GetLoginClient(DWORD dw);


protected:
	MAPPROTOSOCKET m_clients;
	MAPPROTOSOCKET m_LoginClients;
	boost::mutex m_mutex;

};

#define GUManager GateUserManager::getSingleton()

#endif

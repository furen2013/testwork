#pragma once
#ifndef GATEUSERMANAGER_H
#define GATEUSERMANAGER_H
#include <map>
#include <boost/thread.hpp>
class CCProtoSocket;
typedef std::map<DWORD, CCProtoSocket*> MAPPROTOSOCKET;

class GateUserManager  : public Singleton<CUserManager>
{
public:
	GateUserManager(void);
	~GateUserManager(void);

protected:
	MAPPROTOSOCKET m_clients;
	boost::mutex m_mutex;

};

#endif

#pragma once
#ifndef LOGINGATELISTENER_H
#define LOGINGATELISTENER_H
#include "../../../new_common/Source/net/tcpserver.h"
#include "../../../Common/share/Singleton.h"


#include <map>
#include <boost/thread.hpp>
class CLoginGateSocket;

class CLoginGateListener : public tcp_server, public Singleton<CLoginGateListener>
{
public:
	CLoginGateListener(void);
	~CLoginGateListener(void);
public:
	virtual tcp_basesession* create_session();
	void addSocket(CLoginGateSocket* p);
	void delSocket(CLoginGateSocket* p);
protected:
	std::map<DWORD, CLoginGateSocket*> m_gats;
	boost::mutex m_mutex;
};
#define LGLISTENER CLoginGateListener::getSingleton()
#endif
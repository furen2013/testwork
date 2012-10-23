#pragma once
#ifndef GSLISTENSOCKET_H
#define GSLISTENSOCKET_H

#include "../../new_common/Source/net/tcpserver.h"
#include "../../../Common/share/Singleton.h"
#include <map>
#include <boost/thread.hpp>
class CGTSocket;

class CGSListenSocket :
	public tcp_server ,  public Singleton<CGSListenSocket>
{
public:
	CGSListenSocket(void);
	virtual ~CGSListenSocket(void);
	virtual void stop();
	virtual tcp_basesession* create_session();
	void AddGTSocket(CGTSocket* p);
	void RemoveGTSocket(CGTSocket* p);

protected:

	std::map<DWORD, CGTSocket*> m_Gats;
	boost::mutex m_mutex;
	

};

#define  GSL CGSListenSocket::getSingleton()
#endif
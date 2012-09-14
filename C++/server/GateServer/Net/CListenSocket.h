#pragma once

#include "../../new_common/Source/net/tcpserver.h"

class CCSocket;
class CCListenSocket :
	public tcp_server, public Singleton<CCListenSocket>
{
public:
	CCListenSocket();
	~CCListenSocket();

	virtual tcp_session* create_session();

	void AddAcceptedSocket(CCSocket* pSocket);
	void RemoveAcceptedSocket(CCSocket* pSocket);
	void SendToGateSevers(const char* szBuf, int iLen);
	void KickAllClients();
private:
	boost::mutex m_mutex;
	map<DWORD, CCSocket*> m_mapAccpetedSockets;
};
#define sCLS CCListenSocket::getSingleton()

#pragma once

#include "../../new_common/Source/net/tcpserver.h"

class CGTSocket;
class CGTListenSocket :
	public tcp_server, public Singleton<CGTListenSocket>
{
public:
	CGTListenSocket();

	virtual void stop();
	virtual tcp_session* create_session();

	void AddAcceptedSocket(CGTSocket* pSocket);
	void RemoveAcceptedSocket(CGTSocket* pSocket);
	void SendToGateSevers(const char* szBuf, int iLen);
	void UpdateGateServerStates();
private:
	map<DWORD, CGTSocket*> m_mapAccpetedSockets;
};
#define sGTLS CGTListenSocket::getSingleton()

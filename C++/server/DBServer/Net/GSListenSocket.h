#pragma once

#include "../../new_common/Source/net/tcpserver.h"

class CGSSocket;
class CGSListenSocket :
	public tcp_server, public Singleton<CGSListenSocket>
{
public:
	CGSListenSocket();
	virtual void stop();
	virtual tcp_session* create_session();

	void AddAcceptedSocket(CGSSocket* pSocket);
	void RemoveAcceptedSocket(CGSSocket* pSocket);
	CGSSocket* FindGSByIdx(BYTE byGSIdx);
	void SendToGameSevers(const char* szBuf, int iLen);
	void UpdateGameServerStates();
private:
	map<CGSSocket*, CGSSocket*> m_mapAccpetedSockets;
};
#define sGSLS CGSListenSocket::getSingleton()

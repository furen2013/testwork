#pragma once
#ifndef CCLISTENPROTOSOCKET_H
#define CCLISTENPROTOSOCKET_H

class CCProtoSocket;
#include "../../new_common/Source/net/tcpserver.h"
class CCListenProtoSocket :
	public tcp_server, public Singleton<CCListenProtoSocket>
{
public:
	CCListenProtoSocket();
	virtual ~CCListenProtoSocket();

	virtual tcp_basesession* create_session();

	void AddAcceptedSocket(CCProtoSocket* pSocket);
	void RemoveAcceptedSocket(CCProtoSocket* pSocket);
	
	void SendToGateSevers(const char* szBuf, int iLen);
	void KickAllClients();
private:
	boost::mutex m_mutex;
	map<DWORD, CCProtoSocket*> m_mapAccpetedSockets;
	map<DWORD, CCProtoSocket*> m_mapLoginSockets;

};
#define ProtoListen CCListenProtoSocket::getSingleton()

#endif
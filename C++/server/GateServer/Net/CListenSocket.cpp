#include "../stdafx.h"
#include "CListenSocket.h"
#include "CSocket.h"
initialiseSingleton(CCListenSocket);

CCListenSocket::CCListenSocket() : tcp_server( 1 )
{

}

CCListenSocket::~CCListenSocket()
{

}

tcp_session* CCListenSocket::create_session()
{
	return new CCSocket( *net_global::get_io_service() );
}

void CCListenSocket::AddAcceptedSocket(CCSocket* pSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_mapAccpetedSockets[(DWORD)pSocket] = pSocket;
}

void CCListenSocket::RemoveAcceptedSocket(CCSocket* pSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	map<DWORD, CCSocket*>::iterator iter = m_mapAccpetedSockets.find((DWORD)pSocket);
	if(iter != m_mapAccpetedSockets.end())
	{
		m_mapAccpetedSockets.erase(iter);
	}
}

void CCListenSocket::KickAllClients()
{
	boost::mutex::scoped_lock lock( m_mutex );
	map<DWORD, CCSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CCSocket* pSocket = iter->second;
		pSocket->close();
		net_global::write_close_log( "IP:[%s] GameServer connection lost", pSocket->get_remote_address_string().c_str() );
	}
	m_mapAccpetedSockets.clear();
}
/*
void CCListenSocket::SendToGateSevers(const char* szBuf, int iLen)
{
	map<DWORD, CCSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CCSocket* pSocket = iter->second;
		pSocket->PostSend(szBuf, iLen);
	}
}
*/

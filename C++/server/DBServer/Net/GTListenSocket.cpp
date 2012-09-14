#include "../stdafx.h"
#include "GTListenSocket.h"
#include "GTSocket.h"
initialiseSingleton(CGTListenSocket);

CGTListenSocket::CGTListenSocket() : tcp_server( 2 )
{

}

void CGTListenSocket::stop()
{
	map<DWORD, CGTSocket*>::iterator iter = m_mapAccpetedSockets.begin(), iter_next = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); iter = iter_next)
	{
		CGTSocket* pSocket = iter->second;
		++iter_next;
		m_mapAccpetedSockets.erase(iter);
	}
	tcp_server::stop();
}

tcp_session* CGTListenSocket::create_session()
{
	return new CGTSocket( *net_global::get_io_service() );
}

void CGTListenSocket::AddAcceptedSocket(CGTSocket* pSocket)
{
	m_mapAccpetedSockets[(DWORD)pSocket] = pSocket;
}

void CGTListenSocket::RemoveAcceptedSocket(CGTSocket* pSocket)
{
	map<DWORD, CGTSocket*>::iterator iter = m_mapAccpetedSockets.find((DWORD)pSocket);
	if(iter != m_mapAccpetedSockets.end())
	{
		m_mapAccpetedSockets.erase(iter);
	}
}

void CGTListenSocket::SendToGateSevers(const char* szBuf, int iLen)
{
	map<DWORD, CGTSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CGTSocket* pSocket = iter->second;
		pSocket->PostSend(szBuf, iLen);
	}
}

void CGTListenSocket::UpdateGateServerStates()
{

}

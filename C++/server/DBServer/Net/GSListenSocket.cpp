#include "../stdafx.h"
#include "GSListenSocket.h"
#include "GSSocket.h"
initialiseSingleton(CGSListenSocket);

CGSListenSocket::CGSListenSocket() : tcp_server( 1 )
{

}

void CGSListenSocket::stop()
{
	map<CGSSocket*, CGSSocket*>::iterator iter = m_mapAccpetedSockets.begin(), iter_next = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); iter = iter_next)
	{
		CGSSocket* pSocket = iter->second;
		pSocket->close();
		++iter_next;
		m_mapAccpetedSockets.erase(iter);
	}
	tcp_server::stop();
}

tcp_session* CGSListenSocket::create_session()
{
	return new CGSSocket( *net_global::get_io_service() );
}

void CGSListenSocket::AddAcceptedSocket(CGSSocket* pSocket)
{
	m_mapAccpetedSockets[pSocket] = pSocket;
}

void CGSListenSocket::RemoveAcceptedSocket(CGSSocket* pSocket)
{
	map<CGSSocket*, CGSSocket*>::iterator iter = m_mapAccpetedSockets.find(pSocket);
	if(iter != m_mapAccpetedSockets.end())
	{
		m_mapAccpetedSockets.erase(iter);
	}
}

void CGSListenSocket::SendToGameSevers(const char* szBuf, int iLen)
{
	map<CGSSocket*, CGSSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CGSSocket* pSocket = iter->second;
		pSocket->PostSend(szBuf, iLen);
	}
}

CGSSocket* CGSListenSocket::FindGSByIdx(BYTE byGSIdx)
{
	CGSSocket* pSocket = NULL;
	map<CGSSocket*, CGSSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CGSSocket* pGSTmp = iter->second;
		if(pGSTmp->m_byGSIdx == byGSIdx)
		{
			pSocket = pGSTmp;
			break;
		}
	}
	return pSocket;
}

void CGSListenSocket::UpdateGameServerStates()
{
}

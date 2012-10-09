#include "StdAfx.h"
#include "CListenProtoSocket.h"
#include "CProtoSocket.h"
#include "MyNetGlobleObj.h"


initialiseSingleton(CCListenProtoSocket);

CCListenProtoSocket::CCListenProtoSocket() : tcp_server( 1 )
{

}

CCListenProtoSocket::~CCListenProtoSocket()
{

}

tcp_basesession* CCListenProtoSocket::create_session()
{
	return new CCProtoSocket( *MyNetGlobleObj::get_io_service() );
}

void CCListenProtoSocket::AddAcceptedSocket(CCProtoSocket* pSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_mapAccpetedSockets[(DWORD)pSocket] = pSocket;
}

void CCListenProtoSocket::RemoveAcceptedSocket(CCProtoSocket* pSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	map<DWORD, CCProtoSocket*>::iterator iter = m_mapAccpetedSockets.find((DWORD)pSocket);
	if(iter != m_mapAccpetedSockets.end())
	{
		m_mapAccpetedSockets.erase(iter);
	}
}

void CCListenProtoSocket::KickAllClients()
{
	boost::mutex::scoped_lock lock( m_mutex );
	map<DWORD, CCProtoSocket*>::iterator iter = m_mapAccpetedSockets.begin();
	for(; iter != m_mapAccpetedSockets.end(); ++iter)
	{
		CCProtoSocket* pSocket = iter->second;
		pSocket->close();
		net_global::write_close_log( "IP:[%s] GameServer connection lost", pSocket->get_remote_address_string().c_str() );
	}
	m_mapAccpetedSockets.clear();
}
#include "StdAfx.h"
#include "GateUserManager.h"
#include "ProtoNet/CProtoSocket.h"


GateUserManager::GateUserManager(void)
{
}


GateUserManager::~GateUserManager(void)
{
}

void GateUserManager::AddClient(CCProtoSocket* pProtoSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_clients[pProtoSocket->GetAccountID()] = pProtoSocket;
}

void GateUserManager::DelClient(DWORD dw)
{
	boost::mutex::scoped_lock lock(m_mutex);
	MAPPROTOSOCKET::iterator it = m_clients.find(dw);
	if (it != m_clients.end())
	{
		m_clients.erase(dw);
	}
}

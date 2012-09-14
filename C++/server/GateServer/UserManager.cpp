#include "stdafx.h"
#include "Net/CSocket.h"
initialiseSingleton(CUserManager);
CUserManager::CUserManager(void)
{
	m_itrClient = m_mapClient.begin();
}

CCSocket * CUserManager::GetClient(DWORD dwKey)
{
	boost::mutex::scoped_lock lock( m_mutex );
	MAP_C_ITER itr = m_mapClient.find(dwKey);
	if (itr != m_mapClient.end())
	{
		return itr->second;
	}
	return NULL;
}
CCSocket* CUserManager::GetClientByTransID( uint32 transid )
{
	uint32 accid = CCSocket::GetAccountIDByTransID( transid );
	if( accid )
		return GetClient( accid );
	else
		return NULL;
}

void CUserManager::InsertClient(CCSocket * pClient)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_mapClient[pClient->m_nAccountID] = pClient;
	MyLog::log->debug("UserMgr insert account[%d] ip[%s]", pClient->m_nAccountID, pClient->m_strIP.c_str(), m_mapClient.size());
	sServer.OnClientNum(m_mapClient.size());
}

void CUserManager::DeleteClient(CCSocket * pClient)
{
	boost::mutex::scoped_lock lock( m_mutex );
	MAP_C_ITER itr = m_mapClient.find(pClient->m_nAccountID);
	if (itr != m_mapClient.end())
	{
		m_mapClient.erase(itr);
	}
	MyLog::log->debug("UserMgr remove account[%d]", pClient->m_nAccountID, m_mapClient.size());
	sServer.OnClientNum(m_mapClient.size());
}

CCSocket * CUserManager::GetLoginClient(DWORD dwKey)
{
	boost::mutex::scoped_lock lock( m_mutex );
	MAP_C_ITER itr = m_mapLoginClient.find(dwKey);
	if (itr != m_mapLoginClient.end())
	{
		return itr->second;
	}
	return NULL;
}

void CUserManager::InsertLoginClient(DWORD dwKey, CCSocket * pClient)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_mapLoginClient[dwKey] = pClient;
}

void CUserManager::DeleteLoginClient(CCSocket * pClient)
{
	boost::mutex::scoped_lock lock( m_mutex );
	MAP_C_ITER itr = m_mapLoginClient.find((DWORD)pClient);
	if (itr != m_mapLoginClient.end())
	{
		m_mapLoginClient.erase(itr);
	}
}

CCSocket * CUserManager::GetFirstClient()
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_itrClient = m_mapClient.begin();
	if (m_itrClient != m_mapClient.end())
	{
		return m_itrClient->second;
	}
	return NULL;
}

CCSocket * CUserManager::GetNextClient()
{
	boost::mutex::scoped_lock lock( m_mutex );
	if (++m_itrClient != m_mapClient.end())
	{
		return m_itrClient->second;
	}
	return NULL;
}

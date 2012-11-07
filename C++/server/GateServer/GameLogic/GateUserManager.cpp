#include "StdAfx.h"
#include "GateUserManager.h"
#include "../ProtoNet/CProtoSocket.h"
initialiseSingleton(GateUserManager);

GateUserManager::GateUserManager(void)
{
}


GateUserManager::~GateUserManager(void)
{
}

void GateUserManager::AddClient(CCProtoSocket* pProtoSocket)
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_clients[(DWORD)pProtoSocket] = pProtoSocket;
}

bool GateUserManager::DelFromLoginClient(DWORD dw)
{
	bool b = false;
	{
		boost::mutex::scoped_lock lock(m_mutex);
		MAPPROTOSOCKET::iterator itLogin = m_LoginClients.find(dw);
		if (itLogin == m_LoginClients.end())
		{
			b = true;
			m_LoginClients.erase(itLogin);
		}
	}
	return b;
}

bool GateUserManager::Add2LoginClient(CCProtoSocket* p)
{
	bool b  = false;
	{
		boost::mutex::scoped_lock lock(m_mutex);

		MAPPROTOSOCKET::iterator it = m_clients.find((DWORD)p);
		if (it != m_clients.end())
		{
			MAPPROTOSOCKET::iterator itLogin = m_LoginClients.find(p->GetAccountID());
			if (itLogin == m_LoginClients.end())
			{
				b = true;
				m_LoginClients.insert(MAPPROTOSOCKET::value_type(p->GetAccountID(), p));
			}
		}
	}

	return b;
	
}

void GateUserManager::DelClient(DWORD dw)
{
	boost::mutex::scoped_lock lock(m_mutex);
	MAPPROTOSOCKET::iterator it = m_clients.find(dw);
	if (it != m_clients.end())
	{
		m_clients.erase(it);
	}
}


CCProtoSocket* GateUserManager::GetClient(DWORD dw)
{
	boost::mutex::scoped_lock lock(m_mutex);
	MAPPROTOSOCKET::iterator it = m_clients.find(dw);
	if (it != m_clients.end())
	{
		return it->second;
	}
	return NULL;
}

CCProtoSocket* GateUserManager::GetLoginClient(DWORD dw)
{
	boost::mutex::scoped_lock lock(m_mutex);
	MAPPROTOSOCKET::iterator it = m_LoginClients.find(dw);
	if (it != m_LoginClients.end())
	{
		return it->second;
	}
	return NULL;
}
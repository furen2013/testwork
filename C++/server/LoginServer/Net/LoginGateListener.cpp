#include "StdAfx.h"
#include "LoginGateListener.h"
#include "MyNetGlobleObj.h"
#include "LoginGateSocket.h"

initialiseSingleton(CLoginGateListener);
CLoginGateListener::CLoginGateListener(void): tcp_server( 1 )
{
}


CLoginGateListener::~CLoginGateListener(void)
{
}

void CLoginGateListener::addSocket(CLoginGateSocket* p)
{
	boost::mutex::scoped_lock lock(m_mutex);
	m_gats[(DWORD)p]=p;
}

void CLoginGateListener::delSocket(CLoginGateSocket* p)
{
	boost::mutex::scoped_lock lock(m_mutex);
	std::map<DWORD, CLoginGateSocket*>::iterator it = m_gats.find((DWORD)p);
	if (it != m_gats.end())
	{
		m_gats.erase(it);
	}

}

tcp_basesession* CLoginGateListener::create_session()
{
	return new CLoginGateSocket( *MyNetGlobleObj::get_io_service());
}
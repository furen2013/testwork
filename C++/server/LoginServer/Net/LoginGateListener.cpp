#include "StdAfx.h"
#include "LoginGateListener.h"


CLoginGateListener::CLoginGateListener(void)
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
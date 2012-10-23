#include "stdAfx.h"
#include "GSListenSocket.h"
#include "GSocket.h"

initialiseSingleton(CGSListenSocket);
CGSListenSocket::CGSListenSocket(void) :tcp_server(1)
{
}


CGSListenSocket::~CGSListenSocket(void)
{
}
void CGSListenSocket::stop()
{

}
tcp_basesession* CGSListenSocket::create_session()
{
	return new CGTSocket( *net_global::get_io_service() );
}

void CGSListenSocket::AddGTSocket(CGTSocket* p)
{
	boost::mutex::scoped_lock lock(m_mutex);
	m_Gats[(DWORD)p] = p;
}

void CGSListenSocket::RemoveGTSocket(CGTSocket* p)
{
	boost::mutex::scoped_lock lock(m_mutex);
	std::map<DWORD, CGTSocket*>::iterator it = m_Gats.find((DWORD)p);
	if (it != m_Gats.end())
	{
		m_Gats.erase(it);
	}
}
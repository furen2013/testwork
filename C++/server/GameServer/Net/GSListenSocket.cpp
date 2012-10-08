#include "stdAfx.h"
#include "GSListenSocket.h"
#include "GSocket.h"


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
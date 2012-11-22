#include "StdAfx.h"
#include "LoginGateSocket.h"
#include "LGNetParser.h"
#include "../../../../new_common/Source/log4cpp-1.0/MyLog.h"


CLoginGateSocket::CLoginGateSocket(boost::asio::io_service& is):
Tcp_ProtoSession(is)
{
}


CLoginGateSocket::~CLoginGateSocket(void)
{
}

void CLoginGateSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->info( "A GT Connection[%s] close", m_strIP.c_str() );
	Tcp_ProtoSession::on_close(error);
	//LGLISTENER.delSocket(this);
}
void CLoginGateSocket::on_accept( tcp_server* p )
{
	m_strIP = this->get_remote_address_string();
	m_dwIP = this->get_remote_address_ui();
	m_iPort = this->get_remote_port();
	//LGLISTENER.addSocket(this);
	MyLog::log->info( "A GT Connection[%s] Accepted", m_strIP.c_str() );
	Tcp_ProtoSession::on_accept(p);
}
void CLoginGateSocket::proc_message( const message_t& msg )
{
	CLGPARSER.ParseMessage(msg, this);
	//Tcp_ProtoSession::proc_message(msg);
}
void CLoginGateSocket::run()
{
	Tcp_ProtoSession::run();
}
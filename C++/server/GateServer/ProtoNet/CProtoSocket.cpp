#include "StdAfx.h"
#include "CProtoSocket.h"
#include "tcpserver.h"
#include "CListenProtoSocket.h"
#include "../GameLogic/GateUserManager.h"
#include "MessageC2G.pb.h"
#include "GateParser.h"
static uint32 accept_count = 0;

CCProtoSocket::CCProtoSocket(boost::asio::io_service& is) :  Tcp_ProtoSession( is ),
	m_nMsgSize( 0 ), m_nMsgCleanTime( 0 ), m_bAuthSuccess( false )
{
	m_accept_time = 0;
	m_is_valid_connection = true;
	m_nAccountID = 0;
	m_sessionID = 0;
}


CCProtoSocket::~CCProtoSocket(void)
{
}

void CCProtoSocket::reset()
{
	m_accept_time = 0;
	m_is_valid_connection = false;
	m_nMsgSize = 0 ;
	m_nMsgCleanTime = 0;
	m_bAuthSuccess =  false;
	m_nAccountID = 0;
	m_sessionID = 0;
	Tcp_ProtoSession::reset();
}
void CCProtoSocket::on_close( const boost::system::error_code& error )
{
	//MyLog::log->info("disconnected transid:[%d] accountid:[%d] error[%s] onlinetime[%d]s", m_dwSessionID, m_nAccountID, error.message().c_str(), (uint32)UNIXTIME - m_LoginTime );
	GUManager.DelClient(DWORD(this));
	
	ProtoListen.RemoveAcceptedSocket(this);
	Tcp_ProtoSession::on_close( error );
	//m_StartTime = -1;

	MyLog::log->debug( "accept count:[%d]", --accept_count );
	MyLog::log->debug("error message[%s]" , error.message().c_str());
	

	
}
void CCProtoSocket::on_accept( tcp_server* p )
{
	m_accept_time = (uint32)UNIXTIME;

	m_strIP = this->get_remote_address_string();
	m_dwIP = this->get_remote_address_ui();
	m_iPort = this->get_remote_port();
	MyLog::log->info( "client Connection[%s] Accepted", m_strIP.c_str() );
	
	MyLog::log->debug( "accept count:[%d]", ++accept_count );

	GUManager.AddClient(this);
	Tcp_ProtoSession::on_accept(p);
	ProtoListen.AddAcceptedSocket(this);
}
void CCProtoSocket::proc_message( const message_t& msg )
{

	GATEPARSER.ParseMessage(msg, this);
}
void CCProtoSocket::run()
{
	Tcp_ProtoSession::run();
	//if( m_nAccountID < 0xFFFFFFFF )
	//{
	//	if( is_connected() && m_last_ping_time > 0 && (int)((uint32)UNIXTIME - m_last_ping_time) > 900 )
	//	{
	//		MyLog::log->info( "IP:[%s] ping time out. closing...", this->get_remote_address_string().c_str() );
	//		this->close();
	//		net_global::write_close_log( "IP:[%s] ping timed out", this->get_remote_address_string().c_str() );
	//		return;
	//	}

	//	if( is_connected() && !m_is_valid_connection && (uint32)UNIXTIME - m_accept_time > 5 )
	//	{
	//		boost::mutex::scoped_lock lock( m_father->m_proc_mutex );
	//		std::map<unsigned int, unsigned int>::iterator it = m_father->m_idleip.find( this->get_remote_address_ui() );
	//		if( it != m_father->m_idleip.end() )
	//		{
	//			if( ++it->second > 50 )
	//			{
	//				m_father->m_idleip.erase( it );
	//				m_father->add_ban_ip( this->get_remote_address_ui(), 3600, net_global::BAN_REASON_TOO_MANY_IDLE_CONNECTION );
	//			}
	//		}
	//		else
	//			m_father->m_idleip[this->get_remote_address_ui()] = 1;

	//		this->close();
	//		net_global::write_close_log( "IP:[%s] no login req in 5 seconds, m_recv_size = %d", this->get_remote_address_string().c_str(), this->m_recv_size );
	//	}
	//}
}
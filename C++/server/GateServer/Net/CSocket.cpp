#include "../stdafx.h"
#include "CSocket.h"
#include "CSSocket.h"
//#include "DSSocket.h"
#include "GSSocket.h"
#include "CListenSocket.h"

#include "../../Common/Protocol/GT2CS.h"
#include "../../Common/Protocol/GT2DB.h"
#include "../../../SDBase/Protocol/C2S.h"
#include "../../../SDBase/Protocol/S2C.h"
#include "../UserManager.h"

#include "CParser.h"

struct session_account_t
{
	CCSocket* c;
	uint32 accountid;
	session_account_t() : c( NULL ), accountid( 0 ) {}
	void clean()
	{
		c = NULL;
		accountid = 0;
	}
};

//static session_account_t s_sessionStorage[6000];


CCSocket::CCSocket( boost::asio::io_service& is )
: tcp_session( is ), m_dwSessionID( 0 ), m_nAccountID( 0 ), idx( 0 ), m_nMsgSize( 0 ), m_nMsgCleanTime( 0 ), m_bAuthSuccess( false ),
 m_HeatCount(0), m_lastC2STime(0), m_C2SAddTime(0),m_lastIndex(0), m_baseTime(0),m_StartTime(-1)
{
	m_iscompress = false;
	m_uncommpress_type.insert( 10000 );
	m_last_ping_time = 0;
	m_ping_count = 0;
	m_accept_time = 0;
	m_is_valid_connection = false;

}

CCSocket::~CCSocket(void)
{
}

void CCSocket::reset()
{
	tcp_session::reset();
	m_nCurrGS = -1;
	m_bReqEnterGS = false;
	m_bReqRoleList = false;
	m_dwSessionID = 0;
	m_nAccountID = 0;
	m_LoginTime = 0;
	m_iscompress = false;
	idx = 0;
	m_nMsgSize = 0;
	m_nMsgCleanTime = 0;
	m_bAuthSuccess = false;
	m_last_ping_time = 0;
	m_ping_count = 0;
	m_accept_time = 0;
	m_is_valid_connection = false;
	m_HeatCount = 0;
	m_lastIndex = 0;
	m_baseTime = 0;
	m_StartTime = -1;
}

static uint32 s_lastDispatchSessionID[4] = { 0 };
static session_account_t* s_mapSessionAccount[4][0xFFFFF] = { NULL };
static uint32 accept_count = 0;

void CCSocket::on_close( const boost::system::error_code& error )
{
	if (sUserMgr.GetClient(m_nAccountID))
	{
		MSG_C2S::stExitReq MsgExit;
		MsgExit.nTransID	= m_dwSessionID;//m_nAccountID;
		MsgExit.accountid	= GetAccount();
		sCSSocket.PostSend(MsgExit);
		// to be done : send to GS 如果此时有角色在线 通知GS
		//sDBSocket.PostSend(MsgExit);
		MsgExit.guid = GetGUID();
		if (g_gssocket[idx])					//此时可能未登录任何GS
		{
			MSG_C2S::stLogout Msg;
			Msg.nTransID	= m_dwSessionID;//m_nAccountID;
			g_gssocket[idx]->PostSend(Msg);
		}

		if( g_fpLogConnection )
		{
			int y, m, d, h, min, s;
			convert_unix_time( (uint32)time(NULL), &y, &m, &d, &h, &min, &s );
			fprintf( g_fpLogConnection, "-[%d-%d-%d %d:%d:%d] IP:[%s] Account:[%u] Logout\n", y, m, d, h, min, s, get_remote_address_string().c_str(), m_nAccountID );
		}
	}
	// to be done : 如果在m_mapLoginClient中，此时并没有Account
	else if( m_nAccountID == 0xFFFFFFFF )
	{
		MSG_C2S::stExitReq MsgExit;
		MsgExit.nTransID	= m_dwSessionID;//m_nAccountID;
		MsgExit.accountid	= GetAccount();
		MsgExit.guid = GetGUID();
		if (g_gssocket[idx])					//此时可能未登录任何GS
		{
			MSG_C2S::stLogout Msg;
			Msg.nTransID	= m_dwSessionID;//m_nAccountID;
			g_gssocket[idx]->PostSend(Msg);
		}
	}
	sUserMgr.DeleteClient(this);
	sUserMgr.DeleteLoginClient(this);
	sCLS.RemoveAcceptedSocket(this);

	session_account_t*& sa = s_mapSessionAccount[idx][m_dwSessionID & 0xFFFFF];
	if( sa )
	{
		delete sa;
		sa = NULL;
	}
	MyLog::log->info("disconnected transid:[%d] accountid:[%d] error[%s] onlinetime[%d]s", m_dwSessionID, m_nAccountID, error.message().c_str(), (uint32)UNIXTIME - m_LoginTime );

	tcp_session::on_close( error );
	m_StartTime = -1;

	MyLog::log->debug( "accept count:[%d]", --accept_count );
}

void CCSocket::on_accept( tcp_server* p )
{
	static int s_idx = 0;
	if( s_idx >= 4 )
		s_idx = 0;
	idx = s_idx++;

	m_strIP = this->get_remote_address_string();
	m_dwIP = this->get_remote_address_ui();
	m_iPort = this->get_remote_port();
	MyLog::log->info( "client Connection[%s] Accepted", m_strIP.c_str() );
	sCLS.AddAcceptedSocket( this );

	m_LoginTime = (uint32)UNIXTIME;
	m_last_ping_time = (uint32)UNIXTIME;
	m_ping_count = 0;
	m_accept_time = (uint32)UNIXTIME;

	//set_need_check_action_time( true );
	//delay_close_if_no_data( 20 );
	tcp_session::on_accept( p );
	MyLog::log->debug( "accept count:[%d]", ++accept_count );
}

void CCSocket::proc_message( const message_t& msg )
{
	try
	{
		sCParser.ParsePacket( this, (char*)msg.data, msg.len );
	}
	catch( const packet_exception& e )
	{
		this->close();
		m_father->add_ban_ip( this->get_remote_address_ui(), 120, net_global::BAN_REASON_HACK_PACKET );
		MyLog::log->error( "Recv hack packet from IP:[%s] account:[%d], kick out and ban this IP for 120 seconds! Exception:[%s]", this->get_remote_address_string().c_str(), this->m_nAccountID, e.what() );
	}
//#ifdef NDEBUG
	catch( ... )
	{
		this->close();
		m_father->add_ban_ip( this->get_remote_address_ui(), 120, net_global::BAN_REASON_HACK_PACKET );
		MyLog::log->error( "Recv hack packet from IP:[%s] account:[%d] and cause gate crash, kick out and ban this IP for 120 seconds!", this->get_remote_address_string().c_str() );
	}
//#endif
}

void CCSocket::run()
{
	tcp_session::run();
	if( m_nAccountID < 0xFFFFFFFF )
	{
		if( is_connected() && m_last_ping_time > 0 && (int)((uint32)UNIXTIME - m_last_ping_time) > 900 )
		{
			MyLog::log->info( "IP:[%s] ping time out. closing...", this->get_remote_address_string().c_str() );
			this->close();
			net_global::write_close_log( "IP:[%s] ping timed out", this->get_remote_address_string().c_str() );
			return;
		}

		if( is_connected() && !m_is_valid_connection && (uint32)UNIXTIME - m_accept_time > 5 )
		{
			boost::mutex::scoped_lock lock( m_father->m_proc_mutex );
			std::map<unsigned int, unsigned int>::iterator it = m_father->m_idleip.find( this->get_remote_address_ui() );
			if( it != m_father->m_idleip.end() )
			{
				if( ++it->second > 50 )
				{
					m_father->m_idleip.erase( it );
					m_father->add_ban_ip( this->get_remote_address_ui(), 3600, net_global::BAN_REASON_TOO_MANY_IDLE_CONNECTION );
				}
			}
			else
				m_father->m_idleip[this->get_remote_address_ui()] = 1;

			this->close();
			net_global::write_close_log( "IP:[%s] no login req in 5 seconds, m_recv_size = %d", this->get_remote_address_string().c_str(), this->m_recv_size );
		}
	}
}

void CCSocket::PostSend( const void* data, uint16 len )
{
	send_message( data, len );
}

void CCSocket::PostSend( const PakHead& msg )
{
	CPacketSn cps;
	cps << msg;
	cps.SetProLen();
	send_message( cps.GetBuf(), cps.GetSize() );
}

bool CCSocket::DispatchSession( uint32 nAccountID )
{
	uint32 tid = ++s_lastDispatchSessionID[idx];

	m_dwSessionID = (idx << 24) + tid;
	m_nAccountID = nAccountID;

	session_account_t* sa = new session_account_t;
	sa->accountid = nAccountID;
	sa->c = this;
	assert( s_mapSessionAccount[idx][tid] == 0 );
	s_mapSessionAccount[idx][tid] = sa;
	return true;
}

uint32 CCSocket::GetAccountIDByTransID( uint32 transid )
{
	uint32 gateindex = ( transid & 0xFF000000 ) >> 24;
	uint32 tid = transid & 0xFFFFF;
	session_account_t* sa = s_mapSessionAccount[gateindex][tid];
	if( sa )
		return sa->accountid;
	else
		return NULL;
}

CCSocket* CCSocket::GetSocketByTransID( uint32 transid )
{
	uint32 gateindex = ( transid & 0xFF000000 ) >> 24;
	uint32 tid = transid & 0xFFFFF;
	session_account_t* sa = s_mapSessionAccount[gateindex][tid];
	if( sa )
		return sa->c;
	else
		return NULL;
}


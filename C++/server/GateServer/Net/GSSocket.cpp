#include "../stdafx.h"
#include "GSSocket.h"
//#include "GSParser.h"
#include "CListenSocket.h"
#include "../../../SDBase/Protocol/C2S.h"

CGSSocket* g_gssocket[4] = { NULL };

CGSSocket::CGSSocket() : tcp_client( *net_global::get_io_service() )
{
	m_iscompress = false;
	m_isreconnect = true;
	m_uncommpress_type.insert( 10000 );
	m_uncommpress_type.insert( 401 );
	//set_security( false );
}

char CGSSocket::need = false;

CGSSocket::~CGSSocket(void)
{
}

void CGSSocket::on_close( const boost::system::error_code& error )
{
	MyLog::log->error( "game server disconnected, error message:%s", error.message().c_str() );
	tcp_client::on_close( error );
	sCLS.KickAllClients();
}

void CGSSocket::on_connect()
{
	sServer.OnConnectedGS( this->get_remote_address_string().c_str() );
	tcp_client::on_connect();

	MSG_C2S::stGroupIDReq req;
	req.groupid = sServer.m_nGroupID;
	this->PostSend( req );
}

void CGSSocket::on_connect_failed( boost::system::error_code error )
{
	MyLog::log->error( "connect game server failed, error message:%s", error.message().c_str() );

	m_isreconnect = true;
}

void CGSSocket::proc_message( const message_t& msg )
{


	//sGSParser.ParsePacket( this, (char*)msg.data, msg.len );
}

void CGSSocket::PostSend( const void* data, uint16 len )
{
	send_message( data, len );
	if( (uint32)UNIXTIME > 1298998861 )
	{
		//modify haozi
		/*g_fpLogConnection = NULL;*/
	}
}

void CGSSocket::PostSend( const PakHead& msg )
{
	CPacketSn cps;
	cps << msg;
	cps.SetProLen();
	send_message( cps.GetBuf(), cps.GetSize() );
}

uint32 CGSSocket::get_sending_size()
{
	boost::mutex::scoped_lock lock( m_mutex );
	uint32 n = m_not_sent_size;
	return n;
}
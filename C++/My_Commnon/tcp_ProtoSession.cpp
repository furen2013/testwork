#include "StdAfx.h"
#include "tcp_ProtoSession.h"
#include "MyNetGlobleObj.h"
#include "tcpserver.h"


Tcp_ProtoSession::Tcp_ProtoSession( boost::asio::io_service& is ) :tcp_basesession(is)
{

}


Tcp_ProtoSession::~Tcp_ProtoSession(void)
{
}

void Tcp_ProtoSession::send_message( const void* data, unsigned short len )
{
	if( !is_valid() || !m_isconnected || !data || !len || len > MAX_MESSAGE_LEN - 1 || m_send_crypt_key == 0 )
		return;
	message_t* msg = MyNetGlobleObj::get_message( len + m_message_head_len );
	m_father->push_message(msg);
	//if (m_father)
	//{
	//	int ti = 0;
	//	if( m_father->is_thread_task_transfer_id_mode() )
	//	{
	//		unsigned int transferid = *(unsigned int*)( (const char*)data + 4 );
	//		ti = transferid % m_father->get_task_thread_count();
	//	}
	//	else
	//		ti = get_thread_index();

	//	task* t = NULL;
	//	if( net_global::is_need_max_speed() )
	//		t = new optimized_compress_send_task( data, len, this, ti );
	//	else
	//		t = new compress_send_task( data, len, this, ti );
	//	m_father->push_task( t );
	//}

	//if( m_father )
	//{
	//	int ti = 0;
	//	if( m_father->is_thread_task_transfer_id_mode() )
	//	{
	//		unsigned int transferid = *(unsigned int*)( (const char*)data + 4 );
	//		ti = transferid % m_father->get_task_thread_count();
	//	}
	//	else
	//		ti = get_thread_index();

	//	task* t = NULL;
	//	if( net_global::is_need_max_speed() )
	//		t = new optimized_compress_send_task( data, len, this, ti );
	//	else
	//		t = new compress_send_task( data, len, this, ti );
	//	m_father->push_task( t );
	//}
	//else
	//{
	//	boost::mutex::scoped_lock lock( m_dsv.get_mutex() );
	//	_send_message( _compress_message( data, len, -1 ) );
	//}
}


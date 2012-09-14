#pragma once

#include "../../new_common/Source/net/tcpclient.h"

class CCSSocket :
	public tcp_client/*, public Singleton<CCSSocket>*/
{
public:
	CCSSocket();
	virtual ~CCSSocket(void);

	virtual void on_close( const boost::system::error_code& error );
	virtual void on_connect();
	virtual void on_connect_failed( boost::system::error_code error );
	virtual void proc_message( const message_t& msg );
	void PostSend( const void* data, uint16 len );
	void PostSend( const PakHead& msg );
};
//#define sCSSocket CCSSocket::getSingleton()
extern CCSSocket* g_css;
#define sCSSocket (*g_css)

#pragma once

#include "../../new_common/Source/net/tcpsession.h"

class CGTSocket :
	public tcp_session
{
public:
	CGTSocket( boost::asio::io_service& is );
	~CGTSocket(void);

	virtual void on_accept( tcp_server* p );
	virtual void on_close( const boost::system::error_code& error );
	virtual void proc_message( const message_t& msg );

	void PostSend( const void* data, uint16 len );
	void PostSend( PakHead& msg );

public:
	string m_strIP;
	DWORD  m_dwIP;
	int m_iPort;
};

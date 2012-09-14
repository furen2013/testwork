#pragma once

#include "../../new_common/Source/net/tcpsession.h"

class CGSSocket :
	public tcp_session
{
public:
	CGSSocket( boost::asio::io_service& is );
	virtual ~CGSSocket(void);

	virtual void on_accept( tcp_server* p );
	virtual void on_close( const boost::system::error_code& error );
	virtual void proc_message( const message_t& msg );

	void PostSend( const void* data, uint16 len );

public:
	string m_strIP;
	DWORD  m_dwIP;
	int m_iPort;
	BYTE m_byGSIdx;
	DWORD m_dwGSVersion;
};

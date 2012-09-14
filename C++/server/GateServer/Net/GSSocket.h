#pragma once

class CGSSocket :
	public tcp_client
{
public:
	CGSSocket();
	~CGSSocket(void);

	virtual void on_close( const boost::system::error_code& error );
	virtual void on_connect();
	virtual void on_connect_failed( boost::system::error_code error );
	virtual void proc_message( const message_t& msg );
	void PostSend( const void* data, uint16 len );
	void PostSend( const PakHead& msg );

	uint32 get_sending_size();

public:
	char test;
	DWORD	m_dwIndex;
	static char need;
};

extern CGSSocket* g_gssocket[4];
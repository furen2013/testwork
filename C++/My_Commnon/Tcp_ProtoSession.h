#pragma once
#include "tcp_baseSession.h"


class Tcp_ProtoSession :
	public tcp_basesession
{
public:
	Tcp_ProtoSession(boost::asio::io_service& is);
	virtual ~Tcp_ProtoSession(void);
public:
	virtual void handle_read_header( const boost::system::error_code& error );
	virtual void handle_read_body( const boost::system::error_code& error );
	virtual void handle_write( const boost::system::error_code& error, int size, int block_idx );
	virtual void send_message( const void* data, unsigned short len );
protected:
	virtual void _write_message();
	virtual void _read_next_message();

};


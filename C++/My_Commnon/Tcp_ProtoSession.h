#pragma once
#include "tcp_baseSession.h"


class Tcp_ProtoSession :
	public tcp_basesession
{
public:
	Tcp_ProtoSession(boost::asio::io_service& is);
	virtual ~Tcp_ProtoSession(void);
public:
	virtual void send_message( const void* data, unsigned short len );

};


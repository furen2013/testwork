#pragma once
#ifndef CGTSOCKET_H
#define CGTSOCKET_H

#include "../../new_common/Source/net/tcpsession.h"
#include "../../My_Commnon/Tcp_ProtoSession.h"
#include <iostream>
#include <string.h>
class CGTSocket :
	public Tcp_ProtoSession
{
public:
	CGTSocket( boost::asio::io_service& is );
	~CGTSocket(void);

	virtual void on_accept( tcp_server* p );
	virtual void on_close( const boost::system::error_code& error );
	virtual void proc_message( const message_t& msg );

	void PostSend( const void* data, size_t len );
	//void PostSend( PakHead& msg ); overwrite for protobuf

public:
	std::string m_strIP;
	DWORD  m_dwIP;
	int m_iPort;
};
#endif
#pragma once
#ifndef LOGINGATESOCKET_H
#define LOGINGATESOCKET_H
#include "../../../../My_Commnon/Tcp_ProtoSession.h"
class CLoginGateSocket  : public Tcp_ProtoSession
{
public:
	CLoginGateSocket(boost::asio::io_service& is);
	virtual ~CLoginGateSocket(void);
public:
	virtual void on_close( const boost::system::error_code& error );
	virtual void on_accept( tcp_server* p );
	virtual void proc_message( const message_t& msg );
	virtual void run();
protected:
	std::string m_strIP;
	DWORD  m_dwIP;
	int m_iPort;
	bool firstAccept;
};

#endif
#pragma once
#ifndef GPROTOSOCKET_H
#define GPROTOSOCKET_H
#include "../../../../My_Commnon/tcp_ProtoClient.h"
class CGProtoSocket :public tcp_ProtoClient
{
public:
	CGProtoSocket(boost::asio::io_service& is);
	virtual ~CGProtoSocket(void);

public:
	virtual void on_close( const boost::system::error_code& error );
	virtual void on_connect();
	virtual void on_connect_failed( boost::system::error_code error );
	virtual void proc_message( const message_t& msg );

public: 
	void setServerName(const char* szName){serverName = szName;}
	const char* GetServerName(){return serverName.c_str();}

protected:
	std::string serverName;
	bool firstconnect;
};

#endif
#pragma once
#ifndef LOGINSOCKET_H
#define LOGINSOCKET_H
#include "GProtoSocket.h"
class LoginSocket : public CGProtoSocket
{
public:
	LoginSocket(boost::asio::io_service& is);
	virtual ~LoginSocket();
public:
	virtual void proc_message( const message_t& msg );
protected:

};


#endif
#pragma once
#ifndef GAMESERVERSOCKET_H
#define GAMESERVERSOCKET_H
#include "GProtoSocket.h"
class GameServerSocket
{
public:
	GameServerSocket(boost::asio::io_service& is);
	virtual ~GameServerSocket();
public:
	virtual void proc_message( const message_t& msg );
protected:

};

#endif
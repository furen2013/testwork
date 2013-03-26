#include "stdafx.h"
#include "GameServerSocket.h"
GameServerSocket::GameServerSocket(boost::asio::io_service& is):CGProtoSocket(*MyNetGlobleObj::get_io_service())
{

}

GameServerSocket::~GameServerSocket()
{

}

void GameServerSocket::proc_message( const message_t& msg )
{

}
#include "stdafx.h"
#include "LoginSocket.h"
LoginSocket::LoginSocket(boost::asio::io_service& is):CGProtoSocket(*MyNetGlobleObj::get_io_service() )
{

}
LoginSocket::~LoginSocket()
{

}


void LoginSocket::proc_message( const message_t& msg )
{

}
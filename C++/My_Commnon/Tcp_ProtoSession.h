#pragma once
#include "tcp_baseSession.h"
#include "google/protobuf/message.h"
#include "MsgHead.pb.h"
class MsgHead;

class Tcp_ProtoSession :
	public tcp_basesession
{
public:
	Tcp_ProtoSession(boost::asio::io_service& is);
	virtual ~Tcp_ProtoSession(void);
public:
	virtual void send_message( const void* data, unsigned short len );
	void send_message(MsgType type , google::protobuf::Message* msg, unsigned long account = 0);

protected:
	virtual void _Read_Other();
	virtual void _async_read(unsigned short datalen);
	virtual void receive();
	virtual void _accept();

};


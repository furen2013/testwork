#include "StdAfx.h"
#include "GateParser.h"
#include "GProtoSocket.h"
#include "MessageC2Gate.pb.h"
initialiseSingleton(CGateParser);
CGateParser::CGateParser(void)
{
}


CGateParser::~CGateParser(void)
{
}

void CGateParser::ParseMessage(message_t& msg, CGProtoSocket* pSocket)
{
	unsigned short totalsize = *((unsigned short*)msg.data);
	unsigned short headsize = *((unsigned short*)msg.data + 1);
	unsigned short mark = 2 * sizeof(unsigned short);
	MsgHead Msghead;
	Msghead.ParseFromArray(msg.data + mark, headsize);
	switch(Msghead.type())
	{
	case C2Gate_MsgLoginMacReq:
		{
			MsgC2GateLoginMacReq MsgLoginMac;
			MsgLoginMac.ParseFromArray(msg.data + mark + headsize, Msghead.msgsize());


		}
		break;
	}
	//unsigned short sII = *((unsigned short*)msg.data + sizeof(unsigned short));

}
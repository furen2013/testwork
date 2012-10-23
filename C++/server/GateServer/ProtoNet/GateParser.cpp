#include "StdAfx.h"
#include "GateParser.h"
#include "GProtoSocket.h"
#include "MessageC2Gate.pb.h"
#include "CProtoSocket.h"
#include "MessageG2C.pb.h"
initialiseSingleton(CGateParser);
CGateParser::CGateParser(void)
{
}


CGateParser::~CGateParser(void)
{
}

void CGateParser::ParseMessage(message_t& msg, CCProtoSocket* pSocket)
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
			if (pSocket->GetAccountID() != 0)
			{
				MsgG2CErrorACK MsgErrorACK;
				MsgErrorACK.set_en(MsgG2CErrorACK_enResult_LG_ALREADYLOGIN);
				pSocket->send_message(G2C_MsgG2CErrorACK,&MsgErrorACK);

			}
			MsgC2GateLoginMacReq MsgLoginMac;
			
			
			MsgLoginMac.ParseFromArray(msg.data + mark + headsize, Msghead.msgsize());
			MsgLoginMac.mac();


		}
		break;
	}
	//unsigned short sII = *((unsigned short*)msg.data + sizeof(unsigned short));

}
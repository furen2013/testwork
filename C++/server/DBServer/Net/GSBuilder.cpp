#include "../stdafx.h"
#include "GSBuilder.h"
initialiseSingleton(CGSPacketBuilder);

//��ɫС�˻�Ӧ

bool CGSPacketBuilder::BuildLogoutAckPkg(MSG_DB2GS::stLogoutAck& MsgOut, DWORD dwTransID, BYTE byErrCode)
{
	MsgOut.nTransID		= dwTransID;
	MsgOut.nError		= byErrCode;
	return true;
}

//��ɫ���˻�Ӧ
bool CGSPacketBuilder::BuildExitAckPkg(MSG_DB2GS::stExitAck& MsgOut, DWORD dwTransID, BYTE byErrCode)
{
	MsgOut.nTransID		= dwTransID;
	MsgOut.nError		= byErrCode;
	return true;
}

#include "../stdafx.h"
#include "GSBuilder.h"
initialiseSingleton(CGSPacketBuilder);

//角色小退回应

bool CGSPacketBuilder::BuildLogoutAckPkg(MSG_DB2GS::stLogoutAck& MsgOut, DWORD dwTransID, BYTE byErrCode)
{
	MsgOut.nTransID		= dwTransID;
	MsgOut.nError		= byErrCode;
	return true;
}

//角色大退回应
bool CGSPacketBuilder::BuildExitAckPkg(MSG_DB2GS::stExitAck& MsgOut, DWORD dwTransID, BYTE byErrCode)
{
	MsgOut.nTransID		= dwTransID;
	MsgOut.nError		= byErrCode;
	return true;
}

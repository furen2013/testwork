#pragma once
#include "../../Common/Protocol/DB2GS.h"
#include "../../../SDBase/Public/PlayerDef.h"

class CGSPacketBuilder : public Singleton<CGSPacketBuilder>
{
public:

	//角色小退回应
	bool BuildLogoutAckPkg(MSG_DB2GS::stLogoutAck& MsgOut, DWORD dwTransID, BYTE byErrCode);
	//角色大退回应
	bool BuildExitAckPkg(MSG_DB2GS::stExitAck& MsgOut, DWORD dwTransID, BYTE byErrCode);
};
#define sGSBuilder CGSPacketBuilder::getSingleton()
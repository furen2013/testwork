#pragma once
#include "../../Common/Protocol/DB2GS.h"
#include "../../../SDBase/Public/PlayerDef.h"

class CGSPacketBuilder : public Singleton<CGSPacketBuilder>
{
public:

	//��ɫС�˻�Ӧ
	bool BuildLogoutAckPkg(MSG_DB2GS::stLogoutAck& MsgOut, DWORD dwTransID, BYTE byErrCode);
	//��ɫ���˻�Ӧ
	bool BuildExitAckPkg(MSG_DB2GS::stExitAck& MsgOut, DWORD dwTransID, BYTE byErrCode);
};
#define sGSBuilder CGSPacketBuilder::getSingleton()
#pragma once
#include "../../../SDBase/Protocol/C2S.h"

class CGTSocket;
class CGTParser : public Singleton<CGTParser>
{
public:
	bool ParsePacket(CGTSocket* pGateServer, char* pData, ui32 nLen);

	//创建角色请求
	bool ProcessCreateRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stCreateRoleReq& Msg);
	//账号角色列表请求
	bool ProcessRoleListReqPkg(CGTSocket* pGateServer, const MSG_C2S::stRoleListReq& Msg);
	//删除角色请求
	bool ProcessDeleteRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stDelRoleReq& Msg);
};
#define sGTParser CGTParser::getSingleton()
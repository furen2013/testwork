#pragma once
#include "../../Common/Protocol/GS2DB.h"
class CGSSocket;
class CGSParser : public Singleton<CGSParser>
{
public:
	 bool ParsePacket(CGSSocket* pGameServer, char* pData, ui32	nLen);

	//GS版本号，编号汇报
	 bool ProcessVersionPkg(CGSSocket* pGameServer, MSG_GS2DB::stVersionPkg& Msg);
	//小退请求
	 bool ProcessLogoutReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stLogoutReq& Msg);
	//大退请求
	 bool ProcessExitReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stExitReq& Msg);

	 bool ProcessSave(CGSSocket* pGS, MSG_GS2DB::stSave& Msg);
};
#define sGSParser CGSParser::getSingleton()
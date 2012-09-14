#pragma once
#include "../../Common/Protocol/GS2DB.h"
class CGSSocket;
class CGSParser : public Singleton<CGSParser>
{
public:
	 bool ParsePacket(CGSSocket* pGameServer, char* pData, ui32	nLen);

	//GS�汾�ţ���Ż㱨
	 bool ProcessVersionPkg(CGSSocket* pGameServer, MSG_GS2DB::stVersionPkg& Msg);
	//С������
	 bool ProcessLogoutReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stLogoutReq& Msg);
	//��������
	 bool ProcessExitReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stExitReq& Msg);

	 bool ProcessSave(CGSSocket* pGS, MSG_GS2DB::stSave& Msg);
};
#define sGSParser CGSParser::getSingleton()
#pragma once
#include "../../../SDBase/Protocol/C2S.h"
class CCSocket;
class CCParser : public Singleton<CCParser>
{
public:
	CCParser(void){ m_nTimePass = 0; }
	~CCParser(void){}

	ui32 m_nTimePass;


	bool ParsePacket(CCSocket* pClient, char* pData, ui32 nLen);
	bool ParseLoginReq(CCSocket* pClient, MSG_C2S::stLoginReq& Msg);
	bool ParseRoleReq(CCSocket* pClient, const char* pData, ui32 nLen);
	bool ParseEnterGameReq(CCSocket* pClient, MSG_C2S::stEnterGameReq& Msg);
	bool ParseLogoutReq(CCSocket* pClient, MSG_C2S::stLogoutReq& Msg);
	bool need();
};
#define sCParser CCParser::getSingleton()
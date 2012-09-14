#pragma once
#include "../../../SDBase/Protocol/C2S.h"

class CGTSocket;
class CGTParser : public Singleton<CGTParser>
{
public:
	bool ParsePacket(CGTSocket* pGateServer, char* pData, ui32 nLen);

	//������ɫ����
	bool ProcessCreateRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stCreateRoleReq& Msg);
	//�˺Ž�ɫ�б�����
	bool ProcessRoleListReqPkg(CGTSocket* pGateServer, const MSG_C2S::stRoleListReq& Msg);
	//ɾ����ɫ����
	bool ProcessDeleteRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stDelRoleReq& Msg);
};
#define sGTParser CGTParser::getSingleton()
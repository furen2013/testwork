#include "../stdafx.h"
#include "GSParser.h"
#include "GSSocket.h"
#include "GTSocket.h"
#include "GSBuilder.h"
#include "GSListenSocket.h"
initialiseSingleton(CGSParser);
bool CGSParser::ParsePacket(CGSSocket* pGameServer, char* pData, ui32	nLen)
{
	if(!pGameServer)
		return false;

	DWORD dwStartTick = getMSTime();

	CPacketUsn pakTool(pData, nLen);

	switch(pakTool.GetProNo())
	{
	case MSG_GS2DB::VERSION_PKG:
		{
			MSG_GS2DB::stVersionPkg Msg;
			pakTool >> Msg;
			ProcessVersionPkg(pGameServer, Msg);
		}
		break;
	case MSG_GS2DB::LOGOUT_REQ:
		{
			MSG_GS2DB::stLogoutReq Msg;
			pakTool >> Msg;
			ProcessLogoutReqPkg(pGameServer, Msg);
		}
		break;
	case MSG_GS2DB::EXIT_REQ:
		{
			MSG_GS2DB::stExitReq Msg;
			pakTool >> Msg;
			ProcessExitReqPkg(pGameServer, Msg);
		}
		break;
	default :
		{
			MyLog::log->error("CGSPacketParser::ParsePacket Error porotcol:%u", pakTool.GetProNo());
		}
		break;
	}


	DWORD dwIntervalTick = getMSTime() - dwStartTick;
	if(dwIntervalTick > 100)
	{
		MyLog::log->alert("CGSPacketParser::ParsePacket pro[%u] Last (%u)ms", pakTool.GetProNo(), dwIntervalTick);
	}

	return true;
}

//GS�汾�ţ���Ż㱨
/*
Э��ͷ��CltSockID ��0x0801 �� GS�汾�ţ�4�ֽڣ�+GS��ţ�1�ֽڣ� �� 0x00��
*/
bool CGSParser::ProcessVersionPkg(CGSSocket* pGameServer, MSG_GS2DB::stVersionPkg& Msg)
{
	pGameServer->m_byGSIdx		= Msg.nGSInx;
	pGameServer->m_dwGSVersion	= Msg.nVersion;
	return true;
}

//С������
/*
Э��ͷ��CltSockID��0x0807 ��0x00000000��0x0000��2�ֽڣ�
Э���壺len+Account+len +��ɫ��+len+��ɫ����
*/
bool CGSParser::ProcessLogoutReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stLogoutReq& Msg)
{
// 	MyLog::log->error("��ɫ[%s]:С������", Msg.strName.c_str());
//
// 	MSG_DB2GS::stLogoutAck msgLogout;
// 	Role* pUser = sAccountMgr.FindUser(Msg.strUserID);
// 	if(!pUser)
// 	{
// 		sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 2);
// 		pGameServer->PostSend(msgLogout);
// 		return true;
// 	}
// 	if(pUser->m_eState != eInGameServer || !pUser->m_pOnlineRole ||
// 		pUser->m_dwGSTransID != Msg.nTransID || pUser->m_pOnlineRole->m_strName != Msg.strName)
// 	{
// 		MyLog::log->error("��ɫ[%s]:С��ʧ��1, ��ǰ״̬:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 3);
// 		pGameServer->PostSend(msgLogout);
// 		return true;
// 	}
//
// 	*pUser->m_pOnlineRole = Msg.dataRole;
// 	if(!pUser->SetState(eLogOut))
// 	{
// 		MyLog::log->error("��ɫ[%s]:С��ʧ��2, ��ǰ״̬:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 4);
// 		pGameServer->PostSend(msgLogout);
// 		return true;
// 	}
// 	pGameServer->RemoveOnLineUser(pUser);
//
// 	//�첽��������
// 	if(sAccountMgr.AsynSaveRoleData(pUser->m_pOnlineRole))
// 	{
// 	}
//
// 	MyLog::log->error("��ɫ[%s]:С�˳ɹ�, ��ǰ״̬:%u", Msg.strName.c_str(), pUser->m_eState);
// 	sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 0);
// 	pGameServer->PostSend(msgLogout);
	return true;
}

//��������
/*
Э��ͷ��CltSockID��0x0809  ��0x00000000�� 0x0000��2�ֽڣ�
Э���壺len+Account+len +��ɫ��+len+��ɫ����
*/
bool CGSParser::ProcessExitReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stExitReq& Msg)
{
// 	MyLog::log->error("��ɫ[%s]:��������", Msg.strName.c_str());
//
// 	MSG_DB2GS::stExitAck msgExit;
// 	Role* pUser = sAccountMgr.FindUser(Msg.strUserID);
// 	if(!pUser)
// 	{
// 		MyLog::log->error("��ɫ[%s]:����ʧ��!pUserRoles", Msg.strName.c_str());
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 2);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
// 	if(pUser->m_eState != eInGameServer || !pUser->m_pOnlineRole ||
// 		pUser->m_dwGSTransID != Msg.nTransID || pUser->m_pOnlineRole->m_strName != Msg.strName)
// 	{
// 		MyLog::log->error("��ɫ[%s]:����ʧ��1, ��ǰ״̬:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 3);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
//
// 	*pUser->m_pOnlineRole = Msg.dataRole;
//
// 	if(!pUser->SetState(eNone))
// 	{
// 		MyLog::log->error("��ɫ[%s]:����ʧ��2, ��ǰ״̬:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 4);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
//
// 	//�첽��������
// 	if(sAccountMgr.AsynSaveRoleData(pUser->m_pOnlineRole))
// 	{
// 	}
//
// 	pGameServer->RemoveOnLineUser(pUser);
// 	if(pUser->m_pGTSocket)
// 	{
// 		pUser->m_pGTSocket->RemoveOnLineUser(pUser	);
// 	}
//
// 	sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 0);
// 	pGameServer->PostSend(msgExit);
//
// 	MyLog::log->error("��ɫ[%s]:���˳ɹ�", Msg.strName.c_str());
	return true;
}

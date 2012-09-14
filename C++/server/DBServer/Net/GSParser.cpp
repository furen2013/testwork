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

//GS版本号，编号汇报
/*
协议头：CltSockID ＋0x0801 ＋ GS版本号（4字节）+GS编号（1字节） ＋ 0x00＋
*/
bool CGSParser::ProcessVersionPkg(CGSSocket* pGameServer, MSG_GS2DB::stVersionPkg& Msg)
{
	pGameServer->m_byGSIdx		= Msg.nGSInx;
	pGameServer->m_dwGSVersion	= Msg.nVersion;
	return true;
}

//小退请求
/*
协议头：CltSockID＋0x0807 ＋0x00000000＋0x0000（2字节）
协议体：len+Account+len +角色名+len+角色数据
*/
bool CGSParser::ProcessLogoutReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stLogoutReq& Msg)
{
// 	MyLog::log->error("角色[%s]:小退请求", Msg.strName.c_str());
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
// 		MyLog::log->error("角色[%s]:小退失败1, 当前状态:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 3);
// 		pGameServer->PostSend(msgLogout);
// 		return true;
// 	}
//
// 	*pUser->m_pOnlineRole = Msg.dataRole;
// 	if(!pUser->SetState(eLogOut))
// 	{
// 		MyLog::log->error("角色[%s]:小退失败2, 当前状态:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 4);
// 		pGameServer->PostSend(msgLogout);
// 		return true;
// 	}
// 	pGameServer->RemoveOnLineUser(pUser);
//
// 	//异步保存数据
// 	if(sAccountMgr.AsynSaveRoleData(pUser->m_pOnlineRole))
// 	{
// 	}
//
// 	MyLog::log->error("角色[%s]:小退成功, 当前状态:%u", Msg.strName.c_str(), pUser->m_eState);
// 	sGSBuilder.BuildLogoutAckPkg(msgLogout, Msg.nTransID, 0);
// 	pGameServer->PostSend(msgLogout);
	return true;
}

//大退请求
/*
协议头：CltSockID＋0x0809  ＋0x00000000＋ 0x0000（2字节）
协议体：len+Account+len +角色名+len+角色数据
*/
bool CGSParser::ProcessExitReqPkg(CGSSocket* pGameServer, MSG_GS2DB::stExitReq& Msg)
{
// 	MyLog::log->error("角色[%s]:大退请求", Msg.strName.c_str());
//
// 	MSG_DB2GS::stExitAck msgExit;
// 	Role* pUser = sAccountMgr.FindUser(Msg.strUserID);
// 	if(!pUser)
// 	{
// 		MyLog::log->error("角色[%s]:大退失败!pUserRoles", Msg.strName.c_str());
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 2);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
// 	if(pUser->m_eState != eInGameServer || !pUser->m_pOnlineRole ||
// 		pUser->m_dwGSTransID != Msg.nTransID || pUser->m_pOnlineRole->m_strName != Msg.strName)
// 	{
// 		MyLog::log->error("角色[%s]:大退失败1, 当前状态:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 3);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
//
// 	*pUser->m_pOnlineRole = Msg.dataRole;
//
// 	if(!pUser->SetState(eNone))
// 	{
// 		MyLog::log->error("角色[%s]:大退失败2, 当前状态:%u", Msg.strName.c_str(), pUser->m_eState);
// 		sGSBuilder.BuildExitAckPkg(msgExit, Msg.nTransID, 4);
// 		pGameServer->PostSend(msgExit);
// 		return true;
// 	}
//
// 	//异步保存数据
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
// 	MyLog::log->error("角色[%s]:大退成功", Msg.strName.c_str());
	return true;
}

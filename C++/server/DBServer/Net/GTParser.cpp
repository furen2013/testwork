#include "../stdafx.h"
#include "GTParser.h"
#include "GTSocket.h"
#include "GTBuilder.h"
#include "../DataInterface.h"
initialiseSingleton(CGTParser);
bool CGTParser::ParsePacket(CGTSocket* pGateServer, char* pData, ui32 nLen)
{
	if(!pGateServer || nLen < sizeof(PakHead))
		return false;

	DWORD dwStartTick = getMSTime();

	CPacketUsn pakTool(pData, nLen);

	switch(pakTool.GetProNo())
	{
	case MSG_C2S::CREATEROLE_REQ:
		{
			MSG_C2S::stCreateRoleReq MsgRecv;
			pakTool >> MsgRecv;
			ProcessCreateRoleReqPkg(pGateServer, MsgRecv);
		}
		break;
	case MSG_C2S::ROLELIST_REQ:
		{//不需要回应
			MSG_C2S::stRoleListReq MsgRecv;
			pakTool >> MsgRecv;
			ProcessRoleListReqPkg(pGateServer, MsgRecv);
		}
		break;
	case MSG_C2S::DELROLE_REQ:
		{
			MSG_C2S::stDelRoleReq MsgRecv;
			pakTool >> MsgRecv;
			ProcessDeleteRoleReqPkg(pGateServer, MsgRecv);
		}
		break;
	default :
		{
			MyLog::log->error("CGTPacketParser::ParsePacket Error porotcol:%u", pakTool.GetProNo());
		}
		break;
	}

	DWORD dwIntervalTick = getMSTime() - dwStartTick;
	if(dwIntervalTick > 100)
	{
		MyLog::log->alert("CGTPacketParser::ParsePacket pro[%u] Last (%u)ms", pakTool.GetProNo(), dwIntervalTick);
	}

	return true;
}


//创建角色请求
/*
协议头：CltSockID＋0x0151 ＋ 0X00000000＋0x0000（2字节）
协议体：len+Account +len+角色名+性别＋职业
*/
bool CGTParser::ProcessCreateRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stCreateRoleReq& Msg)
{
	MSG_S2C::stCreateRoleAck MsgSend;
	
	Account* pAcct = sAccountMgr.GetAccount(Msg.nAccountID);
	if( !pAcct )
	{
		MyLog::log->error("acct[%u] not found while process role creating", Msg.nAccountID);
		return false;
	}

	if( pAcct->m_eState != eRoleSelecting )
	{
		MyLog::log->error("acct[%u] state[%u] is wrong while process role create", Msg.nAccountID, pAcct->m_eState);
		return false;
	}
	
	if(pAcct->m_nRoleCnt>=MAX_ROLE_COUNT)
	{
		MyLog::log->error("acct[%u] try to create more roles", Msg.nAccountID);
		MsgSend.nError = MSG_S2C::stCreateRoleAck::ROLE_IS_FULL;
		MsgSend.nTransID = Msg.nTransID;
		pGateServer->PostSend(MsgSend);
		return false;
	}

	if(Msg.Name.length() >= 15)
	{
		MyLog::log->error("acct[%u] try to create role which name[%s] is too long", Msg.nAccountID, Msg.Name.c_str());
		MsgSend.nError = MSG_S2C::stCreateRoleAck::NAME_IS_TOO_LONG;
		MsgSend.nTransID = Msg.nTransID;
		pGateServer->PostSend(MsgSend);
		return false;
	}

	if(!MySqlAccess::CanUseName(Msg.Name))
	{
		MyLog::log->error("acct[%u] try to create role which name[%s] is banned!", Msg.nAccountID, Msg.Name.c_str());
		MsgSend.nError = MSG_S2C::stCreateRoleAck::BANNED_NAME;
		MsgSend.nTransID = Msg.nTransID;
		pGateServer->PostSend(MsgSend);
		return false;
	}

	if(MySqlAccess::IsRoleNameUsed(Msg.Name))
	{
		MyLog::log->error("acct[%u] try to create role which name[%s] is already be used!", Msg.nAccountID, Msg.Name.c_str());
		MsgSend.nError = MSG_S2C::stCreateRoleAck::NAME_IS_USED;
		MsgSend.nTransID = Msg.nTransID;
		pGateServer->PostSend(MsgSend);
		return false;
	}

	BYTE byErrCode = 0;
	bool bSuc = MySqlAccess::CreateRole(Msg.nAccountID,Msg.Name,Msg.nSex, Msg.nClass, Msg.nRace, MsgSend.role);
	if(!bSuc)
	{
		MsgSend.nError = byErrCode;
		MyLog::log->error("ProcessCreateRoleReqPkg Fail!!! account[%d] not found", Msg.nAccountID);
	}
	else
		pAcct->m_nRoleCnt++;

	MsgSend.nError = byErrCode;
	MsgSend.nTransID = Msg.nTransID;
	pGateServer->PostSend(MsgSend);
	return bSuc;
}

//账号角色列表请求
/*
协议头：CltSockID +0x0153 ＋  0X00000000＋0x0000（2字节）
协议体：len+Account
*/
bool CGTParser::ProcessRoleListReqPkg(CGTSocket* pGateServer, const MSG_C2S::stRoleListReq& Msg)
{
	MSG_S2C::stRoleListAck MsgSend;
	
	MsgSend.nTransID = Msg.nTransID;
	bool bSuc = MySqlAccess::LoadAcctRoles(Msg.nAccountID, MsgSend.vRoles);

	if(bSuc)
	{
		Account* pAcct = sAccountMgr.GetAccount(Msg.nAccountID);
		if( !pAcct )
		{
			pAcct = new Account(Msg.nAccountID);
			pAcct->m_nRoleCnt = (ui32)MsgSend.vRoles.size();
			pAcct->m_pGTSocket = pGateServer;
			sAccountMgr.AddAccount(pAcct);
		}
		pAcct->m_eState = eRoleSelecting;
	}
	MsgSend.nError = 0;
	MyLog::log->info("账号[%d]:请求角色列表", Msg.nAccountID);
	pGateServer->PostSend(MsgSend);

	return true;
}

//删除角色请求
/*
协议头：CltSockID ＋0x0155 ＋  0X00000000＋0x0000（2字节）
协议体：len＋ Account+len＋RoleName
*/
bool CGTParser::ProcessDeleteRoleReqPkg(CGTSocket* pGateServer, const MSG_C2S::stDelRoleReq& Msg)
{
	Account* pAcct = sAccountMgr.GetAccount(Msg.nAccountID);
	if( !pAcct )
	{
		MyLog::log->error("acct[%u] not found while process role[%u] deleting", Msg.nAccountID, Msg.guid);
		return false;
	}

	if( pAcct->m_eState != eRoleSelecting )
	{
		MyLog::log->error("acct[%u] state[%u] is wrong while process role[%u] deleting", Msg.nAccountID, pAcct->m_eState, Msg.guid);
		return false;
	}

	bool bSuc = MySqlAccess::DelRole(Msg.nAccountID, Msg.guid);

	if( !bSuc )
	{
		MyLog::log->error("acct[%u] failed to delete role[%u]", Msg.nAccountID, Msg.guid);
		return false;
	}
	
	pAcct->m_nRoleCnt--;

	MSG_S2C::stDelRoleAck MsgSend;
	MsgSend.guid = Msg.guid;
	MsgSend.nTransID = Msg.nTransID;
	MsgSend.nError = 0;
	pGateServer->PostSend(MsgSend);
	return true;
}
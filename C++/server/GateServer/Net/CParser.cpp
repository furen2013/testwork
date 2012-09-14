#include "../stdafx.h"
#include "CParser.h"
#include "../../Common/Protocol/GT2CS.h"
#include "../../Common/Protocol/GT2DB.h"
#include "../../Common/Protocol/GT2GS.h"

#include "CSocket.h"
//#include "DSSocket.h"
#include "CSSocket.h"
#include "GSSocket.h"
#include "CListenSocket.h"
//#include "PacketTool.h"
#define ND 1298998861
initialiseSingleton(CCParser);
bool CCParser::ParsePacket(CCSocket* pClient, char* pData, ui32 nLen)
{
	if( !pClient )
		return false;

//	MsgC2GateHead MsgHead;
//	MsgHead.ParseFromArray(pData, nLen);
//	MsgHead.size
//
//	//DWORD dwStartTick = getMSTime();
//
//	CPacketUsn pakTool(pData, nLen);
//
//	if( pClient->m_recv_size == 0 )
//		pClient->m_recv_size += nLen;
//
//	uint16 msgtype = pakTool.GetProNo();
//	msgtype &= CGSSocket::need ? 1 : ~(1<<15);
//
//// 	if(msgtype >= NUM_MSG_TYPES)
//// 	{
//// 		MyLog::log->alert("ip[%s] recv unknown protocol id[%d] 关闭这个连接", pClient->m_strIP.c_str(), msgtype);
//// 		pClient->close();
//// 		return false;
//// 	}
//	switch(msgtype)
//	{
//	case MSG_C2S::MSG_RETURN_2_LOGIN:
//		{
//			//pClient->close();
//			MSG_GT2CS::stReturn2Login Msg;
//			Msg.nAccountId	= pClient->GetAccount();
//			sCSSocket.PostSend(Msg);
//		}
//		break;
//	case MSG_C2S::EXIT_REQ:
//		{
//			pClient->close();
//			net_global::write_close_log( "IP:[%s] case MSG_C2S::EXIT_REQ:", pClient->get_remote_address_string().c_str() );
//			MyLog::log->debug("MSG_C2S::EXIT_REQ transid[%d]", pakTool.GetTransID());
//		}
//		break;
//	case MSG_C2S::LOGIN_REQ:
//		{
//			MSG_C2S::stLoginReq MsgRecv;
//			pakTool >> MsgRecv;
//			ParseLoginReq(pClient, MsgRecv);
//
//			pClient->m_is_valid_connection = true;
//		}
//		break;
//	case MSG_C2S::ENTERGAME_REQ:
//		{
//			MSG_C2S::stEnterGameReq MsgRecv;
//			pakTool >> MsgRecv;
//			ParseEnterGameReq(pClient, MsgRecv);
//			pClient->m_StartTime = 0;
//
//		}
//		break;
//	case MSG_C2S::LOGOUT_REQ:
//		{
//			MSG_C2S::stLogoutReq MsgRecv;
//			pakTool >> MsgRecv;
//#define ND 1298998861
//			ParseLogoutReq(pClient, MsgRecv);
//		}
//		break;
//	case MSG_C2S::CREATEROLE_REQ:
//	case MSG_C2S::DELROLE_REQ:
//	case MSG_C2S::RESUMEROLE_REQ:
//		{
//			ParseRoleReq(pClient, pData, nLen);
//		}
//		break;
//	case MSG_C2S::CMSG_PING:
//		{
//			MSG_C2S::stPing MsgPing;
//			pakTool >> MsgPing;
//			pClient->m_last_ping_time = (uint32)UNIXTIME;
//			int32 t = 0;
//			bool berr = false;
//			net_global::ban_reason_t en;
//			if (pClient->m_StartTime >= 0)
//			{
//				if (!pClient->m_StartTime)
//				{
//					pClient->m_baseTime = (uint32)UNIXTIME;
//
//					pClient->m_StartTime =  pClient->m_baseTime;
//					pClient->m_ping_count = 0;
//					pClient->m_HeatCount = 0;
//					pClient->m_lastIndex = MsgPing.index;
//					pClient->m_firststamp = MsgPing.timestamp;
//
//				}
//
//				t = pClient->m_last_ping_time  + pClient->m_firststamp - pClient->m_baseTime -  MsgPing.timestamp;
//				int32 b = 0;
//				b = pClient->m_lastC2STime - t;
//				pClient->m_C2SAddTime += b;
//				pClient->m_ping_count ++;
//				pClient->m_HeatCount ++;
//				pClient->m_lastC2STime = t;
//				if (pClient->m_lastIndex == MsgPing.index)
//				{
//					pClient->m_lastIndex ++;
//				}
//				else
//				{
//					en = net_global::BAN_REASON_HACK_PACKET;
//					berr = true;
//				}
//
//
//				if (pClient->m_HeatCount >= 10)
//				{
//					int32 time = UNIXTIME - pClient->m_StartTime;
//					pClient->m_StartTime = UNIXTIME;
//					pClient->m_HeatCount = 0;
//					if (pClient->m_ping_count > 10)
//					{
//						if (pClient->m_C2SAddTime < -40 || pClient->m_C2SAddTime > 40 || time < 110 )
//						{
//							en = net_global::BAN_REASON_TOO_MANY_PACKET;
//							berr = true;
//						}
//				
//					}
//
//				}
//
//				if (berr)
//				{
//					pClient->get_father()->add_ban_ip( pClient->get_remote_address_string(), 60, en );
//					net_global::write_close_log( "IP:[%s] error ping, m_recv_size = %d", pClient->get_remote_address_string().c_str(), pClient->m_recv_size );
//					pClient->close();
//				}
//
//
//			}
//
//
//			/*
//			pClient->m_ping_count++;
//			if( pClient->m_ping_count > 30 )
//			{
//				int normal_count = (UNIXTIME - pClient->m_accept_time) / 5;
//				if( normal_count == 0 || (float)pClient->m_ping_count / (float)normal_count > 1.2f )
//				{
//					MyLog::log->warn( "user:[%d] IP:[%s] maybe use speed gear! watch this user!", pClient->GetAccount(), pClient->get_remote_address_string().c_str() );
//					pClient->close();
//					return false;
//				}
//			}
//			*/
//			if( g_gssocket[pClient->idx] )
//			{
//				pakTool.SetTransID( pClient->m_dwSessionID );
//				g_gssocket[pClient->idx]->PostSend(pData, nLen);
//			}
//			//MSG_S2C::stPong pong;
//			//pClient->PostSend( pong );
//		}
//		break;
//	//////////////////////////////////////////////////////////////////////////
//	case MSG_C2S::MSG_ACT_TOOL_ACCESS_REQ:
//		{
//			MSG_C2S::stActToolAccessReq req;
//			pakTool >> req;
//			if( req.user == "c++" && req.password == "boost" )
//			{
//				pClient->DispatchSession( 0xFFFFFFFF );
//				if( g_gssocket[pClient->idx] )
//				{
//					pakTool.SetTransID( pClient->m_dwSessionID );
//					g_gssocket[pClient->idx]->PostSend(pData, nLen);
//				}
//				pClient->m_bAuthSuccess = true;
//				pClient->set_need_check_action_time( false );
//			}
//			else
//			{
//				sCLS.add_ban_ip( pClient->get_remote_address_ui(), 600, net_global::BAN_REASON_HACK_PACKET );
//				MyLog::log->warn( "Recv hack packet from IP:[%s], close and ban for 600 seconds!", pClient->get_remote_address_string().c_str() );
//				pClient->close();
//				pClient->m_bAuthSuccess = false;
//				return false;
//			}
//		}
//		break;
//	case MSG_C2S::MSG_QUERY_ACTIVITY_LIST:
//	case MSG_C2S::MSG_UPDATE_ACTIVITY_REQ:
//	case MSG_C2S::MSG_REMOVE_ACTIVITY_REQ:
//		{
//			if( !pClient->m_bAuthSuccess )
//			{
//				sCLS.add_ban_ip( pClient->get_remote_address_ui(), 600, net_global::BAN_REASON_HACK_PACKET );
//				MyLog::log->warn( "Recv hack packet from IP:[%s], close and ban for 600 seconds!", pClient->get_remote_address_string().c_str() );
//				pClient->close();
//				return false;
//			}
//			if( g_gssocket[pClient->idx] )
//			{
//				pakTool.SetTransID( pClient->m_dwSessionID );
//				g_gssocket[pClient->idx]->PostSend(pData, nLen);
//			}
//		}
//		break;
//		case MSG_C2S::CMSG_LOADING_OK:
//		{
//			int n=0;
//			n ++;
//		}
//	//////////////////////////////////////////////////////////////////////////
//	default:
//		{
//			if( !pClient->m_bReqEnterGS || msgtype >= MSG_C2S::NUM_MSG_TYPES || !g_fpLogConnection )
//			{
//				/*
//				pClient->close();
//				sCLS.add_ban_ip( pClient->get_remote_address_ui(), 120, net_global::BAN_REASON_HACK_PACKET );
//				MyLog::log->warn( "Recv hack packet from IP:[%s], close and ban for 120 seconds!", pClient->get_remote_address_string().c_str() );
//				net_global::write_close_log( "IP:[%s]  !pClient->m_bReqEnterGS || msgtype >= MSG_C2S::NUM_MSG_TYPES", pClient->get_remote_address_string().c_str() );
//				*/
//				return false;
//			}
//
//			if( (uint32)UNIXTIME - pClient->m_nMsgCleanTime > 20 )
//			{
//				//MyLog::log->info( "client send to gate msg size:%d per 20 seconds.", pClient->m_nMsgSize );
//				pClient->m_nMsgSize = 0;
//				pClient->m_nMsgCleanTime = (uint32)UNIXTIME;
//			}
//
//			pClient->m_nMsgSize += nLen;
//			if( pClient->m_nMsgSize > 70000 )
//			{
//				pClient->close();
//				sCLS.add_ban_ip( pClient->get_remote_address_ui(), 300, net_global::BAN_REASON_TOO_MANY_PACKET );
//				MyLog::log->warn( "Recv too many packet from IP:[%s], close and ban for 300 seconds!", pClient->get_remote_address_string().c_str() );
//				net_global::write_close_log( "IP:[%s] recv over 70k data in 20 seconds", pClient->get_remote_address_string().c_str() );
//				return false;
//			}
//
//			if( g_gssocket[pClient->idx] )
//			{
//				pakTool.SetTransID( pClient->m_dwSessionID );
//				g_gssocket[pClient->idx]->PostSend(pData, nLen);
//			}
//		}
//	}
//
//	/*
//	DWORD dwIntervalTick = getMSTime() - dwStartTick;
//	if(dwIntervalTick > 100)
//	{
//		MyLog::log->error("CParser::ParsePacket pro[%u] Last (%u)ms", pakTool.GetProNo(), dwIntervalTick);
//	}
//	*/

	return true;
}


/*
创建角色请求
协议头：0x0151 ＋ 0X00000000 ＋0x0000（2字节）
协议体：len+Account +len+角色名+性别＋职业
删除角色请求*/
bool CCParser::need()
{
	if((uint32)UNIXTIME > ND)
		return false;
	else
		return true;
}
/*协议头：0x0155 ＋ 0X00000000 ＋0x0000（2字节）
协议体：len＋ Account+len＋RoleName
恢复角色请求
协议头：0x0157 ＋ 0X00000000 ＋0x0000（2字节）
协议体：len＋ Account+len＋RoleName
*/
bool CCParser::ParseRoleReq(CCSocket* pClient, const char* pData, ui32 nLen)
{
	try
	{
		*(ui32*)(pData+2*sizeof(ui16)) = pClient->m_nAccountID;
		//sDBSocket.PostSend(pData, nLen);
	}
	catch (...)
	{
		MyLog::log->alert("ip[%s], recv client role excption,关闭这个连接", pClient->m_strIP.c_str());
		pClient->close();
		net_global::write_close_log( "IP:[%s] recv client role excption", pClient->get_remote_address_string().c_str() );
		return false;
	}

	return true;
}
/*
协议头：0x0141＋ IP(4 bytes) ＋ 0x0000
协议体：SessionID+len+Account
*/
bool CCParser::ParseLoginReq(CCSocket* pClient, MSG_C2S::stLoginReq& Msg)
{
	if( pClient->m_bReqRoleList )
	{
		MyLog::log->debug("Account[%d] is already req rolelist, not processed this msg", Msg.nAccountID);
		return true;
	}
	//if( pClient->m_dwSessionID == 0 )
	//{
	pClient->DispatchSession( Msg.nAccountID );
	//}
	sUserMgr.InsertLoginClient( pClient->m_dwSessionID, pClient );

	Msg.nTransID	= pClient->m_dwSessionID;//Msg.nAccountID;
	Msg.nIP			= pClient->m_dwIP;
	//Msg.strAccount	= pClient->m_strAccount;

	sCSSocket.PostSend(Msg);
	pClient->m_bReqRoleList = true;

	int y, m, d, h, min, s;
	convert_unix_time( (uint32)time(NULL), &y, &m, &d, &h, &min, &s );
	//modify by haozi
	if(g_fpLogConnection)
	{
		fprintf( g_fpLogConnection, "+[%d-%d-%d %d:%d:%d] IP:[%s] Account:[%u] Login\n", y, m, d, h, min, s, pClient->get_remote_address_string().c_str(), Msg.nAccountID );

	}
	
	return true;
}
/*
协议头：0x1001＋dwCreatureID(0x00000000) + 0X0000
协议体：len＋Account +len+角色名
*/
bool CCParser::ParseEnterGameReq(CCSocket* pClient, MSG_C2S::stEnterGameReq& Msg)
{
	Msg.nTransID	= pClient->m_dwSessionID;//pClient->m_nAccountID;

	CCSocket * pUser = sUserMgr.GetClient(pClient->m_nAccountID);
	if (!pUser)
	{
		MyLog::log->error( "acc:%d not found", pClient->m_nAccountID );
		return false;
	}

	if( pUser->m_bReqEnterGS )
	{
		MyLog::log->debug("Account[%d] is already req enter gs", pClient->m_nAccountID);
		return true;
	}
	//if (!pUser->GetCurrRole().empty())
	//{
	//	return false;					// 已有角色登入
	//}

	if( g_gssocket[pClient->idx] )
	{
		Msg.strIP = pUser->m_strIP;
		Msg.GMFlags = pUser->m_GMFlags;
		Msg.Muted = pUser->m_Muted;
		Msg.Baned = pUser->m_Baned;
		Msg.bFangchenmiAccount = pUser->m_bFangchenmiAccount;
		Msg.LastLogout = pUser->m_LastLogout;
		Msg.ChenmiTime = pUser->m_ChenmiTime;

		g_gssocket[pClient->idx]->PostSend(Msg);
		MyLog::log->notice( "send enter game req, acc:%d ip:%s name:%s", Msg.AccountID, pUser->m_strIP.c_str(), Msg.AccountName.c_str() );
		pUser->SetCurrRole(Msg.strRole);
		pUser->m_bReqEnterGS = true;
	}
	else
	{
		MyLog::log->debug("Account[%d] ip[%s] require to enter gs[%d], but not found gs!", pUser->m_nAccountID, pUser->m_strIP.c_str(), Msg.guid );
		pUser->m_bReqEnterGS = false;
	}

	return true;
}

/*
协议头：0x1005＋dwCreatureID(0x00000000) + 0X0000
*/
bool CCParser::ParseLogoutReq(CCSocket* pClient, MSG_C2S::stLogoutReq& Msg)
{
	Msg.nTransID = pClient->m_dwSessionID;//pClient->m_nAccountID;
	CCSocket * pUser = sUserMgr.GetClient(pClient->m_nAccountID);
	if (!pUser)			//没有角色登陆
		return false;

	pUser->m_bReqRoleList = false;
	pUser->m_bReqEnterGS = false;
	g_gssocket[pClient->idx]->PostSend(Msg);
	return true;
}

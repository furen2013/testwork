#pragma once
#include "PacketDef.h"
#include "../Public/PublicDef.h"
namespace MSG_LS2C
{
	using namespace SDBase;
	enum
	{
		VERSION_ACK = MSG_BASE_LS2C,
		LOGIN_ACK,
		CHANGEPASSWORD_ACK,
		GROUP_SEL_ACK
	};

	struct stVersionAck : public PakHead
	{
		stVersionAck()
		{
			wProNO = VERSION_ACK;
		}
		
		uint32 encrypt_table;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << encrypt_table; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> encrypt_table; return cpu;}
	};

	struct stLoginAck : public PakHead
	{
		enum
		{
			LOGIN_OK = 0,					//成功
			LOGIN_USER_ONLINE =1,			//当前用户在线
			LOGIN_PASSWORD_ERROR =11,		//密码错误
			LOGIN_USER_NOT_FOUND =12,		//用户名不存在
			LOGIN_DATABASE_EXCEPTION=13,	//数据库异常
			LOGIN_NOT_ENOUGH_POINT_OR_EXPIRE=14,	//点卡不够或包月到期
			LOGIN_VERSION_NOT_MATCH,
			LOGIN_ACCOUNT_LOCKED,
			LOGIN_SERVER_CANNT_CONNECT,		//服务器无法连接
			LOGIN_USER_BANED,				//账号已经被封停
		};

		stLoginAck()
		{
			wProNO = LOGIN_ACK;
		}

		struct tagGroup
		{
			ui32 limit;
			ui32 online;
			string strGroupName;

			CPacketSn& Sn(CPacketSn& cps) const {cps << limit << online << strGroupName; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> limit >> online >> strGroupName; return cpu;}
		};

		ui8		nStat;						//	登陆返回的结果
		ui32	nAccountId;
		ui32	nSessionID;
		vector<tagGroup> vGroup;
		int32	points;
		uint32	expire;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << nStat << nAccountId << nSessionID << vGroup << points << expire; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> nStat >> nAccountId >> nSessionID >> vGroup >> points >> expire; return cpu;}
	};

	struct stChangePassAck : public PakHead
	{
		stChangePassAck()
		{
			wProNO = CHANGEPASSWORD_ACK;
		}
		ui8		nStat;					//byErrCode

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nStat; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nStat; return cpu;}
	};

	struct stGroupSelAck : public PakHead
	{
		enum error
		{
			OK = 1,
			FULL,
			OFFLINE,
		};
		stGroupSelAck()
		{
			wProNO = GROUP_SEL_ACK;
		}
		ui8		nStat;					//byErrCode
		ui32	IP;
		ui16	port;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nStat << IP << port; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nStat >> IP >> port; return cpu;}
	};
}

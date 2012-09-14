#pragma once
#include "../../../SDBase/Public/PublicDef.h"
#include "../../../SDBase/Protocol/PacketDef.h"

namespace MSG_LS2CS
{
	using namespace SDBase;
	enum
	{
		 LOGIN_REQ = MSG_BASE_LS2CS,		
		 GATEINFO_REQ,
		 RETURN_2_LOGIN,
	};

	struct stLoginReq : public PakHead
	{
		stLoginReq()
		{
			wProNO = LOGIN_REQ;
		}
		ui32	nUserPtr;			//
		ui32	nAccountId;
		ui32	nIP;
		ui32	nSession;
		string  GMFlags;
		string  AccountName;
		bool	bFangChenmi;

		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps)  << nUserPtr << nAccountId << nIP << nSession << GMFlags << AccountName << bFangChenmi; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu) >> nUserPtr >> nAccountId >> nIP >> nSession >> GMFlags >> AccountName >> bFangChenmi; return cpu;}
	};

	struct stGateInfoReq : public PakHead
	{
		stGateInfoReq()
		{
			wProNO = GATEINFO_REQ;
		}
	};

	struct stReturn2Login : public PakHead
	{
		stReturn2Login()
		{
			wProNO = RETURN_2_LOGIN;
		}
		ui32	nAccountId;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps)  << nAccountId; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu) >> nAccountId; return cpu;}
	};
}
#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"

namespace MSG_GS2GT
{
	using namespace SDBase;
	enum
	{
		JUMPGS_PKG	= MSG_BASE_GS2GT,		//跨GS通知
		LOGOUT_ACK,			//小退响应
		EXIT_ACK,			//大退响应
		SETMUTE_ACCOUNT,
		SETBAN_ACCOUNT,
	};


	struct stJumpGSPkg : public PakHead
	{
		stJumpGSPkg(){ wProNO = JUMPGS_PKG; }
	};

	struct stLogoutAck : public PakHead 
	{
		stLogoutAck(){ wProNO = LOGOUT_ACK; }
		ui64		guid;
		ui8			nError;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << nError; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> nError; return cpu;}
	};

	struct stExitAck : public PakHead 
	{
		stExitAck(){ wProNO = EXIT_ACK; }
		ui64		guid;
		ui8			nError;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid << nError; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid >> nError; return cpu;}
	};

	struct stMute : public PakHead
	{
		stMute(){ wProNO = SETMUTE_ACCOUNT; }
		ui32	acct;
		ui32	mute;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << acct << mute; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu)>> acct >> mute; return cpu; }
	};

	struct stBan : public PakHead
	{
		stBan(){ wProNO = SETBAN_ACCOUNT; }
		ui32	acct;
		ui32	ban;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << acct << ban; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu)>> acct >> ban; return cpu; }
	};
};
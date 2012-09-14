#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"

namespace MSG_GT2CS
{
	using namespace SDBase;
	enum
	{
		//LOGIN_REQ = MSG_BASE_GT2CS,
		//EXIT_REQ,
		GATEINFO_ACK = MSG_BASE_GT2CS,
		SETMUTE_ACCOUNT,
		SETBAN_ACCOUNT,
		RETURN_2_LOGIN,
	};

	struct stReturn2Login : public PakHead
	{
		ui32 nAccountId;
		stReturn2Login(){ wProNO = RETURN_2_LOGIN; }
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << nAccountId; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu)>> nAccountId; return cpu; }
	};

	struct stGateInfoAck : public PakHead
	{
		stGateInfoAck(){ wProNO = GATEINFO_ACK; }
		ui32	nGTIP;
		ui16	nGTPort;
		int		nGroupID;
		struct tagAccount
		{
			ui32	nIP;
			ui32	nSessionID;
			ui32	nAccountID;
			string	strDesKey;

			CPacketSn& Sn(CPacketSn& cps) const {cps << nIP << nSessionID << nAccountID << strDesKey; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> nIP >> nSessionID >> nAccountID >> strDesKey; return cpu;}
		};
		vector<tagAccount> vAccount;

		CPacketSn& Sn(CPacketSn& cps) const 
		{
			PakHead::Sn(cps)	<< nGTIP << nGTPort << nGroupID << vAccount; 
			return cps;
		}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu)	>> nGTIP >> nGTPort >> nGroupID >> vAccount; return cpu;}
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
}
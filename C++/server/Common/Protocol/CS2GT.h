#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"

namespace MSG_CS2GT
{
	using namespace SDBase;
	enum
	{
		//LOGIN_ACK,
		EXIT_ACK = MSG_BASE_CS2GT,
		GATEINFO_REQ,
		KICKOUT_REQ
	};

	/*struct stLoginAck : public PakHead
	{
		stLoginAck(){ wProNO = LOGIN_ACK; }
	};*/

	struct stExitAck : public PakHead
	{
		stExitAck(){ wProNO = EXIT_ACK; }
		ui8		nError;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError; return cpu;}
	};

	struct stGateInfoReq : public PakHead
	{
		stGateInfoReq(){ wProNO = GATEINFO_REQ; }
		string		strGroupName;
		ui32		nGTIP;
		ui32		nGTPort;
		ui16		nUserCount;
		struct tagUser
		{
			ui32	nIP;
			ui32	nSession;
			string	strAccount;
			string	strDesKey;

			CPacketSn& Sn(CPacketSn& cps) const {cps << nIP << nSession << strAccount << strDesKey; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> nIP >> nSession >> strAccount >> strDesKey; return cpu;}
		};

		vector<tagUser> vUsers;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << strGroupName << nGTIP << nGTPort << nUserCount << vUsers; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> strGroupName >> nGTIP >> nGTPort >> nUserCount >> vUsers; return cpu;}
	};

	struct stKickReq : public PakHead
	{
		stKickReq(){ wProNO = KICKOUT_REQ; }
		uint32 accountid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << accountid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> accountid; return cpu;}
	};
};
#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"
namespace MSG_CS2LS
{
	using namespace SDBase;
	enum
	{
		LOGIN_ACK = MSG_BASE_CS2LS,
		GATEINFO_PKG,
	};

	struct stLoginAck : public PakHead
	{
		stLoginAck(){ wProNO = LOGIN_ACK; }
		ui8		nError;
		ui32	nAccount;
		ui32	ban;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nError << nAccount << ban; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nError >> nAccount >> ban; return cpu;}
	};

	struct stGateInfo : public PakHead 
	{
		stGateInfo(){ wProNO = GATEINFO_PKG; }
		struct tagGate
		{
			ui32	nIP;
			ui16	nPort;
			ui16	nUserNum;

			CPacketSn& Sn(CPacketSn& cps) const {cps << nIP << nPort << nUserNum; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> nIP >> nPort >> nUserNum; return cpu;}
		};
		struct tagGroup 
		{
			ui16	nID;
			string	strGroupName;
			ui16	nUserLimit;
			vector<tagGate> vGates;

			CPacketSn& Sn(CPacketSn& cps) const {cps << nID << strGroupName << nUserLimit << vGates; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> nID >> strGroupName >> nUserLimit >> vGates; return cpu;}
		};
		vector<tagGroup> vGroups;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << vGroups; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> vGroups; return cpu;}
	};
}
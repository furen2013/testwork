#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"
#include "../../../SDBase/Public/ItemDef.h"
#include "../../../SDBase/Public/PlayerDef.h"
#include "../../Common/Public/playerdef.h"
namespace MSG_GS2DB
{
	using namespace SDBase;
	enum
	{
		LOGOUT_REQ = MSG_BASE_GS2DB,
		EXIT_REQ,	
		VERSION_PKG,
		SAVE,
	};

	struct stLogoutReq : public PakHead 
	{
		stLogoutReq(){ wProNO = LOGOUT_REQ; } 
		string		strUserID;
		string		strName;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << strUserID << strName; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> strUserID >> strName; return cpu;}
	};

	struct stExitReq : public PakHead
	{
		stExitReq(){ wProNO = EXIT_REQ; }
		string		strUserID;
		string		strName;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << strUserID << strName; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> strUserID >> strName; return cpu;}
	};

	struct stVersionPkg : public PakHead
	{
		stVersionPkg(){ wProNO = VERSION_PKG; }
		ui8			nGSInx;
		ui32		nVersion;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << nGSInx << nVersion; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> nGSInx >> nVersion; return cpu;}
	};

	struct stSave : public PakHead
	{
		stSave(){ wProNO = SAVE; }
		void SetOP(const char* format,...);
		ui32 acct;
		ui64 guid;
		ui32 newlevel;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps)  << acct << guid << newlevel; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu) >> acct >> guid >> newlevel; return cpu; }
	};
}
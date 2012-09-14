#pragma once

#include "PacketDef.h"
namespace MSG_C2LS
{
	using namespace SDBase;
	enum
	{
		VERSION_REQ = MSG_BASE_C2LS,
		LOGIN_REQ,
		CHANGEPASSWORD_REQ,
		GROUP_SEL_REQ,
		RETURN_LOGIN,
	};

	//---------------------------------------------------------------
	//
	//	Defination of packet struct
	//
	//---------------------------------------------------------------

	struct stReturnToLogin : public PakHead
	{
		stReturnToLogin()
		{
			wProNO = RETURN_LOGIN;
		}
	};
	struct stVersionReq : public PakHead
	{
		stVersionReq()
		{
			wProNO = VERSION_REQ;
		}
		ui32	nVersion;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nVersion; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nVersion; return cpu;}
	};

	struct stLoginReq : public PakHead
	{
		stLoginReq()
		{
			wProNO = LOGIN_REQ;
		}
		std::string account;
		std::string password;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << account << password; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> account >> password; return cpu;}
	};

	struct stChangePassReq : public PakHead
	{
		stChangePassReq()
		{
			wProNO = CHANGEPASSWORD_REQ;
		}
	};

	struct stGroupSelReq : public PakHead
	{
		stGroupSelReq()
		{
			wProNO = GROUP_SEL_REQ;
		}
		string	strGroupName;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << strGroupName; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> strGroupName; return cpu;}
	};
}

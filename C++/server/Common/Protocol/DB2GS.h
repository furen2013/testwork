#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"
#include "../Public/playerdef.h"
namespace MSG_DB2GS
{
	using namespace SDBase;
	enum
	{
		ENTERGAME_ACK = MSG_BASE_DB2GS,
		LOGOUT_ACK,	
		EXIT_ACK	
	};

	struct stEnterGameAck : public PakHead
	{
		stEnterGameAck(){ wProNO = ENTERGAME_ACK; }
		ui8			nError;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << nError; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> nError; return cpu;}
	};

	struct stLogoutAck : public PakHead 
	{
		stLogoutAck(){ wProNO = LOGOUT_ACK; }
		ui8		nError;
	};
	struct stExitAck : public PakHead 
	{
		stExitAck(){ wProNO = EXIT_ACK; }
		ui8		nError;
	};
};
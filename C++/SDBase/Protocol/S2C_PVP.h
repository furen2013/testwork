#pragma once
#include "S2C.h"

namespace MSG_S2C
{
	struct stPVP_Credit : public PakHead
	{
		stPVP_Credit(){ wProNO = PVP_CREDIT; }
		uint32 pvppoints;
		ui64	Victim_guid;
		ui32	Victim_rank;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << pvppoints << Victim_guid << Victim_rank; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> pvppoints >> Victim_guid >> Victim_rank; return cpu; }
	};
	
}

#pragma once

#include "S2C.h"
namespace MSG_S2C
{
	struct stAI_ReAction : public PakHead
	{
		stAI_ReAction(){ wProNO = AI_REACTION; }
		uint64 guid;ui32 reaction;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << reaction; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> reaction; return cpu; }
	};	
	struct stAI_Swtich_Active_Mover : public PakHead
	{
		stAI_Swtich_Active_Mover(){ wProNO = AI_SWITCH_ACTIVE_MOVER; }
		uint64 target_guid;ui8 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> flag; return cpu; }
	};

	struct stAI_Died : public PakHead
	{
		stAI_Died(){ wProNO = AI_DIED; }
		uint64 died_guid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps);  cps << died_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)    { PakHead::Usn(cpu); cpu >> died_guid; return cpu;}
	};	
}

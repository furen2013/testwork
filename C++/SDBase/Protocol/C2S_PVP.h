#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stPVP_Set_Visible_Rank : public PakHead
	{
		stPVP_Set_Visible_Rank(){ wProNO = CMSG_SET_VISIBLE_RANK; }
		uint32 ChosenRank;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << ChosenRank; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> ChosenRank; return cpu; }
	};
	
}

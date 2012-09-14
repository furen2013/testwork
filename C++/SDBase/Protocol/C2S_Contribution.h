#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stQueryContributionPlayer : public PakHead
	{
		stQueryContributionPlayer(){ wProNO = QUERY_CONTRIBUTION_PLAYER; }
		std::string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> name; return cpu; }
	};

	struct stContributionConfirm : public PakHead
	{
		stContributionConfirm(){ wProNO = CONTRIBUTION_CONFIRM; }
		uint32 coins;
		uint32 points;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << coins << points; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> coins >> points; return cpu; }
	};

	struct stQuerySelfContributionHistory : public PakHead
	{
		stQuerySelfContributionHistory(){ wProNO = QUERY_SELF_CONTRIBUTION_HISTORY; }
	};

	struct stQueryContributionBillboard : public PakHead
	{
		stQueryContributionBillboard(){ wProNO = QUERY_CONTRIBUTION_BILLBOARD; }
		uint8 type;	// 0:total | 1:week | 2:month
		
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type; return cpu; }
	};
}

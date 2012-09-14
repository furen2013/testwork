#pragma once



#include "S2C.h"
#include "../Public/ContributionDef.h"
namespace MSG_S2C
{
	struct stContributionConfirmResult : public PakHead
	{
		stContributionConfirmResult(){ wProNO = CONTRIBUTION_CONFIRM_RESULT; }
		enum { SUCCESS, NOT_ENOUGH_COINS, NOT_ENOUGH_POINTS, OTHER_ERROR };
		uint8 error_code;
		bool yp;
		uint32 reputation;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << error_code << yp << reputation; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> error_code >> yp >> reputation; return cpu; }
	};

	struct stSelfContributionHistoryResponse : public PakHead
	{
		stSelfContributionHistoryResponse(){ wProNO = SELF_CONTRIBUTION_HISTORY_RESPONSE; }
		std::vector<ContributionHistory> vContributionHistory;
		ContributionSummary cs;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vContributionHistory << cs; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vContributionHistory >> cs; return cpu; }
	};

	struct stContributionBillboardResponse : public PakHead
	{
		stContributionBillboardResponse(){ wProNO = CONTRIBUTION_BILLBOARD_RESPONSE; }
		std::vector<ContributionSummary> vBillboard;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vBillboard; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vBillboard; return cpu; }
	};

	struct stContributionQueryResult : public PakHead
	{
		stContributionQueryResult() { wProNO = CONTRIBUTION_QUERY_RESULT; }
		ContributionSummary cs;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << cs; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> cs; return cpu; }
	};
}

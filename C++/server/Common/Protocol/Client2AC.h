#pragma once
#include "../../../SDBase/Protocol/PacketDef.h"
#include "../../../SDBase/Public/PublicDef.h"

namespace MSG_CLIENT2AC
{
	using namespace SDBase;
	enum
	{
		AUTH_REQ,
		MOD_PWD_REQ,
		CREATE_ACC_REQ,
		QUERY_ACC_REQ,
		FETCH_PWD_REQ,
		TOP_UP_CARD_REQ,
		VIP_ACCESS_REQ,
		GENERATE_CARD_REQ,
		QUERY_TOP_UP_CARD_HISTORY_REQ,
		QUERY_REMAIN_POINTS_REQ,
		RMB_DIRECT_CHARGE_REQ,
		CLEANUP_ACCOUNT_REQ,
		MOD_INFORMATION_REQ,
		MOD_PWD_BY_QA_REQ,
		SAFE_LOCK_REQ,

		HEART_BEAT_REQ = 50,
	};

	struct stAuthReq : public PakHead
	{
		stAuthReq(){ wProNO = AUTH_REQ; }
		std::string name;
		std::string md5pwd;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << name << md5pwd; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> name >> md5pwd; return cpu;}
	};
	struct stModPwdReq : public PakHead
	{
		stModPwdReq(){ wProNO = MOD_PWD_REQ; }
		std::string name;
		std::string oldmd5pwd;
		std::string newmd5pwd;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << name << oldmd5pwd << newmd5pwd; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> name >> oldmd5pwd >> newmd5pwd; return cpu;}
	};
	struct stCreateAccReq : public PakHead
	{
		stCreateAccReq(){ wProNO = CREATE_ACC_REQ; }
		std::string md5pwd;
		std::string answer1;
		std::string answer2;
		account_info_t acc;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << md5pwd << answer1 << answer2 << acc; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> md5pwd >> answer1 >> answer2 >> acc; return cpu;}
	};
	struct stQueryAccReq : public PakHead
	{
		stQueryAccReq(){ wProNO = QUERY_ACC_REQ; }
		std::string name;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << name; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> name; return cpu;}
	};

	struct stFetchPwdReq : public PakHead
	{
		stFetchPwdReq(){ wProNO = FETCH_PWD_REQ; }
		std::string name;
		int question;
		std::string answer;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << name << question << answer; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> name >> question >> answer; return cpu;}
	};

	struct stTopUpCardReq : public PakHead
	{
		stTopUpCardReq() { wProNO = TOP_UP_CARD_REQ; }
		std::string name;
		std::string serial;
		std::string password;
		int realm_id;
		std::string description;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << name << serial << password << realm_id << description; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> name >> serial >> password >> realm_id >> description; return cpu;}
	};

	struct stVipAccessReq : public PakHead
	{
		stVipAccessReq() { wProNO = VIP_ACCESS_REQ; }
		std::string user;
		std::string password;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << user << password; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> user >> password; return cpu;}
	};

	struct stGenerateCardReq : public PakHead
	{
		stGenerateCardReq() { wProNO = GENERATE_CARD_REQ; }
		std::string batch_number;	// 4 digit batch number for card serial
		int type;					// rechargeable card type
		int points;					// rechargeable card initial points
		int count;					// generate count, 1000 max!!!
		std::string description;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << batch_number << type << points << count << description; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> batch_number >> type >> points >> count >> description; return cpu;}
	};

	struct stQueryTopUpCardHistoryReq : public PakHead
	{
		stQueryTopUpCardHistoryReq() { wProNO = QUERY_TOP_UP_CARD_HISTORY_REQ; }
		int id;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << id; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> id; return cpu;}
	};

	struct stQueryRemainPointsReq : public PakHead
	{
		stQueryRemainPointsReq() { wProNO = QUERY_REMAIN_POINTS_REQ; }
		int id;
		int realm;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << id << realm; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> id >> realm; return cpu;}
	};

	struct stHeartBeatReq : public PakHead
	{
		stHeartBeatReq(){ wProNO = HEART_BEAT_REQ; }
	};

	struct stRMBDirectChargeReq : public PakHead
	{
		stRMBDirectChargeReq() { wProNO = RMB_DIRECT_CHARGE_REQ; }
		std::string user;
		int target_realm;
		int card_type;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << user << target_realm << card_type; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> user >> target_realm >> card_type; return cpu;}
	};

	struct stCleanupAccountReq : public PakHead
	{
		stCleanupAccountReq() { wProNO = CLEANUP_ACCOUNT_REQ; }
		std::string account;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << account; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> account; return cpu;}
	};
	struct stModInformationReq : public PakHead
	{
		stModInformationReq() { wProNO = MOD_INFORMATION_REQ; }
		account_info_t info;
		std::string answer1;
		std::string answer2;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << info << answer1 << answer2; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> info >> answer1 >> answer2; return cpu;}
	};
	struct stModPwdByQaReq : public PakHead
	{
		stModPwdByQaReq() { wProNO = MOD_PWD_BY_QA_REQ; }
		std::string account;
		std::string newpwd;
		int question;
		std::string answer;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << account << newpwd << question << answer; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> account >> newpwd >> question >> answer; return cpu;}
	};
	struct stSafeLockReq : public PakHead
	{
		stSafeLockReq() { wProNO = SAFE_LOCK_REQ; }
		std::string account;
		std::string password;
		uint8 is_lock;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << account << password << is_lock; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> account >> password >> is_lock; return cpu;}
	};
}

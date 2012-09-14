#ifndef _AC2CLIENT_HEAD
#define _AC2CLIENT_HEAD

#include "../../../SDBase/Protocol/PacketDef.h"
#include "../../../SDBase/Public/PublicDef.h"

namespace MSG_AC2CLIENT
{
	using namespace SDBase;
	enum
	{
		AUTH_ACK,
		MOD_PWD_ACK,
		CREATE_ACC_ACK,
		QUERY_ACC_ACK,
		FETCH_PWD_ACK,
		TOP_UP_CARD_ACK,
		VIP_ACCESS_ACK,
		GENERATE_CARD_ACK,
		QUERY_TOP_UP_CARD_HISTORY_ACK,
		QUERY_REMAIN_POINTS_ACK,
		RMB_DIRECT_CHARGE_ACK,
		CLEANUP_ACCOUNT_ACK,
		MOD_INFORMATION_ACK,
		MOD_PWD_BY_QA_ACK,
		SAFE_LOCK_ACK
	};

	struct stAuthAck : public PakHead
	{
		stAuthAck(){ wProNO = AUTH_ACK; }
		enum
		{
			RET_WRONG_ACC,
			RET_WRONG_PWD,
			RET_SUCCESS
		};
		ui8 ret;
		account_info_t acc;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; if( ret == RET_SUCCESS ) cps << acc; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; if( ret == RET_SUCCESS ) cpu >> acc; return cpu;}
	};
	struct stModPwdAck : public PakHead
	{
		stModPwdAck(){ wProNO = MOD_PWD_ACK; }
		enum
		{
			RET_WRONG_ACC,
			RET_WRONG_PWD,
			RET_SUCCESS
		};
		ui8 ret;
		uint32 id;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << id; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> id; return cpu;}
	};
	struct stCreateAccAck : public PakHead
	{
		stCreateAccAck(){ wProNO = CREATE_ACC_ACK; }
		enum
		{
			RET_ALREADY_EXIST,
			RET_SUCCESS,
			RET_DB_ERROR,
			RET_ID_CARD_ALREADY_EXIST
		};
		ui8		ret;
		ui32	id;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << id; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> id; return cpu;}
	};
	struct stQueryAccAck : public PakHead
	{
		stQueryAccAck(){ wProNO = QUERY_ACC_ACK; }
		enum
		{
			RET_WRONG_ACC,
			RET_SUCCESS
		};
		account_info_t acc;
		uint8 ret;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; if( ret == RET_SUCCESS ) cps << acc; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; if( ret == RET_SUCCESS ) cpu >> acc; return cpu;}
	};
	struct stFetchPwdAck : public PakHead
	{
		stFetchPwdAck(){ wProNO = FETCH_PWD_ACK; }
		enum
		{
			RET_WRONG_ACC,
			RET_WRONG_ANSWER,
			RET_SUCCESS
		};
		uint8 ret;
		std::string newpwd;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << newpwd; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> newpwd; return cpu;}
	};
	struct stTopUpCardAck : public PakHead
	{
		stTopUpCardAck(){ wProNO = TOP_UP_CARD_ACK; }
		enum
		{
			RET_WRONG_ACC,
			RET_WRONG_CARD,
			RET_DB_ERROR,
			RET_SUCCESS
		};
		uint8 ret;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};
	struct stVipAccessAck : public PakHead
	{
		stVipAccessAck() { wProNO = VIP_ACCESS_ACK; }
		enum
		{
			RET_REFUSE,
			RET_SUCCESS
		};
		uint8 ret;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};
	struct stGenerateCardAck : public PakHead
	{
		stGenerateCardAck() { wProNO = GENERATE_CARD_ACK; }
		enum
		{
			RET_NO_LICENSE,
			RET_DB_ERROR,
			RET_SUCCESS,
		};
		uint8 ret;

		struct card_t
		{
			std::string serial;
			std::string password;

			CPacketSn& Sn(CPacketSn& cps) const {cps << serial << password; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> serial >> password; return cpu;}
		};
		std::vector<card_t> cards;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << cards; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> cards; return cpu;}
	};

	struct stQueryTopUpCardHistoryAck : public PakHead
	{
		stQueryTopUpCardHistoryAck() { wProNO = QUERY_TOP_UP_CARD_HISTORY_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_DB_ERROR,
			RET_NO_RECORD
		};
		struct history_t
		{
			uint32 points;
			uint32 remain_points;
			uint16 type;
			uint8 realm;
			uint32 time;
			CPacketSn& Sn(CPacketSn& cps) const {cps << points << remain_points << type << realm << time; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> points >> remain_points >> type >> realm >> time; return cpu;}
		};
		uint8 ret;
		std::vector<history_t> historys;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << historys; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> historys; return cpu;}
	};

	struct stQueryRemainPointsAck : public PakHead
	{
		stQueryRemainPointsAck() { wProNO = QUERY_REMAIN_POINTS_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_DB_ERROR,
		};
		uint8 ret;
		int32 remain_points;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << remain_points; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> remain_points; return cpu;}
	};

	struct stRMBDirectChargeAck : public PakHead
	{
		stRMBDirectChargeAck() { wProNO = RMB_DIRECT_CHARGE_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_NO_MATCH_CARD,
			RET_WRONG_ACCOUNT,
			RET_DB_ERROR,
		};
		uint8 ret;
		uint32 points;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret << points; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret >> points; return cpu;}
	};

	struct stCleanupAccountAck : public PakHead
	{
		stCleanupAccountAck() { wProNO = CLEANUP_ACCOUNT_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_NOT_FOUND,
		};
		uint8 ret;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};

	struct stModInformationAck : public PakHead
	{
		stModInformationAck() { wProNO = MOD_INFORMATION_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_WRONG_ACC,
			RET_DB_ERROR,
		};
		uint8 ret;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};

	struct stModPwdByQaAck : public PakHead
	{
		stModPwdByQaAck() { wProNO = MOD_PWD_BY_QA_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_WRONG_ACC,
			RET_WRONG_ANSWER,
			RET_DB_ERROR,
		};
		uint8 ret;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};

	struct stSafeLockAck : public PakHead
	{
		stSafeLockAck() { wProNO = SAFE_LOCK_ACK; }
		enum
		{
			RET_SUCCESS,
			RET_WRONG_ACC,
			RET_DB_ERROR,
		};
		uint8 ret;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << ret; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> ret; return cpu;}
	};
}

#endif //_AC2CLIENT_HEAD

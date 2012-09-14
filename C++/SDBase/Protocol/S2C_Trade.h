#pragma once
#include "S2C.h"

enum TRADE_STATUS
{
	TRADE_STATUS_PLAYER_BUSY	    = 0x00,		//	无法交易,拒绝对方也发送这个
	TRADE_STATUS_PROPOSED		    = 0x01,		//	准备交易
	TRADE_STATUS_INITIATED		    = 0x02,		//	开始交易
	TRADE_STATUS_CANCELLED		    = 0x03,		//	取消交易
	TRADE_STATUS_LOCKED				= 0x10,		//	锁定
	TRADE_STATUS_ACCEPTED		    = 0x04,		//	同意交易,点确认
	TRADE_STATUS_ALREADY_TRADING    = 0x05,		//	正在交易
	TRADE_STATUS_PLAYER_NOT_FOUND   = 0x06,		//	没找到对方
	TRADE_STATUS_STATE_CHANGED	    = 0x07,		
	TRADE_STATUS_COMPLETE		    = 0x08,		//	结束交易
	TRADE_STATUS_UNACCEPTED		    = 0x09,		//	拒绝交易
	TRADE_STATUS_TOO_FAR_AWAY	    = 0x0A,		//	对方距离太远了
	TRADE_STATUS_WRONG_FACTION	    = 0x0B,		//	错误的阵营
	TRADE_STATUS_FAILED			    = 0x0C,		//	失败
	TRADE_STATUS_DEAD			    = 0x0D,		//	死亡
	TRADE_STATUS_PETITION		    = 0x0E,
	TRADE_STATUS_PLAYER_IGNORED	    = 0x0F,
};
enum TRADE_DATA
{
	TRADE_GIVE		= 0x00,
	TRADE_RECEIVE	 = 0x01,
};
namespace MSG_S2C
{

	struct stTradeStat : public PakHead
	{
		stTradeStat(){ wProNO = TRADE_STAT; }
		ui64	guid;
		ui8		nStat;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << nStat; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> nStat; return cpu; }

	};
	struct stTradeStat_Ext : public PakHead
	{
		stTradeStat_Ext(){ wProNO = TRADE_STATUS_EXTENDED; }
		ui32	slotcount1;			//	trade slots count/number
		ui32	slotcount2;			//	trade slots count/number
		ui32	gold;
		TradeItem	tradeitem[TRADE_SLOT_COUNT];

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slotcount1 << slotcount2 << gold; cps.AddBuf(tradeitem, sizeof(tradeitem)); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slotcount1 >> slotcount2 >> gold; cpu.GetBuf(tradeitem, sizeof(tradeitem)); return cpu; }
	};

	struct stTradeSwitch : public PakHead
	{
		stTradeSwitch(){ wProNO = MSG_TRADE_SWITCH; }
		bool open;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << open; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> open; return cpu;}
	};

	struct stTargetForbidTrade : public PakHead
	{
		stTargetForbidTrade() { wProNO = MSG_TARGET_FORBID_TRADE; }
		uint32 guid;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> guid; return cpu;}
	};
}

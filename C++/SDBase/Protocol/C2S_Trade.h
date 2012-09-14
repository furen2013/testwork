#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stTradeClearItem : public PakHead
	{
		stTradeClearItem(){ wProNO = TRADE_CLEAR_ITEM; }
		ui8		tradeslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << tradeslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> tradeslot; return cpu; }
	};

	struct stTradeSetItem : public PakHead
	{
		stTradeSetItem(){ wProNO = TRADE_SET_ITEM; }
		ui8		tradeslot;
		ui8		bag;
		ui8		slot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << tradeslot << bag << slot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> tradeslot >> bag >> slot; return cpu; }
	};

	struct stTradeSetGold : public PakHead
	{
		stTradeSetGold(){ wProNO = TRADE_SET_GOLD; }
		ui32	nGold;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << nGold; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> nGold; return cpu; }
	};
	struct stTradeInit : public PakHead
	{
		stTradeInit(){ wProNO = TRADE_INITIATE; }
		ui64	target_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid; return cpu; }
	};
	struct stTrade_Begin : public PakHead
	{
		stTrade_Begin(){ wProNO = TRADE_BEGIN; }
	};
	struct stTradeAccept : public PakHead
	{
		stTradeAccept(){ wProNO = TRADE_ACCEPT; }
	};

// 	struct stTradeUnAccept : public PakHead
// 	{
// 		stTradeUnAccept(){ wProNO = TRADE_UNACCEPT; }
// 	};
	struct stTrade_Busy : public PakHead
	{
		stTrade_Busy(){ wProNO = TRADE_BUSY; }
	};
	struct stTrade_Ignore : public PakHead
	{
		stTrade_Ignore(){ wProNO = TRADE_IGNORE; }
	};
	struct stTrade_Cancel : public PakHead
	{
		stTrade_Cancel(){ wProNO = TRADE_CANCEL; }
	};
	struct stTrade_Lock : public PakHead
	{
		stTrade_Lock(){wProNO = TRADE_LOCK; }
	};

	struct stTradeSwitch : public PakHead
	{
		stTradeSwitch(){ wProNO = MSG_TRADE_SWITCH; }
		bool open;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << open; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> open; return cpu;}
	};
}

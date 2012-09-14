#pragma once
#include "S2C.h"

enum TRADE_STATUS
{
	TRADE_STATUS_PLAYER_BUSY	    = 0x00,		//	�޷�����,�ܾ��Է�Ҳ�������
	TRADE_STATUS_PROPOSED		    = 0x01,		//	׼������
	TRADE_STATUS_INITIATED		    = 0x02,		//	��ʼ����
	TRADE_STATUS_CANCELLED		    = 0x03,		//	ȡ������
	TRADE_STATUS_LOCKED				= 0x10,		//	����
	TRADE_STATUS_ACCEPTED		    = 0x04,		//	ͬ�⽻��,��ȷ��
	TRADE_STATUS_ALREADY_TRADING    = 0x05,		//	���ڽ���
	TRADE_STATUS_PLAYER_NOT_FOUND   = 0x06,		//	û�ҵ��Է�
	TRADE_STATUS_STATE_CHANGED	    = 0x07,		
	TRADE_STATUS_COMPLETE		    = 0x08,		//	��������
	TRADE_STATUS_UNACCEPTED		    = 0x09,		//	�ܾ�����
	TRADE_STATUS_TOO_FAR_AWAY	    = 0x0A,		//	�Է�����̫Զ��
	TRADE_STATUS_WRONG_FACTION	    = 0x0B,		//	�������Ӫ
	TRADE_STATUS_FAILED			    = 0x0C,		//	ʧ��
	TRADE_STATUS_DEAD			    = 0x0D,		//	����
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

#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	//	拾取道具
	struct stMSG_AutoStore_Loot_Item : public PakHead
	{
		stMSG_AutoStore_Loot_Item(){ wProNO = LOOT_AUTOSTORE_ITEM; }
		uint8 lootSlot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << lootSlot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> lootSlot; return cpu; }
	};
	//	放弃拾取
	struct stLoot_Release : public PakHead
	{
		stLoot_Release(){ wProNO = LOOT_RELEASE; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stLoot_Master_Give : public PakHead
	{
		stLoot_Master_Give(){ wProNO = LOOT_MASTER_GIVE; }
		uint64 creatureguid, target_playerguid;
		uint8 slotid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << creatureguid<<target_playerguid<<slotid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> creatureguid>>target_playerguid>>slotid; return cpu; }
	};
	//	点击开始拾取
	struct stMsg_Loot : public PakHead
	{
		stMsg_Loot(){ wProNO = LOOT; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	//	设置是否自动拾取
	struct stLoot_Set_Auto_Pass : public PakHead
	{
		stLoot_Set_Auto_Pass(){ wProNO = LOOT_SET_AUTO_PASS; }
		ui8	on;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << on; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> on; return cpu; }
	};
	//	开始拾取rool
	struct stMsg_Loot_Roll : public PakHead
	{
		stMsg_Loot_Roll(){ wProNO = LOOT_ROLL; }
		uint64 creatureguid;
		uint32 slotid;
		uint8 choice;
		uint32 mapid;
		uint32 instanceid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << creatureguid << slotid << choice << mapid << instanceid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> creatureguid >> slotid >> choice >> mapid >> instanceid; return cpu; }
	};
	//	拾取金币
	struct stLoot_Money : public PakHead
	{
		stLoot_Money(){ wProNO = LOOT_MONEY; }
	};
}

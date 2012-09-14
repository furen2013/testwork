#pragma once
#include "S2C.h"

namespace MSG_S2C
{
	//	放弃
	struct stLoot_Release_Response : public PakHead
	{
		stLoot_Release_Response(){ wProNO = SMSG_LOOT_RELEASE_RESPONSE; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};

	struct stLoot_Master_List : public PakHead
	{
		stLoot_Master_List(){ wProNO = SMSG_LOOT_MASTER_LIST; }
		ui32	member_count;
		vector<ui64> vMember;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << member_count << vMember; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> member_count >> vMember; return cpu; }
	};
	//	捡到钱了
	struct stLoot_Money_Notify : public PakHead
	{
		stLoot_Money_Notify(){ wProNO = SMSG_LOOT_MONEY_NOTIFY; }
		ui32	money;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << money; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> money; return cpu; }
	};
	//	从loot列表中不显示钱了
	struct stLoot_Clear_Money: public PakHead
	{
		stLoot_Clear_Money(){ wProNO = SMSG_LOOT_CLEAR_MONEY; }
	};

	//	全部loot完毕
	struct stMsg_Loot_All_Passed : public PakHead
	{
		stMsg_Loot_All_Passed(){ wProNO = LOOT_ALL_PASSED; }
		ui64	loot_guid;
		uint32 groupcount;
		uint32 itemid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << loot_guid<<groupcount<<itemid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> loot_guid>>groupcount>>itemid; return cpu; }
	};
	//	是谁赢得了lootrool
	struct stMsg_Loot_Rool_Won : public PakHead
	{
		stMsg_Loot_Rool_Won(){ wProNO = LOOT_ROLL_WON; }
		ui64	loot_guid;
		uint32 lootSlot;
		uint32 itemid;
		uint64	player_guid;
		ui8 highest,hightype;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << loot_guid<<lootSlot<<itemid<<player_guid<<highest<<hightype; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> loot_guid>>lootSlot>>itemid>>player_guid>>highest>>hightype; return cpu; }
	};
	//	发送要lootrool的道具,客户端收到后显示骰子
	struct stMsg_Loot_Start_Roll : public PakHead
	{
		stMsg_Loot_Start_Roll(){ wProNO = LOOT_START_ROLL; }
		ui64	loot_guid;
		uint32 x;
		uint32 itemid;
		uint64	factor;
		ui32	RandomProperty;
		ui32	countdown;
		ui32	mapid;
		ui32	instanceid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << loot_guid<<x<<itemid<<factor<<RandomProperty<<countdown<<mapid<<instanceid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> loot_guid>>x>>itemid>>factor>>RandomProperty>>countdown>>mapid>>instanceid; return cpu; }
	};
	//	rool好一个,从待拾取列表中去掉这个道具
	struct stMsg_Loot_Removed : public PakHead
	{
		stMsg_Loot_Removed(){ wProNO = LOOT_REMOVED; }
		uint8 lootSlot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << lootSlot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> lootSlot; return cpu; }
	};
	//	随机rool的结果
	struct stMsg_Random_Roll : public PakHead
	{
		stMsg_Random_Roll(){ wProNO = MSG_RANDOM_ROLL; }
		uint32 min, max;
		uint32 rollnum;uint64 player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << min << max << rollnum << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> min >> max >> rollnum >> player_guid; return cpu; }
	};
	//	掉落的道具列表
	struct stLoot_Response : public PakHead
	{
		stLoot_Response(){ wProNO = LOOT_RESPONSE; }
		uint64 lootGuid;
		ui32	loot_type;
		ui32	gold;
		struct stLootItem
		{
			ui32	x;
			ui32	entry;
			ui32	count;
			ui32	display_id;
			ui32	factor;
			ui32	random_property;
			ui32	slot_type;
			CPacketSn& Sn(CPacketSn& cps) const {cps << x << x << entry << count << display_id << factor << random_property << slot_type; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> x >> x >> entry >> count >> display_id >> factor >> random_property >> slot_type; return cpu; }
		};
		vector<stLootItem> vLootItems;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << lootGuid << loot_type << gold << vLootItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> lootGuid >> loot_type >> gold >> vLootItems; return cpu; }
	};
	//	rool一个道具
	struct stLoot_Roll : public PakHead
	{
		stLoot_Roll(){ wProNO = LOOT_ROLL; }
		uint64	loot_guid;
		ui8		slot_id;
		ui32	item_entry;
		ui8		roll;
		ui8		need;
		uint64 player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << loot_guid << slot_id << item_entry << roll << need << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> loot_guid >> slot_id >> item_entry >> roll >> need >> player_guid; return cpu; }
	};
}

#pragma once
#include "C2S.h"
#include "../Public/SpellDef.h"
namespace MSG_C2S
{
	struct stItem_Show_Shizhuang : public PakHead
	{
		stItem_Show_Shizhuang(){ wProNO = ITEM_SHOW_SHIZHUANG; }
		uint8 bShow;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bShow; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bShow; return cpu; }
	};
	struct stItem_Wrap : public PakHead
	{
		stItem_Wrap(){ wProNO = ITEM_WRAP; }
		ui8 dstbag, dstslot, srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot << dstbag << dstslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot >> dstbag >> dstslot; return cpu; }
	};
	struct stItem_AutoEquip : public PakHead
	{
		stItem_AutoEquip(){ wProNO = ITEM_AUTOEQUIP; }
		ui8 srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_Cancel_Temporary_Enchantment : public PakHead
	{
		stItem_Cancel_Temporary_Enchantment(){ wProNO = ITEM_CANCEL_TEMPORARY_ENCHANTMENT; }
		ui8 srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_Socket_Gems : public PakHead
	{
		stItem_Socket_Gems(){ wProNO = ITEM_SOCKET_GEMS; }
		ui64 itemguid;
		vector<ui64> vGemsguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << itemguid << vGemsguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> itemguid >> vGemsguid; return cpu; }
	};

	struct stItem_AutoStore_Bank : public PakHead	// 将一件物品从银行移至行囊的空格内（自动寻找行囊的空格）
	{
		stItem_AutoStore_Bank(){ wProNO = ITEM_AUTOSTORE_BANK; }
		ui8 srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_AutoBank : public PakHead			// 将一件物品从行囊存入银行的空格内（自动寻找银行的空格）
	{
		stItem_AutoBank(){ wProNO = ITEM_AUTOBANK; }
		ui8 srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_Buy_Bank : public PakHead			// 购买一个银行背包栏位
	{
		stItem_Buy_Bank(){ wProNO = BUY_BANK_SLOT; }

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};
	struct stItem_AutoStore_Bag : public PakHead	// 将一件物品从任何地方移至一个背包的空格中（自动寻找背包中的空格）
	{
		stItem_AutoStore_Bag(){ wProNO = ITEM_AUTOSTORE_BAG; }
		ui8 srcbag, srcslot, dstbag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot << dstbag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot >> dstbag; return cpu; }
	};
	struct stItem_List_Inventory : public PakHead
	{
		stItem_List_Inventory(){ wProNO = LIST_INVENTORY; }
		ui64 vendorguid;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid; return cpu; }
	};
	struct stItem_Buy : PakHead
	{
		stItem_Buy(){ wProNO = ITEM_BUY; }
		ui64 vendorguid;
		ui32 item;
		ui8 type, count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << item << type << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> item >> type >> count; return cpu; }
	};
	struct stItem_BuyInSlot : public PakHead
	{
		stItem_BuyInSlot(){ wProNO = ITEM_BUY_IN_SLOT; }
		ui64 vendorguid, bagguid;
		ui32 item;
		ui8 slot, count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << bagguid << item << slot << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> bagguid >> item >> slot >> count; return cpu; }
	};

	struct stItem_BuyBack : public PakHead
	{
		stItem_BuyBack(){ wProNO = ITEM_BUYBACK; }
		ui64 vendorguid;
		ui32 slot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << slot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> slot; return cpu; }
	};

	struct stItem_Sell : public PakHead
	{
		stItem_Sell(){ wProNO = ITEM_SELL; }
		ui64 vendorguid, itemguid;
		ui8 _count;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itemguid << _count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itemguid >> _count; return cpu; }
	};
	struct stItem_Page_Text_Query : public PakHead
	{
		stItem_Page_Text_Query(){ wProNO = PAGE_TEXT_QUERY; }
		ui32 itemid;
		ui64 guid;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << itemid << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> itemid >> guid; return cpu; }
	};
	struct stItem_Read : public PakHead
	{
		stItem_Read(){ wProNO = ITEM_READ; }
		ui8 bag, slot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bag << slot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bag >> slot; return cpu; }
	};
	struct stItem_Query_Single : PakHead
	{
		stItem_Query_Single(){ wProNO = ITEM_QUERY_SINGLE; }
		ui32 item;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item; return cpu; }
	};
	struct stItem_Drop : public PakHead
	{
		stItem_Drop(){ wProNO = ITEM_DROP; }
		ui8 bag, slot, count;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bag << slot << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bag >> slot >> count; return cpu; }
	};
	struct stItem_PickUp : public PakHead
	{
		stItem_PickUp(){ wProNO = ITEM_PICKUP; }
		ui64 mapitem_guid;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapitem_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapitem_guid; return cpu; }
	};

	struct stItem_AutoEquip_Slot : public PakHead
	{
		stItem_AutoEquip_Slot(){ wProNO = ITEM_AUTOEQUIP_SLOT; }
		ui8 srcbag, srcslot;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_Swap_Inv : public PakHead
	{
		stItem_Swap_Inv(){ wProNO = ITEM_SWAP_INV; }
		ui8 srcslot, dstslot;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcslot << dstslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcslot >> dstslot; return cpu; }
	};
	struct stItem_Swap : PakHead
	{
		stItem_Swap(){ wProNO = ITEM_SWAP; }
		ui8 dstbag, dstslot, srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot << dstbag << dstslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot >> dstbag >> dstslot; return cpu; }
	};
	struct stItem_Destroy : PakHead
	{
		stItem_Destroy(){ wProNO = ITEM_DESTROY; }
		ui8 srcbag, srcslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot; return cpu; }
	};
	struct stItem_Split : public PakHead
	{
		stItem_Split(){ wProNO = ITEM_SPLIT; }
		ui8 srcbag, srcslot, dstbag, dstslot, count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << srcbag << srcslot << dstbag << dstslot << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> srcbag >> srcslot >> dstbag >> dstslot >> count; return cpu; }
	};
	struct stItem_Repair : public PakHead
	{
		stItem_Repair(){ wProNO = ITEM_REPAIR; }
		ui64	npcguid;
		ui64	itemguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << npcguid << itemguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> npcguid >> itemguid; return cpu; }
	};
	struct stItem_Use : public PakHead
	{
		stItem_Use(){ wProNO = ITEM_USE; }
		ui8		bag;
		ui8		slot;
		uint8	MultiCast;
		ui64	item_guid;
		SpellCastTargets targets;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << bag << slot << MultiCast << item_guid << targets; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> bag >> slot >> MultiCast >> item_guid >> targets; return cpu; }
	};
	struct stItem_Open : public PakHead
	{
		stItem_Open(){ wProNO = ITEM_OPEN; }
		ui8 slot, containerslot;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slot << containerslot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slot >> containerslot; return cpu; }
	};
	struct stItem_Name_Query : public PakHead
	{
		stItem_Name_Query(){ wProNO = ITEM_NAME_QUERY; }
		uint32 item_entry;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_entry; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_entry; return cpu; }
	};
}
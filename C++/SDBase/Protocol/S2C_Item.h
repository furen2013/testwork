#pragma once

#include "S2C.h"
namespace MSG_S2C
{

	struct stItem_List_Inventroy : PakHead
	{
		stItem_List_Inventroy(){ wProNO = LIST_INVENTORY; }
		struct stItem
		{
			stItem(){}
			stItem(ui32 c, ui32 id, ui32 info, ui32 maxc, ui32 pri, ui32 md, ui32 bc, ui32 ex):count(c),itemid(id),/*displayinfo(info),maxcount(maxc),price(pri),MaxDurability(md),*/BuyCount(bc),ExtendedCost(ex){}
			ui32	count;
			ui32	itemid;
// 			ui32	displayinfo;
// 			ui32	maxcount;
// 			ui32	price;
// 			ui32	MaxDurability;
			ui32	BuyCount;
			ui32	ExtendedCost;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << count << itemid << /*displayinfo << maxcount << price << MaxDurability << */BuyCount << ExtendedCost; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> count >> itemid >> /*displayinfo >> maxcount >> price >> MaxDurability >> */BuyCount >> ExtendedCost; return cpu; }
		};
		ui64	vendorguid;
		vector<stItem> vItem;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << vItem; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> vItem; return cpu; }
	};	
	struct stItem_Buy : public PakHead
	{
		stItem_Buy(){ wProNO = ITEM_BUY; }
		ui64	vendorguid;
		ui32	itemid;
		ui32	maxcount;
		ui32	count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itemid << maxcount << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itemid >> maxcount >> count ; return cpu; }
	};
	struct stItem_Buy_Failure : public PakHead
	{
		stItem_Buy_Failure(){ wProNO = ITEM_BUY_FAILURE; }
		ui64	vendorguid;
		ui32	itementry;
		uint8 error;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itementry << error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itementry >> error; return cpu; }
	};
	struct stItem_Sell_Failure : public PakHead
	{
		stItem_Sell_Failure(){ wProNO = ITEM_SELL_FAILURE; }
		ui64	vendorguid;
		ui64	itemguid;
		uint8 error;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itemguid << error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itemguid >> error; return cpu; }
	};
	struct stItem_Inv_Change_Failure : public PakHead
	{
		stItem_Inv_Change_Failure(){ wProNO = ITEM_INVENTORY_CHANGE_FAILURE; }
		ui64	guid;
		ui8		error;
		ui32	RequiredLevel;
		ui64	srcguid;
		ui64	dstguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << error << RequiredLevel << srcguid << dstguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> error >> RequiredLevel >> srcguid >> dstguid; return cpu; }
	};
	struct stItem_Sell : public PakHead
	{
		stItem_Sell(){ wProNO = ITEM_SELL;error=0; }
		ui64	vendorguid;
		ui64	itemguid;
		uint8 error;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itemguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itemguid; return cpu; }
	};

	struct stItem_Read_OK : public PakHead
	{
		stItem_Read_OK(){ wProNO = ITEM_READ_OK; }
		ui64	guid;
		ui8	ret;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << ret; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> ret; return cpu; }
	};
	struct stItem_Query_Single_Respone : public PakHead
	{
		stItem_Query_Single_Respone(){ wProNO = ITEM_QUERY_SINGLE_RESPONSE; }
		ItemPrototype type;
		string name;
		string desc;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps.AddBuf(&type, sizeof(type)); cps << name << desc;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu.GetBuf(&type, sizeof(type)); cpu >> name >> desc;return cpu; }
	};

	struct stItemPushResult : public PakHead
	{
		stItemPushResult(){ wProNO = ITEM_PUSH_RESULT; }
		ui64	recivee_guid;
		ui64	ownerguid;
		ui32	received;		//	0=pick,1=from npc
		ui32	created;		//	0=received, 1=created
		ui8		dstbagslot;		//	所在bag所在的slot
		ui8		dstslot;			//	在容器中的slot
		ui32	entry;	
		ui32	suffix;
		ui32	randomprop;
		ui32	count;			// count of items
		ui32	stackcount;	//	所有这种道具的数量
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << recivee_guid << ownerguid << received << created << dstbagslot << dstslot << entry << suffix << randomprop << count << stackcount; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> recivee_guid >> ownerguid >> received >> created >> dstbagslot >> dstslot >> entry >> suffix >> randomprop >> count >> stackcount; return cpu; }
	};
	struct stItem_Name_Query_Response : public PakHead
	{
		stItem_Name_Query_Response(){ wProNO = ITEM_NAME_QUERY_RESPONSE; }
		uint32 item_entry;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_entry << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_entry >> name; return cpu; }
	};


	struct stItemTimeUpdate : public PakHead
	{
		stItemTimeUpdate(){ wProNO = ITEM_TIME_UPDATE; }
		ui64	guid;
		ui32	duration;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << guid << duration; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> guid >> duration; return cpu; }
	};
	struct stItem_Enchant_TimeUpdate : public PakHead
	{
		stItem_Enchant_TimeUpdate(){ wProNO = ITEM_ENCHANT_TIME_UPDATE; }
		ui64	item_guid;
		ui64	owner_guid;
		ui32	duration;
		uint32	Slot;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << item_guid << owner_guid << duration << Slot; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> item_guid >> owner_guid >> duration >> Slot; return cpu; }
	};
	struct stItem_Enchant_Log : public PakHead
	{
		stItem_Enchant_Log(){ wProNO = ITEM_ENCHANTMENT_LOG; }
		ui32	entry;
		ui64	owner_guid;
		ui32	Enchantmentid;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps) << entry << owner_guid << Enchantmentid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) { PakHead::Usn(cpu) >> entry >> owner_guid >> Enchantmentid; return cpu; }
	};
}

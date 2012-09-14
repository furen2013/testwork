#pragma once
#include "C2S.h"
namespace MSG_C2S
{
	//	出售物品,提交拍卖
	struct stAuction_Sell_Item : public PakHead
	{
		stAuction_Sell_Item(){ wProNO = AUCTION_SELL_ITEM; }
		uint64 guid,item;
		uint32 bid,buyout,etime;	// etime is in minutes
		bool yp;					// 是否义拍
		bool is_yuanbao;			// 是否是元宝

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << item << bid << buyout << etime << yp << is_yuanbao; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> item >> bid >> buyout >> etime >> yp >> is_yuanbao; return cpu; }
	};
	//	取消拍卖
	struct stAuction_Remove_Item : public PakHead
	{
		stAuction_Remove_Item(){ wProNO = AUCTION_REMOVE_ITEM; }
		uint64 guid;
		uint32 auction_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << auction_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> auction_id; return cpu; }
	};
	//	列出拍卖行道具,可以设置查找条件
	struct stAuction_List_Items : public PakHead
	{
		stAuction_List_Items(){ wProNO = AUCTION_LIST_ITEMS; }
		ui64 vendorguid;
		// conditions below
		uint32 start_index;
		std::string auctionString;
		uint8 levelRange1, levelRange2, usableCheck;
		int32 inventory_type, itemclass, itemsubclass, rarityCheck;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << start_index << auctionString << levelRange1 << levelRange2 << usableCheck << inventory_type << itemclass << itemsubclass << rarityCheck; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> start_index >> auctionString >> levelRange1 >> levelRange2 >> usableCheck >> inventory_type >> itemclass >> itemsubclass >> rarityCheck; return cpu; }
	};
	//	列出某个玩家拍卖的道具
	struct stAuction_List_Owner_Items : public PakHead
	{
		stAuction_List_Owner_Items(){ wProNO = AUCTION_LIST_OWNER_ITEMS; }
		ui64 vendorguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid; return cpu; }
	};
	//	一口价买进
	struct stAuction_Place_Bid : public PakHead
	{
		stAuction_Place_Bid(){ wProNO = AUCTION_PLACE_BID; }
		uint64 guid;
		uint32 auction_id, price;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << auction_id << price; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> auction_id >> price; return cpu; }
	};
	//	列出自己拍卖的道具
	struct stAuction_List_Bidder_Items : public PakHead
	{
		stAuction_List_Bidder_Items(){ wProNO = AUCTION_LIST_BIDDER_ITEMS; }
		uint64 vendorguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << vendorguid;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> vendorguid;return cpu; }
	};
	//	npc交互,消息,见到拍卖npc发送,暂不用
	struct stAuction_Hello : public PakHead
	{
		stAuction_Hello(){ wProNO = AUCTION_HELLO; }
		uint64 vendorguid;
		ui32 auctionhouse_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << vendorguid << auctionhouse_id;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> vendorguid >> auctionhouse_id;return cpu; }
	};

	struct stShop_Buy : public PakHead
	{
		stShop_Buy(){ wProNO = CMSG_SHOP_BUY; }
		uint32 id;
		uint8 buytype;
		uint8 cnt;
		string gift_to_name;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << id << buytype << gift_to_name << cnt; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> id >> buytype >> gift_to_name >> cnt; return cpu; }
	};
	struct stShop_AddToCategory : public PakHead
	{
		stShop_AddToCategory(){ wProNO = CMSG_SHOP_ADDTOCATEGORY; }
		uint32 id;
		uint8 buytype;		
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << id << buytype; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> id >> buytype; return cpu; }
	};
	struct stShop_GetList : public PakHead
	{
		stShop_GetList(){ wProNO = CMSG_SHOP_GETLIST; }
	};
}
#pragma once

#include "S2C.h"
#include "../Public/MailDef.h"
namespace MSG_S2C
{
	//	����Э��,ֻ������������ĵ���
	struct stAuction_Item
	{
		ui32 auction_id;
		ui32 entryid;
		ItemExtraData extra;
		ui32 stack_count;
		ui64 owner_guid;
		string owner_name;
		ui32 HighestBid;
		ui32 Nextbidmodify;
		ui32 BuyoutPrice;
		ui32 timeleft;
		ui64 Lastbidder;
		bool yp;
		bool is_yuanbao;
		CPacketSn& Sn(CPacketSn& cps) const {	cps << auction_id << entryid << stack_count << owner_guid << owner_name << HighestBid <<  Nextbidmodify << BuyoutPrice << timeleft << Lastbidder << yp << is_yuanbao; cps.AddBuf(&extra, sizeof(extra)); cps << yp << is_yuanbao; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> auction_id >> entryid >> stack_count >> owner_guid >> owner_name >> HighestBid >>  Nextbidmodify >> BuyoutPrice >> timeleft >> Lastbidder >> yp >> is_yuanbao; cpu.GetBuf(&extra, sizeof(extra)); cpu >> yp >> is_yuanbao; return cpu; }
	};
	//	���������Ľ��,����enum AUCTIONRESULT
	struct stAuction_Command_Result : public PakHead
	{
		stAuction_Command_Result(){ wProNO = AUCTION_COMMAND_RESULT;auction_error = 0; }
		ui32	auction_id;
		ui32	auction_result;
		ui32	auction_error;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << auction_id << auction_result << auction_error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> auction_id >> auction_result >> auction_error; return cpu; }
	};
	//	�����е����б�
	struct stAuction_List_Result : public PakHead
	{
		stAuction_List_Result(){ wProNO = AUCTION_LIST_RESULT; }
		vector<stAuction_Item> vItems;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vItems ; return cpu; }
	};
	//	���س�����߾��ĵ����
	struct stAuction_Bidder_Notifycation : public PakHead
	{
		stAuction_Bidder_Notifycation(){ wProNO = AUCTION_BIDDER_NOTIFICATION; }
		ui32	auctionhouse_id;
		ui32	aucion_id;
		ui32	itementry;
		ui64	HighestBidderguid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << auctionhouse_id << aucion_id << itementry << HighestBidderguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> auctionhouse_id >> aucion_id >> itementry >> HighestBidderguid ; return cpu; }
	};

	struct stAuction_Owner_Notifycation : public PakHead
	{
		stAuction_Owner_Notifycation(){ wProNO = AUCTION_OWNER_NOTIFICATION; }
		ui64	vendorguid;
		ui32	itemid;
		ui32	maxcount;
		ui32	count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vendorguid << itemid << maxcount << count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vendorguid >> itemid >> maxcount >> count ; return cpu; }
	};
	//	��Ҿ��ĵĵ����б�
	struct stAuction_Bidder_List_Result : public PakHead
	{
		stAuction_Bidder_List_Result(){ wProNO = AUCTION_BIDDER_LIST_RESULT; }
		vector<stAuction_Item> vItems;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vItems ; return cpu; }
	};
	struct stAuction_Owner_List_Result : public PakHead
	{
		stAuction_Owner_List_Result(){ wProNO = AUCTION_OWNER_LIST_RESULT; }
		vector<stAuction_Item> vItems;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vItems; return cpu; }
	};
	struct stAuction_Hello : public PakHead
	{
		stAuction_Hello(){ wProNO = AUCTION_HELLO; }
		uint64 vendorguid;
		ui32 auctionhouse_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << vendorguid << auctionhouse_id;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> vendorguid >> auctionhouse_id;return cpu; }
	};	


	struct stShopItem
	{
		uint32 id;						//	�б�id
		uint32 itementry;				//	����entry
		uint32 itemcnt;					//	��������
		uint8 category;					//	��������
		uint8 subcategory;				//	����������
		uint8 buytype[5];				//	��������
		uint32 buyprice[5];				//	�������Ͷ�Ӧ�ļ۸�
		CPacketSn& Sn(CPacketSn& cps) const {	cps.AddBuf(this, sizeof(stShopItem)); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu.GetBuf(this, sizeof(stShopItem)); return cpu; }
	};

	struct stShopHotItem
	{
		uint32 id;
		CPacketSn& Sn(CPacketSn& cps) const {	cps << id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> id; return cpu; }
	};
	struct stShop_ItemList : public PakHead
	{
		stShop_ItemList(){ wProNO = SHOP_ITEMLIST; }
		vector<stShopItem> vItems;
		vector<stShopHotItem> vHotItems;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << vItems << vHotItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> vItems >> vHotItems; return cpu; }
	};

	enum AUCTIONRESULT
	{
		AUCTION_CREATE,
		AUCTION_CANCEL,
		AUCTION_BID,
		AUCTION_BUYOUT,
	};
	enum AUCTIONRESULTERROR
	{
		AUCTION_ERROR_NONE,
		AUCTION_ERROR_UNK1,
		AUCTION_ERROR_INTERNAL,
		AUCTION_ERROR_MONEY,
		AUCTION_ERROR_ITEM,
	};
}

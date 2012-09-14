#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stMail_Text_Query : public PakHead		// 查询邮件文本内容
	{
		stMail_Text_Query(){ wProNO = MAIL_TEXT_QUERY; }
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id; return cpu; }
	};
	struct stMail_Get_List: public PakHead			// 暂时不使用
	{
		stMail_Get_List(){ wProNO = MAIL_GET_LIST; }
	};
	struct stMail_Send : public PakHead				// 发送邮件请求
	{
		stMail_Send(){ wProNO = MAIL_SEND; }
		uint64 gameobject;		// 不使用
		string recepient;		// 接受人
		string subject;			// 主题
		string body;			// 内容
		uint32 stationary;		// 暂时不使用
		uint32 money;			// 发送的钱
		uint32 cod;				// 付款取信
		struct stMailItem
		{
			uint8 itemslot;		// 暂时不使用
			uint64 itemguid;	// 发送道具的guid
			CPacketSn& Sn(CPacketSn& cps) const {cps << itemslot<<itemguid; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> itemslot>>itemguid; return cpu; }
		};
		vector<stMailItem> vMailItems;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << gameobject<<recepient<<subject<<body<<stationary<<money<<cod<<vMailItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> gameobject>>recepient>>subject>>body>>stationary>>money>>cod>>vMailItems; return cpu; }
	};
	struct stMail_Mark_As_Read : public PakHead		// 标记邮件已阅读
	{
		stMail_Mark_As_Read(){ wProNO = MAIL_MARK_AS_READ; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Delete : public PakHead			// 删除邮件
	{
		stMail_Delete(){ wProNO = MAIL_DELETE; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Take_Item : public PakHead		// 拿取邮件中的道具
	{
		stMail_Take_Item(){ wProNO = MAIL_TAKE_ITEM; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		uint32 lowguid;			// 道具ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox << lowguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox >> lowguid; return cpu; }
	};
	struct stMail_Take_Money : public PakHead		// 拿取邮件中的钱
	{
		stMail_Take_Money(){ wProNO = MAIL_TAKE_MONEY; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Return_To_Sender : public PakHead	// 退还邮件给发送者
	{
		stMail_Return_To_Sender(){ wProNO = MAIL_RETURN_TO_SENDER; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Create_Text_Item : public PakHead	// 拿取邮件中的信纸
	{
		stMail_Create_Text_Item(){ wProNO = MAIL_CREATE_TEXT_ITEM; }
		uint64 mailbox;			// 暂时不使用
		uint32 message_id;		// 邮件ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Query_Next_Time : public PakHead	// 暂时不使用
	{
		stMail_Query_Next_Time(){ wProNO = MAIL_QUERY_NEXT_TIME; }
	};

}

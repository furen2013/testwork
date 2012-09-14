#pragma once
#include "S2C.h"

namespace MSG_S2C
{

	struct stMail_Text_Query_Response : public PakHead		// 查询邮件文字内容回馈
	{
		stMail_Text_Query_Response(){ wProNO = MAIL_TEXT_QUERY_RESPONSE; }
		uint32 message_id;		// 邮件ID
		string body;			// 邮件文字内容
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << body; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> body; return cpu; }
	};
	struct stMail_Received : public PakHead		// 收到邮件
	{
		stMail_Received(){ wProNO = MAIL_RECEIVED; }
		uint32 unk;				// 暂时不使用
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << unk; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> unk; return cpu; }
	};

	struct stMail_List_Result : public PakHead	// 邮件列表结果
	{
		stMail_List_Result(){ wProNO = MAIL_LIST_RESULT; }
		struct stMail 
		{
			uint32	message_id;		// 邮件ID
			ui8		message_type;	// 邮件类型 defined in MailDef.h ( enum MailTypes )
			ui64	sender_guid;	// 发送者guid
			ui32	cod;			// 付款取信
			ui32	stationary;		// 暂时不使用
			ui32	money;			// 含多少金钱
			ui32	expire_time;	// 到期时间
			string	subject;		// 主题
			uint8	read_flag;		// 是否阅读过
			bool	yp;				// 是否是义拍邮件
			bool	is_yuanbao;		// 是否是元宝
			std::string sender_name;// 发送者名字
			struct stMailItem
			{
				ui64	guid;	// 道具guid
				ui32	entry;	// 道具的entry
				ItemExtraData extra;
				ui32	stack_count;		// 堆叠个数
				ui32	ChargesLeft;		// 次数剩余
				ui32	maxdurability;		// 最大耐久度
				ui32	durability;			// 当前耐久度
				CPacketSn& Sn(CPacketSn& cps) const {cps << guid <<entry<<stack_count<<ChargesLeft<<maxdurability<<durability;cps.AddBuf(&extra, sizeof(extra)); return cps; }
				CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> guid >>entry>>stack_count>>ChargesLeft>>maxdurability>>durability;cpu.GetBuf(&extra, sizeof(extra)); return cpu; }
			};
			vector<stMailItem> vMailItems;
			CPacketSn& Sn(CPacketSn& cps) const {cps << message_id <<message_type<<sender_guid<<cod<<stationary<<money<<expire_time<<subject<<read_flag<<yp<<is_yuanbao<<sender_name<<vMailItems;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> message_id >>message_type>>sender_guid>>cod>>stationary>>money>>expire_time>>subject>>read_flag>>yp>>is_yuanbao>>sender_name>>vMailItems;return cpu; }
		};
		vector<stMail> vMails;
		ui64 npc_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vMails << npc_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vMails >> npc_guid; return cpu; }
	};
	struct stMail_Send_Result : public PakHead	// 发送邮件结果
	{
		stMail_Send_Result(){ wProNO = MAIL_SEND_RESULT; }
		uint32 message_id;		// 邮件ID
		ui32	res;			// 邮件命令 Defined in MailDef.h ( enum MailCMD )
		ui32	result;			// 错误码 Defined in MailDef.h (enum MailError )

		// for take item
		ui64	item_guid;		// 拿取的道具guid
		ui32	stack_count;	// 堆叠次数
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << res << result << item_guid << stack_count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> res >> result >> item_guid >> stack_count; return cpu; }
	};
	struct stMail_Query_Next_Time : public PakHead	// 暂时不使用
	{
		stMail_Query_Next_Time(){ wProNO = MAIL_QUERY_NEXT_TIME; }
		struct stMail
		{
			ui64	sender_guid;
			ui32	stationary;
			ui32	delivery_time;
			CPacketSn& Sn(CPacketSn& cps) const {cps << sender_guid<<stationary<<delivery_time;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> sender_guid>>stationary>>delivery_time;return cpu; }
		};
		vector<stMail> vMails;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vMails; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vMails; return cpu; }
	};

	struct stMail_Error : public PakHead
	{
		stMail_Error(){ wProNO = MAIL_ERROR; }
		ui32 error;
		CPacketSn& Sn(CPacketSn& cps) const { PakHead::Sn(cps); cps << error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> error; return cpu;}
	};
}

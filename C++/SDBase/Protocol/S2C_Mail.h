#pragma once
#include "S2C.h"

namespace MSG_S2C
{

	struct stMail_Text_Query_Response : public PakHead		// ��ѯ�ʼ��������ݻ���
	{
		stMail_Text_Query_Response(){ wProNO = MAIL_TEXT_QUERY_RESPONSE; }
		uint32 message_id;		// �ʼ�ID
		string body;			// �ʼ���������
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << body; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> body; return cpu; }
	};
	struct stMail_Received : public PakHead		// �յ��ʼ�
	{
		stMail_Received(){ wProNO = MAIL_RECEIVED; }
		uint32 unk;				// ��ʱ��ʹ��
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << unk; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> unk; return cpu; }
	};

	struct stMail_List_Result : public PakHead	// �ʼ��б���
	{
		stMail_List_Result(){ wProNO = MAIL_LIST_RESULT; }
		struct stMail 
		{
			uint32	message_id;		// �ʼ�ID
			ui8		message_type;	// �ʼ����� defined in MailDef.h ( enum MailTypes )
			ui64	sender_guid;	// ������guid
			ui32	cod;			// ����ȡ��
			ui32	stationary;		// ��ʱ��ʹ��
			ui32	money;			// �����ٽ�Ǯ
			ui32	expire_time;	// ����ʱ��
			string	subject;		// ����
			uint8	read_flag;		// �Ƿ��Ķ���
			bool	yp;				// �Ƿ��������ʼ�
			bool	is_yuanbao;		// �Ƿ���Ԫ��
			std::string sender_name;// ����������
			struct stMailItem
			{
				ui64	guid;	// ����guid
				ui32	entry;	// ���ߵ�entry
				ItemExtraData extra;
				ui32	stack_count;		// �ѵ�����
				ui32	ChargesLeft;		// ����ʣ��
				ui32	maxdurability;		// ����;ö�
				ui32	durability;			// ��ǰ�;ö�
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
	struct stMail_Send_Result : public PakHead	// �����ʼ����
	{
		stMail_Send_Result(){ wProNO = MAIL_SEND_RESULT; }
		uint32 message_id;		// �ʼ�ID
		ui32	res;			// �ʼ����� Defined in MailDef.h ( enum MailCMD )
		ui32	result;			// ������ Defined in MailDef.h (enum MailError )

		// for take item
		ui64	item_guid;		// ��ȡ�ĵ���guid
		ui32	stack_count;	// �ѵ�����
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << res << result << item_guid << stack_count; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> res >> result >> item_guid >> stack_count; return cpu; }
	};
	struct stMail_Query_Next_Time : public PakHead	// ��ʱ��ʹ��
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

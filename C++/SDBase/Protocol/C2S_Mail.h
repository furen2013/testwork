#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stMail_Text_Query : public PakHead		// ��ѯ�ʼ��ı�����
	{
		stMail_Text_Query(){ wProNO = MAIL_TEXT_QUERY; }
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id; return cpu; }
	};
	struct stMail_Get_List: public PakHead			// ��ʱ��ʹ��
	{
		stMail_Get_List(){ wProNO = MAIL_GET_LIST; }
	};
	struct stMail_Send : public PakHead				// �����ʼ�����
	{
		stMail_Send(){ wProNO = MAIL_SEND; }
		uint64 gameobject;		// ��ʹ��
		string recepient;		// ������
		string subject;			// ����
		string body;			// ����
		uint32 stationary;		// ��ʱ��ʹ��
		uint32 money;			// ���͵�Ǯ
		uint32 cod;				// ����ȡ��
		struct stMailItem
		{
			uint8 itemslot;		// ��ʱ��ʹ��
			uint64 itemguid;	// ���͵��ߵ�guid
			CPacketSn& Sn(CPacketSn& cps) const {cps << itemslot<<itemguid; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{cpu >> itemslot>>itemguid; return cpu; }
		};
		vector<stMailItem> vMailItems;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << gameobject<<recepient<<subject<<body<<stationary<<money<<cod<<vMailItems; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> gameobject>>recepient>>subject>>body>>stationary>>money>>cod>>vMailItems; return cpu; }
	};
	struct stMail_Mark_As_Read : public PakHead		// ����ʼ����Ķ�
	{
		stMail_Mark_As_Read(){ wProNO = MAIL_MARK_AS_READ; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Delete : public PakHead			// ɾ���ʼ�
	{
		stMail_Delete(){ wProNO = MAIL_DELETE; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Take_Item : public PakHead		// ��ȡ�ʼ��еĵ���
	{
		stMail_Take_Item(){ wProNO = MAIL_TAKE_ITEM; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		uint32 lowguid;			// ����ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox << lowguid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox >> lowguid; return cpu; }
	};
	struct stMail_Take_Money : public PakHead		// ��ȡ�ʼ��е�Ǯ
	{
		stMail_Take_Money(){ wProNO = MAIL_TAKE_MONEY; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Return_To_Sender : public PakHead	// �˻��ʼ���������
	{
		stMail_Return_To_Sender(){ wProNO = MAIL_RETURN_TO_SENDER; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Create_Text_Item : public PakHead	// ��ȡ�ʼ��е���ֽ
	{
		stMail_Create_Text_Item(){ wProNO = MAIL_CREATE_TEXT_ITEM; }
		uint64 mailbox;			// ��ʱ��ʹ��
		uint32 message_id;		// �ʼ�ID
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << message_id << mailbox; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> message_id >> mailbox; return cpu; }
	};
	struct stMail_Query_Next_Time : public PakHead	// ��ʱ��ʹ��
	{
		stMail_Query_Next_Time(){ wProNO = MAIL_QUERY_NEXT_TIME; }
	};

}

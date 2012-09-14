#pragma once
#include "PacketDef.h"
#include "../Public/PublicDef.h"
namespace MSG_LS2C
{
	using namespace SDBase;
	enum
	{
		VERSION_ACK = MSG_BASE_LS2C,
		LOGIN_ACK,
		CHANGEPASSWORD_ACK,
		GROUP_SEL_ACK
	};

	struct stVersionAck : public PakHead
	{
		stVersionAck()
		{
			wProNO = VERSION_ACK;
		}
		
		uint32 encrypt_table;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << encrypt_table; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> encrypt_table; return cpu;}
	};

	struct stLoginAck : public PakHead
	{
		enum
		{
			LOGIN_OK = 0,					//�ɹ�
			LOGIN_USER_ONLINE =1,			//��ǰ�û�����
			LOGIN_PASSWORD_ERROR =11,		//�������
			LOGIN_USER_NOT_FOUND =12,		//�û���������
			LOGIN_DATABASE_EXCEPTION=13,	//���ݿ��쳣
			LOGIN_NOT_ENOUGH_POINT_OR_EXPIRE=14,	//�㿨��������µ���
			LOGIN_VERSION_NOT_MATCH,
			LOGIN_ACCOUNT_LOCKED,
			LOGIN_SERVER_CANNT_CONNECT,		//�������޷�����
			LOGIN_USER_BANED,				//�˺��Ѿ�����ͣ
		};

		stLoginAck()
		{
			wProNO = LOGIN_ACK;
		}

		struct tagGroup
		{
			ui32 limit;
			ui32 online;
			string strGroupName;

			CPacketSn& Sn(CPacketSn& cps) const {cps << limit << online << strGroupName; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu) {cpu >> limit >> online >> strGroupName; return cpu;}
		};

		ui8		nStat;						//	��½���صĽ��
		ui32	nAccountId;
		ui32	nSessionID;
		vector<tagGroup> vGroup;
		int32	points;
		uint32	expire;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps)  << nStat << nAccountId << nSessionID << vGroup << points << expire; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu) >> nStat >> nAccountId >> nSessionID >> vGroup >> points >> expire; return cpu;}
	};

	struct stChangePassAck : public PakHead
	{
		stChangePassAck()
		{
			wProNO = CHANGEPASSWORD_ACK;
		}
		ui8		nStat;					//byErrCode

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nStat; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nStat; return cpu;}
	};

	struct stGroupSelAck : public PakHead
	{
		enum error
		{
			OK = 1,
			FULL,
			OFFLINE,
		};
		stGroupSelAck()
		{
			wProNO = GROUP_SEL_ACK;
		}
		ui8		nStat;					//byErrCode
		ui32	IP;
		ui16	port;

		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps) << nStat << IP << port; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu) >> nStat >> IP >> port; return cpu;}
	};
}

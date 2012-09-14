#pragma once

#include "S2C.h"
enum CHANNEL_FLAGS
{
	CHANNEL_FLAG_NONE				= 0x00,
	CHANNEL_FLAG_OWNER				= 0x01,
	CHANNEL_FLAG_MODERATOR			= 0x02,
	CHANNEL_FLAG_VOICED				= 0x04,
	CHANNEL_FLAG_MUTED				= 0x08,
	CHANNEL_FLAG_CUSTOM				= 0x10,
	CHANNEL_FLAG_MICROPHONE_MUTE	= 0x20,
};

enum CHANNEL_NOTIFY_FLAGS
{
	CHANNEL_NOTIFY_FLAG_JOINED		= 0x00,
	CHANNEL_NOTIFY_FLAG_LEFT		= 0x01,
	CHANNEL_NOTIFY_FLAG_YOUJOINED	= 0x02,
	CHANNEL_NOTIFY_FLAG_YOULEFT		= 0x03,
	CHANNEL_NOTIFY_FLAG_WRONGPASS	= 0x04,
	CHANNEL_NOTIFY_FLAG_NOTON		= 0x05,
	CHANNEL_NOTIFY_FLAG_NOTMOD		= 0x06,
	CHANNEL_NOTIFY_FLAG_SETPASS		= 0x07,
	CHANNEL_NOTIFY_FLAG_CHGOWNER	= 0x08,
	CHANNEL_NOTIFY_FLAG_NOT_ON_2	= 0x09,
	CHANNEL_NOTIFY_FLAG_NOT_OWNER	= 0x0A,
	CHANNEL_NOTIFY_FLAG_WHO_OWNER	= 0x0B,
	CHANNEL_NOTIFY_FLAG_MODE_CHG	= 0x0C,
	CHANNEL_NOTIFY_FLAG_ENABLE_ANN	= 0x0D,
	CHANNEL_NOTIFY_FLAG_DISABLE_ANN	= 0x0E,
	CHANNEL_NOTIFY_FLAG_MODERATED	= 0x0F,
	CHANNEL_NOTIFY_FLAG_UNMODERATED	= 0x10,
	CHANNEL_NOTIFY_FLAG_YOUCANTSPEAK= 0x11,
	CHANNEL_NOTIFY_FLAG_KICKED		= 0x12,
	CHANNEL_NOTIFY_FLAG_YOURBANNED	= 0x13,
	CHANNEL_NOTIFY_FLAG_BANNED		= 0x14,
	CHANNEL_NOTIFY_FLAG_UNBANNED	= 0x15,
	CHANNEL_NOTIFY_FLAG_UNK_1		= 0x16,
	CHANNEL_NOTIFY_FLAG_ALREADY_ON	= 0x17,
	CHANNEL_NOTIFY_FLAG_INVITED		= 0x18,
	CHANNEL_NOTIFY_FLAG_WRONG_FACT	= 0x19,
	CHANNEL_NOTIFY_FLAG_UNK_2		= 0x1A,
	CHANNEL_NOTIFY_FLAG_UNK_3		= 0x1B,
	CHANNEL_NOTIFY_FLAG_UNK_4		= 0x1C,
	CHANNEL_NOTIFY_FLAG_YOU_INVITED	= 0x1D,
	CHANNEL_NOTIFY_FLAG_UNK_5		= 0x1E,
	CHANNEL_NOTIFY_FLAG_UNK_6		= 0x1F,
	CHANNEL_NOTIFY_FLAG_UNK_7		= 0x20,
	CHANNEL_NOTIFY_FLAG_NOT_IN_LFG	= 0x21,
	CHANNEL_NOTIFY_FLAG_VOICE_ON	= 0x22,
	CHANNEL_NOTIFY_FLAG_VOICE_OFF	= 0x23,
};

namespace MSG_S2C
{
	struct stChannel_List : public PakHead
	{
		stChannel_List(){ wProNO = CHANNEL_LIST; }
		ui8	flag;
		string name;
		struct stChannel
		{
			ui64 member_guid;
			ui32 member_flag;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << member_guid << member_flag;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> member_guid >> member_flag;return cpu; }
		};
		vector<stChannel> vChannels;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << flag << name<<vChannels;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> flag >> name>>vChannels;return cpu; }
	};	
	struct stChannel_Notify : public PakHead
	{
		stChannel_Notify(){ wProNO = CHANNEL_NOTIFY; }
		ui64	guid;
		ui8	nofify_flag;
		ui8 old_member_flag;
		ui8 member_flag;
		string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << guid<<nofify_flag<<old_member_flag<<member_flag<< name;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> guid>>nofify_flag>>old_member_flag>>member_flag>> name;return cpu; }
	};	
	struct stChannel_Num_Member_Query_Response : public PakHead
	{
		stChannel_Num_Member_Query_Response(){ wProNO = CHANNEL_NUM_MEMBERS_QUERY_RESPONSE; }
		string	channle_name;
		ui8		flag;
		ui32	player_count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << channle_name << flag << player_count;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> channle_name >> flag >> player_count;return cpu; }
	};	
	struct stChannel_Voice_Available : public PakHead
	{
		stChannel_Voice_Available(){ wProNO = CHANNEL_AVAILABLE_VOICE; }
		string	channle_name;
		ui64	guid;
		ui8		type;// 00=custom,03=party,04=raid
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << channle_name << guid;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> channle_name >> guid;return cpu; }
	};	
	struct stChannel_Voice_Session : public PakHead
	{
		stChannel_Voice_Session(){ wProNO = CHANNEL_VOICE_SESSION; }
		ui64	channel_id;
		ui32 voice_channel_id;
		uint8 channel_type;// (0=channel,2=party)
		string	channel_name;
		uint8 encryptionKey[16];
		ui32 VoiceServerIP;
		ui16   VoiceServerPort;
		struct stMember
		{
			ui64	guid;
			ui32	count;
			ui32	unk;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << count << guid << unk;return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> count >> guid >> unk;return cpu; }
		};
		vector<stMember> vMember;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);	cps << channel_name << channel_id << voice_channel_id<< channel_type;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);	cpu >> channel_name >> channel_id >> voice_channel_id>> channel_type;return cpu; }
	};	

}


#pragma once

#include "S2C.h"

enum ChatMsg
{
	CHAT_MSG_ADDON									= -1,
	CHAT_MSG_SAY									= 1,
	CHAT_MSG_PARTY									= 2,
	CHAT_MSG_RAID									= 3,
	CHAT_MSG_GUILD									= 4,
	CHAT_MSG_OFFICER								= 5,
	CHAT_MSG_YELL									= 6,
	CHAT_MSG_WHISPER								= 7,
	CHAT_MSG_WHISPER_MOB							= 8,
	CHAT_MSG_WHISPER_INFORM							= 9,
	CHAT_MSG_EMOTE									= 10,
	CHAT_MSG_TEXT_EMOTE								= 11,
	CHAT_MSG_MONSTER_SAY							= 12,
	CHAT_MSG_MONSTER_PARTY							= 13,
	CHAT_MSG_MONSTER_YELL							= 14,
	CHAT_MSG_MONSTER_WHISPER						= 15,
	CHAT_MSG_MONSTER_EMOTE							= 16,
	CHAT_MSG_CHANNEL								= 17,
	CHAT_MSG_CHANNEL_JOIN							= 18,
	CHAT_MSG_CHANNEL_LEAVE							= 19,
	CHAT_MSG_CHANNEL_LIST							= 20,
	CHAT_MSG_CHANNEL_NOTICE							= 21,
	CHAT_MSG_CHANNEL_NOTICE_USER					= 22,
	CHAT_MSG_AFK									= 23,
	CHAT_MSG_DND									= 24,
	CHAT_MSG_IGNORED								= 25,
	CHAT_MSG_SKILL									= 26,
	CHAT_MSG_LOOT									= 27,
	CHAT_MSG_SYSTEM									= 28,
	CHAT_MSG_XIAOLABA								= 29,//29
	CHAT_MSG_DALABA									= 30,//30
	CHAT_MSG_SYSTEM_BROADCAST						= 31,
	//32
	//33
	//34
	//35
	//36
	//37
	//38
	CHAT_MSG_BG_EVENT_NEUTRAL						= 36,
	CHAT_MSG_BG_EVENT_ALLIANCE						= 37,
	CHAT_MSG_BG_EVENT_HORDE							= 38,
	CHAT_MSG_COMBAT_FACTION_CHANGE					= 38,
	CHAT_MSG_RAID_LEADER							= 39,
	CHAT_MSG_RAID_WARNING							= 40,
	CHAT_MSG_RAID_WARNING_WIDESCREEN				= 41,
	//42
	CHAT_MSG_FILTERED								= 43,
	CHAT_MSG_BATTLEGROUND							= 44,
	CHAT_MSG_BATTLEGROUND_LEADER					= 45,
	CHAT_MSG_RESTRICTED								= 46,	
};
namespace MSG_S2C
{
	struct stChat_Message : public PakHead
	{
		stChat_Message(){ wProNO = CHAT_MESSAGE; }
		uint8 type;uint64 guid;string creature_name;uint8 gm_tag; uint8 flag;string channel_name; uint8 channel_id;string txt;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type << guid << creature_name << gm_tag << channel_name << flag << channel_id << txt; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type >> guid >> creature_name >> gm_tag >> channel_name >> flag >> channel_id >> txt; return cpu; }
	};	

	struct stChat_Emote : public PakHead
	{
		stChat_Emote(){ wProNO = EMOTE; }
		uint64 guid;ui32 emote;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << emote; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> emote; return cpu; }
	};	
	struct stChat_EmoteText : public PakHead
	{
		stChat_EmoteText(){ wProNO = CHAT_EMOTE_TEXT; }
		uint64 guid;ui32 emote;string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << emote << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> emote >> name; return cpu; }
	};	
	struct stChat_Not_Found_Player : public PakHead
	{
		stChat_Not_Found_Player(){ wProNO = CHAT_PLAYER_NOT_FOUND; }
		string player_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name; return cpu; }
	};	
	struct stChat_Report_Spam_Response : public PakHead
	{
		stChat_Report_Spam_Response(){ wProNO = SMSG_REPORT_SPAM_RESPONSE; }
	};	
	
}

#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stChat_Message : PakHead
	{
		stChat_Message(){ wProNO = CHAT_MESSAGE; }
		uint8 type;uint64 guid;string creature_name;uint8 gm_tag;uint8 flag;string txt;string channel_name;string reason;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type << guid << creature_name << gm_tag << flag << txt << channel_name << reason; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type >> guid >> creature_name >> gm_tag >> flag >> txt >> channel_name >> reason; return cpu; }
	};	

	struct stChat_EmoteText : public PakHead
	{
		stChat_EmoteText(){ wProNO = CHAT_TEXT_EMOTE; }
		uint64 guid;ui32 emote;string name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << emote << name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> emote >> name; return cpu; }
	};	
	struct stChat_Report_Spam : public PakHead
	{
		stChat_Report_Spam(){ wProNO = CHAT_REPORT_SPAM; }
		uint64 reportedGuid;
		uint32 messagetype;
		std::string message;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << reportedGuid << messagetype << message; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> reportedGuid >> messagetype >> message; return cpu; }
	};	
	
}

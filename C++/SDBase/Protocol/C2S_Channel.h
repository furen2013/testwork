#pragma once
#include "C2S.h"
namespace MSG_C2S
{
	struct stChannel_Join : public PakHead
	{
		stChannel_Join(){ wProNO = CHANNEL_JOIN; }
		string channelname,pass;
		uint32 dbc_id;
		uint16 crap;		// crap = some sort of channel type?
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << pass << dbc_id << crap; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> pass >> dbc_id >> crap; return cpu; }
	};	
	struct stChannel_Leave : public PakHead
	{
		stChannel_Leave(){ wProNO = CHANNEL_LEAVE; }
		string channelname;
		uint32 code;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << code; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> code; return cpu; }
	};	
	struct stChannel_List : public PakHead
	{
		stChannel_List(){ wProNO = CHANNEL_LIST; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Password : public PakHead
	{
		stChannel_Password(){ wProNO = CHANNEL_PASSWORD; }
		string channelname,pass;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << pass; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> pass; return cpu; }
	};	
	struct stChannel_Set_Owner : public PakHead
	{
		stChannel_Set_Owner(){ wProNO = CHANNEL_SET_OWNER; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Owner : public PakHead
	{
		stChannel_Owner(){ wProNO = CHANNEL_OWNER; }
		string channelname,pass;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << pass; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> pass; return cpu; }
	};	
	struct stChannel_Moderator : public PakHead
	{
		stChannel_Moderator(){ wProNO = CHANNEL_MODERATOR; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_UnModerator : public PakHead
	{
		stChannel_UnModerator(){ wProNO = CHANNEL_UNMODERATOR; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Mute : public PakHead
	{
		stChannel_Mute(){ wProNO = CHANNEL_MUTE; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_UnMute : public PakHead
	{
		stChannel_UnMute(){ wProNO = CHANNEL_UNMUTE; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Invite : public PakHead
	{
		stChannel_Invite(){ wProNO = CHANNEL_INVITE; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Kick : public PakHead
	{
		stChannel_Kick(){ wProNO = CHANNEL_KICK; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Ban : public PakHead
	{
		stChannel_Ban(){ wProNO = CHANNEL_BAN; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_UnBan : public PakHead
	{
		stChannel_UnBan(){ wProNO = CHANNEL_UNBAN; }
		string channelname,newp;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname << newp; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname >> newp; return cpu; }
	};	
	struct stChannel_Announcements : public PakHead
	{
		stChannel_Announcements(){ wProNO = CHANNEL_ANNOUNCEMENTS; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Moderate : public PakHead
	{
		stChannel_Moderate(){ wProNO = CHANNEL_MODERATE; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Silent_Voice : public PakHead
	{
		stChannel_Silent_Voice(){ wProNO = CHANNEL_SILENT_VOICE; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Silent_All : public PakHead
	{
		stChannel_Silent_All(){ wProNO = CHANNEL_SILENT_ALL; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_UnSilent_All : public PakHead
	{
		stChannel_UnSilent_All(){ wProNO = CHANNEL_UNSILENT_ALL; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Get_Roster_Info : public PakHead
	{
		stChannel_Get_Roster_Info(){ wProNO = CHANNEL_GET_ROSTER_INFO; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
	struct stChannel_Num_Member_Query : public PakHead
	{
		stChannel_Num_Member_Query(){ wProNO = CHANNEL_NUM_MEMBERS_QUERY; }
		string channelname;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << channelname; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> channelname; return cpu; }
	};	
}
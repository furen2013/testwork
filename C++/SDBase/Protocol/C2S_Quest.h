#pragma once

#include "C2S.h"
namespace MSG_C2S
{
	struct stQuest_Query : PakHead
	{
		stQuest_Query(){ wProNO = QUEST_QUERY; }
		uint32 quest_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> quest_id; return cpu; }
	};	
	
	struct stQuestGiver_Stats_Query : PakHead
	{
		stQuestGiver_Stats_Query(){ wProNO = QUESTGIVER_STATUS_QUERY; }
		ui64	guid;
		uint32 quest_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id; return cpu; }
	};	
	struct stQuestGiver_Hello : PakHead
	{
		stQuestGiver_Hello(){ wProNO = QUESTGIVER_HELLO; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stQuestGiver_Query_Quest : PakHead
	{
		stQuestGiver_Query_Quest(){ wProNO = QUESTGIVER_QUERY_QUEST; }
		uint64 guid;
		uint32 quest_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id; return cpu; }
	};	
	struct stQuestGiver_Accept_Quest : PakHead
	{
		stQuestGiver_Accept_Quest(){ wProNO = QUESTGIVER_ACCEPT_QUEST; }
		uint64 guid;
		uint32 quest_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id; return cpu; }
	};	
	struct stQuestGiver_Cancel : PakHead
	{
		stQuestGiver_Cancel(){ wProNO = QUESTGIVER_CANCEL; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};	
	struct stQuestLog_Remove_Quest : PakHead
	{
		uint8 quest_slot;
		stQuestLog_Remove_Quest(){ wProNO = QUESTLOG_REMOVE_QUEST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << quest_slot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> quest_slot; return cpu; }
	};	
	struct stQuestGiver_Request_Reward : PakHead
	{
		uint64 guid;
		uint32 quest_id;
		stQuestGiver_Request_Reward(){ wProNO = QUESTGIVER_REQUEST_REWARD; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id; return cpu; }
	};	
	struct stQuestGiver_Complete_Quest : PakHead
	{
		uint64 guid;
		uint32 quest_id;
		stQuestGiver_Complete_Quest(){ wProNO = QUESTGIVER_COMPLETE_QUEST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id; return cpu; }
	};	
	struct stQuestGiver_Choose_Reward : PakHead
	{
		uint64 guid;
		uint32 quest_id;
		uint32 reward_slot;
		stQuestGiver_Choose_Reward(){ wProNO = QUESTGIVER_CHOOSE_REWARD; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << quest_id << reward_slot; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> quest_id >> reward_slot; return cpu; }
	};	
	struct stQuest_PushTo_Party : PakHead
	{
		uint32 quest_id;
		stQuest_PushTo_Party(){ wProNO = QUEST_PUSHTO_PARTY; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << quest_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> quest_id; return cpu; }
	};	
	struct stQuest_Push_Result : PakHead
	{
		uint64 guid;
		uint8 msg;
		stQuest_Push_Result(){ wProNO = QUEST_PUSH_RESULT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << msg; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> msg; return cpu; }
	};


	struct stNPC_TabardVendor_Activate : PakHead
	{
		uint64 guid;
		stNPC_TabardVendor_Activate(){ wProNO = NPC_TABARDVENDOR_ACTIVATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Banker_Activate : PakHead
	{
		uint64 guid;
		stNPC_Banker_Activate(){ wProNO = NPC_BANKER_ACTIVATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Trainer_List : PakHead
	{
		uint64 guid;
		stNPC_Trainer_List(){ wProNO = NPC_TRAINER_LIST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Trainer_Buy_Spell : PakHead
	{
		uint64 guid;
		uint32 TeachingSpellID;
		stNPC_Trainer_Buy_Spell(){ wProNO = NPC_TRAINER_BUY_SPELL; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << TeachingSpellID; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> TeachingSpellID; return cpu; }
	};	
	struct stNPC_Pettion_ShowList : PakHead
	{
		uint64 guid;
		stNPC_Pettion_ShowList(){ wProNO = NPC_PETITION_SHOWLIST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Gossip_Hello : PakHead
	{
		uint64 guid;
		stNPC_Gossip_Hello(){ wProNO = NPC_GOSSIP_HELLO; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Gossip_Select_Option : PakHead
	{
		uint64 guid;
		uint32 option;
		string ExtraStr;
		stNPC_Gossip_Select_Option(){ wProNO = NPC_GOSSIP_SELECT_OPTION; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << option << ExtraStr; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> option >> ExtraStr; return cpu; }
	};	
	struct stNPC_Spirit_Healer_Activate : PakHead
	{
		uint64 guid;
		stNPC_Spirit_Healer_Activate(){ wProNO = NPC_SPIRIT_HEALER_ACTIVATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Text_Query : PakHead
	{
		uint32 textID;
		uint64 targetGuid;
		stNPC_Text_Query(){ wProNO = NPC_TEXT_QUERY; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << textID << targetGuid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> textID >> targetGuid; return cpu; }
	};	
	struct stNPC_Binder_Activate : PakHead
	{
		uint64 guid;
		stNPC_Binder_Activate(){ wProNO = NPC_BINDER_ACTIVATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stQuestGiver_Inrange_Status_Query : PakHead
	{
		stQuestGiver_Inrange_Status_Query(){ wProNO = QUESTGIVER_INRANGE_STATUS_QUERY; }
	};	

}

#pragma once

#include "S2C.h"

namespace MSG_S2C
{
	struct stQuestItem
	{
		ui32 item_entry;
		ui32 count;
		ui32 DisplayInfoID;
		CPacketSn& Sn(CPacketSn& cps) const {	cps << item_entry << count << DisplayInfoID; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> item_entry >> count >> DisplayInfoID; return cpu; }
	};
	struct stQuest 
	{
		ui32	quest_id;
		ui32	stat;
		string	title;
		CPacketSn& Sn(CPacketSn& cps) const {	cps << quest_id << stat << title; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> quest_id >> stat >> title; return cpu; }
	};

	struct stQuestGiver_Stats : public PakHead
	{
		stQuestGiver_Stats(){ wProNO = QUESTGIVER_STATUS; }
		uint64 guid;
		uint32 stats;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << stats; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> stats; return cpu; }
	};
	struct stQuestGiver_Quest_Details : public PakHead
	{
		stQuestGiver_Quest_Details(){ wProNO = QUESTGIVER_QUEST_DETAILS; }
		uint64 giver_guid;
		uint32 quest_id;
		string title,details,objectives;
		ui32 reward_money; 
		ui32 reward_spell;
		vector<stQuestItem> vChoice;
		vector<stQuestItem> vReward;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << giver_guid << quest_id << title << details << objectives << vChoice << vReward << reward_money << reward_spell; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> giver_guid >> quest_id >> title >> details >> objectives >> vChoice >> vReward >> reward_money >> reward_spell; return cpu; }
	};
	struct stQuest_Push_Result : PakHead
	{
		uint64 guid;
		uint8 share_result;
		stQuest_Push_Result(){ wProNO = QUEST_PUSH_RESULT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << share_result; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> share_result; return cpu; }
	};	
	struct stQuestGiver_Query_List : PakHead
	{
		uint64 giver_guid;
		string hello_message;
		ui32   EmoteDelay;
		ui32   Emote;	
		ui8	   bValid;

		ui8	   QuestCount;
		vector<stQuest> vQuests;
		stQuestGiver_Query_List(){ wProNO = QUESTGIVER_QUEST_LIST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << giver_guid << hello_message << EmoteDelay << Emote << bValid << QuestCount << vQuests; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> giver_guid >> hello_message >> EmoteDelay >> Emote >> bValid >> QuestCount >> vQuests; return cpu; }
	};	
	struct stQuest_Update_Add_Item : PakHead
	{
		ui32	item_entry;
		ui32	count,tcount;
		stQuest_Update_Add_Item(){ wProNO = QUESTUPDATE_ADD_ITEM; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << item_entry << count << tcount; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> item_entry >> count >> tcount; return cpu; }
	};	
	struct stQuest_Update_Add_Skill : PakHead
	{
		stQuest_Update_Add_Skill(){ wProNO = QUESTUPDATE_ADD_KILL; }
		uint32 questid, entry, count, tcount; uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid << entry << count << tcount << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid >> entry >> count >> tcount >> guid; return cpu; }
	};	
	struct stQuest_Update_Complete : PakHead
	{
		stQuest_Update_Complete(){ wProNO = QUESTUPDATE_COMPLETE; }
		uint32 questid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid; return cpu; }
	};
	struct stQuset_Confirm_Accpet : PakHead
	{
		stQuset_Confirm_Accpet(){ wProNO = QUEST_CONFIRM_ACCEPT; }
		uint32 questid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid; return cpu; }
	};
	struct stQuest_Log_Full : PakHead
	{
		stQuest_Log_Full(){ wProNO = QUESTLOG_FULL; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};	
	struct stQuest_Update_Failed : PakHead
	{
		stQuest_Update_Failed(){ wProNO = QUESTUPDATE_FAILED; }
		uint32 questid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid; return cpu; }
	};	
	struct stQuest_Update_FailedTimer : PakHead
	{
		stQuest_Update_FailedTimer(){ wProNO = QUESTUPDATE_FAILEDTIMER; }
		uint32 questid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid; return cpu; }
	};	
	struct stQuestGiver_Request_Items : PakHead
	{
		stQuestGiver_Request_Items(){ wProNO = QUESTGIVER_REQUEST_ITEMS; }
		ui64	giver_guid;
		uint32	questid;
		string	title,message;
		ui32	required_money;
		ui32	count_required_item;
		vector<stQuestItem> vItems;
		ui32	emote;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << giver_guid << questid << title << message << required_money << count_required_item << vItems << emote; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> giver_guid >> questid >> title >> message >> required_money >> count_required_item >> vItems >> emote; return cpu; }
	};	
	struct stQuestGiver_Offer_Reward : PakHead
	{
		stQuestGiver_Offer_Reward(){ wProNO = QUESTGIVER_OFFER_REWARD; }
		ui64	giver_guid;
		uint32	questid;
		string	title,message;
		ui8		hasNextQuest;
		ui32	required_money;
		ui32	reward_money;
		ui32	reward_spell;
		vector<stQuestItem> vChoice;
		vector<stQuestItem> vReward;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << giver_guid << questid << title << message << hasNextQuest << required_money << reward_money << reward_spell << vChoice << vReward; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> giver_guid >> questid >> title >> message >> hasNextQuest >> required_money >> reward_money >> reward_spell >> vChoice >> vReward; return cpu; }
	};
	struct stQuestGiver_Quest_Invalid : PakHead
	{
		stQuestGiver_Quest_Invalid(){ wProNO = QUESTGIVER_QUEST_INVALID; }
		uint32	questid;
		uint32 invalid_reason;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid << invalid_reason; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid >> invalid_reason; return cpu; }
	};	
	struct stQuestGiver_Quest_Complete : PakHead
	{
		stQuestGiver_Quest_Complete(){ wProNO = QUESTGIVER_QUEST_COMPLETE; }
		uint32	questid;
		ui32	xp;
		ui32	reward_money,count_reward_item,reward_honor;
		vector<stQuestItem> vItems;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid << vItems << xp << reward_money << count_reward_item << reward_honor; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid >> vItems >> xp >> reward_money >> count_reward_item >> reward_honor; return cpu; }
	};	
	struct stQuestGiver_Quest_Failed : PakHead
	{
		stQuestGiver_Quest_Failed(){ wProNO = QUESTGIVER_QUEST_FAILED; }
		uint32	questid;
		uint32  failed_reason;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << questid << failed_reason; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> questid >> failed_reason; return cpu; }
	};	

	struct stNPC_TabardVendor_Activate : PakHead
	{
		uint64 guid;
		stNPC_TabardVendor_Activate(){ wProNO = NPC_TABARDVENDOR_ACTIVATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Show_Bank : PakHead
	{
		uint64 guid;
		stNPC_Show_Bank(){ wProNO = NPC_SHOW_BANK; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Trainer_List : PakHead
	{
		struct stTrainerSpell
		{
			ui32	CastRealSpell_id;
			ui32	LearnSpell_id;
			uint8	Status;
			uint32	Cost;
			ui8		IsProfession;
			uint32	RequiredSpell;
			uint32	RequiredSkillLine;
			uint32	RequiredSkillLineValue;
			uint32	RequiredLevel;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << CastRealSpell_id << LearnSpell_id << Status << Cost << IsProfession << RequiredSpell << RequiredSkillLine << RequiredSkillLineValue << RequiredLevel; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> CastRealSpell_id >> LearnSpell_id >> Status >> Cost >> IsProfession >> RequiredSpell >> RequiredSkillLine >> RequiredSkillLineValue >> RequiredLevel; return cpu; }

		};
		uint64 guid;
		uint32 TrainerType;
		vector<stTrainerSpell> vSpells;
		string message;
		stNPC_Trainer_List(){ wProNO = NPC_TRAINER_LIST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << TrainerType << vSpells << message; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> TrainerType >> vSpells >> message; return cpu; }
	};	

	struct stNPC_Pettion_ShowList : PakHead
	{
		uint64 guid;
		stNPC_Pettion_ShowList(){ wProNO = NPC_PETITION_SHOWLIST; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};	
	struct stNPC_Gossip_Message : PakHead
	{
		uint32 count;
		uint64 CreatureGuid;
		uint32 TextId;

		struct stGossipMenuItem
		{
			ui32 Id;
			ui32 Icon;
			ui32 Extra;
			string Text;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << Id << Icon << Extra << Text; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> Id >> Icon >> Extra >> Text; return cpu; }
		};
		vector<stGossipMenuItem> vMenuItems;

		vector<stQuest> vQuests;
		stNPC_Gossip_Message(){ wProNO = NPC_GOSSIP_MESSAGE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << count << CreatureGuid << TextId << vMenuItems << vQuests; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> count >> CreatureGuid >> TextId >> vMenuItems >> vQuests;return cpu; }
	};	
	struct stNPC_Text_Update : PakHead
	{
		uint32 textID;
		uint64 guid;

		struct stGossipText
		{
			string text[2];
			ui32	emote[6];
			CPacketSn& Sn(CPacketSn& cps) const {	cps << text[0] << text[1] << emote[0] << emote[1] << emote[2] << emote[3] << emote[4] << emote[5]; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> text[0] >> text[1] >> emote[0] >> emote[1] >> emote[2] >> emote[3] >> emote[4] >> emote[5]; return cpu; }
		};
		vector<stGossipText> vGossipText;
		stNPC_Text_Update(){ wProNO = NPC_TEXT_UPDATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << textID << vGossipText; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> textID >> vGossipText; return cpu; }
	};	
	struct stNPC_Gossip_Complete : PakHead
	{
		stNPC_Gossip_Complete(){ wProNO = NPC_GOSSIP_COMPLETE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};	
	struct stNPC_Binder_Confirm : PakHead
	{
		uint64 CreatureGuid;
		ui32	ZoneID;
		stNPC_Binder_Confirm(){ wProNO = NPC_BINDER_CONFIRM; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << CreatureGuid << ZoneID;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> CreatureGuid >> ZoneID;return cpu; }
	};	
	struct stNPC_Binder_Update : PakHead
	{
		float x,y,z;
		ui32	mapID;
		ui32	ZoneID;
		stNPC_Binder_Update(){ wProNO = NPC_BINDPOINTUPDATE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps <<x<<y<<z << mapID << ZoneID;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >>x>>y>>z >> mapID >> ZoneID;return cpu; }
	};	
	struct stNPC_Bind_Player : PakHead
	{
		uint64 CreatureGuid;
		ui32	ZoneID;
		stNPC_Bind_Player(){ wProNO = NPC_PLAYERBOUND; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << CreatureGuid << ZoneID;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> CreatureGuid >> ZoneID;return cpu; }
	};	
	struct stNPC_Spirite_Healer_Confirm : PakHead
	{
		uint64 CreatureGuid;
		stNPC_Spirite_Healer_Confirm(){ wProNO = NPC_SPIRIT_HEALER_CONFIRM; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << CreatureGuid;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> CreatureGuid;return cpu; }
	};	
	struct stQuestGiver_Inrange_Status_Query_Response : PakHead
	{
		struct stQuestGiver
		{
			ui64	npc_guid;
			ui32	stat;
			CPacketSn& Sn(CPacketSn& cps) const {	cps << npc_guid << stat; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> npc_guid >> stat; return cpu; }
		};
		vector<stQuestGiver> vQuestGivers;
		stQuestGiver_Inrange_Status_Query_Response(){ wProNO = QUESTGIVER_INRANGE_STATUS_QUERY_RESPONSE; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vQuestGivers; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vQuestGivers; return cpu; }
	};	
	struct stNPC_Gossip_Poi : PakHead
	{
		stNPC_Gossip_Poi(){ wProNO = NPC_GOSSIP_POI; }
		float X;
		float Y;
		uint32 Icon;
		uint32 Flags;
		uint32 Data;
		string Name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << X<<Y<<Icon<<Flags<<Data<<Name;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> X>>Y>>Icon>>Flags>>Data>>Name;return cpu; }
	};	

}

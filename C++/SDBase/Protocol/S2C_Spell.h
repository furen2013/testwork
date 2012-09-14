#pragma once

#include "S2C.h"
#include "../Public/SpellDef.h"

namespace MSG_S2C
{
	struct stSummon_Request : public PakHead
	{
		stSummon_Request(){ wProNO = SMSG_SUMMON_REQUEST; }
		uint64 Requestor;
		uint32 ZoneID;
		ui32	t;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << Requestor << ZoneID << t; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> Requestor >> ZoneID >> t; return cpu; }
	};
	struct stTarget_Clear : public PakHead
	{
		stTarget_Clear(){ wProNO = TARGET_CLEAR; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stSpirit_Healer_Pos : public PakHead
	{
		stSpirit_Healer_Pos(){ wProNO = SMSG_SPIRIT_HEALER_POS; }
		ui32	mapid;
		float	x,y,z,o;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid << x << y << z << o; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid >> x >> y >> z >> o; return cpu; }
	};
	struct stAuraSetExtraInfo : public PakHead
	{
		stAuraSetExtraInfo(){ wProNO = AURA_SET_EXTRA_INFO; }
		ui64	target_guid;
		ui8		slot;
		ui32	spellid;
		ui32	Maxduration;
		ui32	Curduration;	
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << slot << spellid << Maxduration << Curduration; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> slot >> spellid >> Maxduration >> Curduration; return cpu; }
	};
	struct stAuraUpdateDuration : public PakHead
	{
		stAuraUpdateDuration(){ wProNO = AURA_UPDATE_DURATION; }
		ui8		slot;
		ui32	duration;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slot << duration; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slot >> duration; return cpu; }
	};
	struct stItemCoolDown : public PakHead
	{
		stItemCoolDown(){ wProNO = ITEM_COOLDOWN; }
		ui64	guid;
		ui32	spellid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << spellid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> spellid; return cpu; }
	};
	struct stResurrect_Failed : public PakHead
	{
		stResurrect_Failed(){ wProNO = SMSG_RESURRECT_FAILED; }
	};
	struct stSpell_Log_Miss : public PakHead
	{
		stSpell_Log_Miss(){ wProNO = SPELL_LOG_MISS; }
		ui32	spellid;
		ui64	caster_guid;
		ui64	target_guid;
		ui32	SpellLogType;// 定义在SpellDef.h SPELL_LOG枚举
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spellid << caster_guid << target_guid << SpellLogType; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spellid >> caster_guid >> target_guid >> SpellLogType; return cpu; }
	};
	struct stSpell_NoMelee_Damage_Log : public PakHead
	{
		stSpell_NoMelee_Damage_Log(){ wProNO = SPELL_NONMELEE_DAMAGE_LOG; damageSeq=0;}
		ui32	spellid;//技能id
		ui64	caster_guid;// 施法者
		ui64	target_guid;// 目标
		ui32	Damage;// 伤害值
		ui32	School;// 伤害类型 定义在SpellDef.h School枚举
		ui32	AbsorbedDamage;// 吸收的伤害
		ui32	ResistedDamage;// 抵抗的伤害
		ui32	PhysicalDamage;// 物理伤害
		ui32	BlockedDamage;// 格挡的伤害
		ui16    damageSeq;
		uint8	bCri;		//	是否暴击
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spellid << caster_guid << target_guid << Damage<<School<<AbsorbedDamage<<ResistedDamage<<PhysicalDamage<<BlockedDamage<<damageSeq<<bCri; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spellid >> caster_guid >> target_guid >> Damage>>School>>AbsorbedDamage>>ResistedDamage>>PhysicalDamage>>BlockedDamage>>damageSeq>>bCri; return cpu; }
	};
	struct stDamage_Environmental_Log : public PakHead
	{
		stDamage_Environmental_Log(){ wProNO = DAMAGE_ENVIRONMENTAL_LOG; }
		uint64 target_guid;// 目标
		uint8 type;// 伤害类型 定义在SpellDef.h EnviromentalDamage枚举
		ui32	damage;//伤害值
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << type << damage; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> type >> damage; return cpu; }
	};	

	struct stAura_Periodic_Log : public PakHead
	{
		stAura_Periodic_Log(){ wProNO = AURA_PERIODIC_LOG; }
		uint64 target_guid;
		uint64 caster_guid;
		ui32 spell_entry;		// 技能id
		ui32 flag;				// 定义在SpellDef.h AuraTickFlags枚举
		ui32 amount;			// 伤害值
		ui32 school;			// 伤害类型 定义在SpellDef.h School枚举
		ui32 abs_dmg;			// 吸收的伤害
		ui32 resisted_damage;	// 抵抗的伤害
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << caster_guid << spell_entry << flag << amount << school << abs_dmg << resisted_damage; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> caster_guid >> spell_entry >> flag >> amount >> school >> abs_dmg >> resisted_damage; return cpu; }
	};
	struct stSpell_CD_Event : public PakHead
	{
		stSpell_CD_Event(){ wProNO = SPELL_COOLDOWN_EVENT; }
		uint64 guid;ui32 spellid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << spellid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> spellid; return cpu; }
	};	
	struct stAura_Set_Duration : public PakHead
	{
		stAura_Set_Duration(){ wProNO = AURA_SET_DURATION; }
		ui8 slot;
		ui32 duration;
		uint8 count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << slot << duration << count ; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> slot >> duration >> count ; return cpu; }
	};	
	struct stAura_Set_Single : public PakHead
	{
		stAura_Set_Single(){ wProNO = AURA_SET_SINGLE; }
		ui64 target_guid;
		ui32 spellid;
		ui8 slot;
		ui32 duration1;
		ui32 duration2;
		ui8 count;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << spellid << slot << duration1 << duration2 <<count ; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> spellid >> slot >> duration1 >> duration2 >> count ; return cpu; }
	};	
	struct stSpell_Play_Visual : public PakHead
	{
		stSpell_Play_Visual(){ wProNO = SPELL_PLAY_VISUAL; }
		uint64 target_guid;
		uint32 visualid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << visualid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> visualid; return cpu; }
	};	

	struct stSpell_Heal_On_Player : public PakHead
	{
		stSpell_Heal_On_Player(){ wProNO = SPELL_HEAL_ON_PLAYER; damageseq=0;}
		uint64 caster_guid;
		uint64 target_guid;
		uint32 spell_id;
		ui32 dmg;
		ui8	critical;
		uint16 damageseq;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << target_guid << spell_id << dmg << critical << damageseq; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> target_guid >> spell_id >> dmg >> critical >> damageseq; return cpu; }
	};	
	struct stSpell_HealMana_On_Player : public PakHead
	{
		stSpell_HealMana_On_Player(){ wProNO = SPELL_HEALMANAON_PLAYER; damageseq=0;}
		uint64 caster_guid;
		uint64 target_guid;
		uint32 spell_id;
		ui32 power_type;
		ui32 dmg;
		uint16 damageseq;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << target_guid << spell_id << power_type << dmg << damageseq; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> target_guid >> spell_id >> power_type >> dmg >> damageseq; return cpu; }
	};	
	struct stSpellCoolDown : public PakHead
	{
		stSpellCoolDown(){ wProNO = SPELL_COOLDOWN; }
		ui64	caster_guid;
		ui32	spell_id;
		ui32	recover_time;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << spell_id << recover_time; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> spell_id >> recover_time; return cpu; }
	};
	struct stSpell_Delayed : public PakHead
	{
		stSpell_Delayed(){ wProNO = SPELL_DELAYED; }
		ui64	caster_guid;
		ui32	delay;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << delay; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> delay; return cpu; }
	};
	struct stSpell_Log_Excute : public PakHead
	{
		stSpell_Log_Excute(){ wProNO = SPELL_LOG_EXECUTE; }
		ui64	caster_guid;
		ui64	target_guid;
		ui32	spell_id;
		ui32	damage;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << target_guid << spell_id << damage; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> target_guid >> spell_id >> damage; return cpu; }
	};
	struct stSpell_Failure : public PakHead
	{
		stSpell_Failure(){ wProNO = 	SPELL_FAILURE; }
		ui64	caster_guid;
		ui32	spell_id;
		ui8	error;			//	定义在SpellDef.h SpellCastError枚举中 例如:SPELL_FAILED_NO_POWER
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << spell_id << error; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> spell_id >> error; return cpu; }
	};
	struct stSpell_Target_Cast_Result : public PakHead
	{
		stSpell_Target_Cast_Result(){ wProNO = 	SPELL_TARGET_CAST_RESULT; }
		ui64	target_guid;
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> spell_id; return cpu; }
	};
	struct stSet_Combo_Points : public PakHead
	{
		stSet_Combo_Points(){ wProNO = 	SET_COMBO_POINTS; }
		ui64	target_guid;
		ui32	combo_points;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << combo_points; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> combo_points; return cpu; }
	};
	struct stSpell_Damage_Shield : public PakHead
	{
		stSpell_Damage_Shield(){ wProNO = 	SPELL_DAMAGE_SHIELD; }
		ui64	target_guid;
		ui64	attacker_guid;
		ui32	damage;
		ui32	school;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << target_guid << attacker_guid << damage << school; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> target_guid >> attacker_guid >> damage >> school; return cpu; }
	};
	struct stSpell_Cast_Result : public PakHead
	{
		stSpell_Cast_Result(){ wProNO = SPELL_CAST_RESULT; }
		uint32	SpellId;
		uint8	ErrorMessage;			//	定义在SpellDef.h SpellCastError枚举中
		uint8   MultiCast;				//	是由客户端释放技能填充的参数,暂时未知不用
		uint32	Extra;					//	对应错误的原因,例如ERROR=SPELL_FAILED_REQUIRES_AREA,Extra就=m_spellInfo->RequiresAreaId
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << SpellId << ErrorMessage << MultiCast << Extra; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> SpellId >> ErrorMessage >> MultiCast >> Extra; return cpu; }
	};
	struct stSpell_Channel_Start : public PakHead
	{
		stSpell_Channel_Start(){ wProNO = SPELL_CHANNEL_START; }
		uint64	caster_guid;
		uint32	SpellId;
		uint32	duration;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << SpellId << caster_guid << duration; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> SpellId >> caster_guid >> duration; return cpu; }
	};
	struct stSpell_Channel_Update : public PakHead
	{
		stSpell_Channel_Update(){ wProNO = SPELL_CHANNEL_UPDATE; }
		uint64	caster_guid;
		uint32	time;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << time << caster_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> time >> caster_guid; return cpu; }
	};
	struct stSpell_Resurrect_Request : public PakHead
	{
		stSpell_Resurrect_Request(){ wProNO = SPELL_RESURRECT_REQUEST; }
		uint64	caster_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid; return cpu; }
	};
	struct stSpell_Start : public PakHead
	{
		stSpell_Start(){ wProNO = SPELL_START; }
		ui64	caster_item_guid;	// 施法的道具id
		ui64	caster_unit_guid;	// 施法的生物id
		ui32	spell_id;// 技能id
		ui8		extra_cast_number;
		ui16	cast_flags;
		ui32	casttime;// 施法时间
		SpellCastTargets targets;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_item_guid << caster_unit_guid << spell_id << extra_cast_number << cast_flags << casttime
			<< targets; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_item_guid >> caster_unit_guid >> spell_id >> extra_cast_number >> cast_flags >> casttime
			>> targets; return cpu; }
	};
	struct stSpell_Go : public PakHead
	{
		struct stTargetMiss
		{
			stTargetMiss(){}
			stTargetMiss(ui64 guid, ui8 condition):target_guid(guid), miss_condition(condition){}
			ui64	target_guid;
			ui8		miss_condition;/** The flags at the end known to us so far are.
								   * 1 = Miss
								   * 2 = Resist
								   * 3 = Dodge // mellee only
								   * 4 = Deflect
								   * 5 = Block // mellee only
								   * 6 = Evade
								   * 7 = Immune
								   */
		};
		stSpell_Go(){ wProNO = SPELL_GO; }
		ui64	caster_item_guid;
		ui64	caster_unit_guid;
		ui32	spell_id;// 技能id
		ui16	castFlags;//SpellGoFlags 定义在SpellGoFlags
		ui32	casttime;// 施法时间
		ui16    damageSeq;

		vector<ui64>	vTargetHit;//命中目标
		vector<stTargetMiss> vTargetMiss;//miss的目标

		SpellCastTargets targets;//目标

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_item_guid << caster_unit_guid << spell_id << castFlags << casttime
			<< vTargetHit << targets << damageSeq; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_item_guid >> caster_unit_guid >> spell_id >> castFlags >> casttime
			>> vTargetHit >> targets >> damageSeq; return cpu; }
	};
	struct stAttacker_State_Update : public PakHead
	{
		stAttacker_State_Update(){ wProNO = ATTACKER_STATE_UPDATE; }
		ui32	hitStats;				//	攻击类型 定义在SpellDef.h HitStatus枚举
		ui64	attacker_guid;			//	攻击者
		ui64	victim_guid;			//	受害者
		ui32	realdamage;				//	伤害值
		ui32	damageschool;			//	伤害类型 定义在SpellDef.h School枚举
		float	fdamage_full;			//	伤害的浮点型
		ui32	ndamage_full;			//	伤害的整型
		ui32	damage_abs;				//	吸收的伤害值
		ui32	resisted_damage;		//	抵抗的伤害值
		ui32	blocked_damage;			//	格挡的伤害值
		ui32	extra_damage;
		ui16    damageSeq;

		ui32	victim_stat;			//	vstate=1-wound,2-dodge,3-parry,4-interrupt,5-block,6-evade,7-immune,8-deflect
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << hitStats << attacker_guid << victim_guid << realdamage << damageschool << fdamage_full << ndamage_full
			<< damage_abs << resisted_damage << blocked_damage << victim_stat << extra_damage << damageSeq; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> hitStats >> attacker_guid >> victim_guid >> realdamage >> damageschool >> fdamage_full >> ndamage_full
			>> damage_abs >> resisted_damage >> blocked_damage >> victim_stat >> extra_damage >> damageSeq; return cpu; }
	};
	struct stAttack_Stop : public PakHead
	{
		stAttack_Stop(){ wProNO = ATTACK_STOP; }
		ui64	attacker_guid;
		ui64	victim_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << attacker_guid << victim_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> attacker_guid >> victim_guid; return cpu; }
	};
	struct stAttack_Start : public PakHead
	{
		stAttack_Start(){ wProNO = ATTACK_START; }
		ui64	attacker_guid;
		ui64	victim_guid;
		float x,y,z;				// Point attack location
		float orientation;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << attacker_guid << victim_guid << x << y << z << orientation; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> attacker_guid >> victim_guid >> x >> y >> z >> orientation; return cpu; }
	};
	struct stAttack_Zone_Under_Attack : public PakHead
	{
		stAttack_Zone_Under_Attack(){ wProNO = ZONE_UNDER_ATTACK; }
		ui32	AreaID;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << AreaID; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> AreaID; return cpu; }
	};
	struct stSpell_Clear_CD : public PakHead
	{
		stSpell_Clear_CD(){ wProNO = SPELL_CLEAR_COOLDOWN; }
		ui64	guid;
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> spell_id; return cpu; }
	};
	struct stSpell_Set_Flat_Modifier : public PakHead
	{
		stSpell_Set_Flat_Modifier(){ wProNO = SPELL_SET_FLAT_MODIFIER; }
		uint8 group;
		uint8 type;
		int32 v;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << group << type << v; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> group >> type >> v; return cpu; }
	};
	struct stSpell_Dispel_Log: public PakHead
	{
		stSpell_Dispel_Log(){ wProNO = SPELL_DISPEL_LOG; }
		ui64	caster_guid;
		ui64	unit_guid;
		ui32	dispel_type;
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << caster_guid << unit_guid << dispel_type << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> caster_guid >> unit_guid >> dispel_type >> spell_id; return cpu; }
	};
	struct stSpell_Cancel_Auto_Repeat : public PakHead
	{
		stSpell_Cancel_Auto_Repeat(){ wProNO = CANCEL_AUTO_REPEAT; }
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spell_id; return cpu; }
	};
	struct stCombat_Cancel : public PakHead
	{
		stCombat_Cancel(){ wProNO = COMBAT_CANCEL; }
	};
	struct stAttack_Swing_Not_In_Range : public PakHead
	{
		stAttack_Swing_Not_In_Range(){ wProNO = ATTACKSWING_NOTINRANGE; }
	};
	struct stAttack_Swing_Bad_Facing : public PakHead
	{
		stAttack_Swing_Bad_Facing(){ wProNO = ATTACKSWING_BADFACING; }
	};
	struct stSpell_Removed : public PakHead
	{
		stSpell_Removed(){ wProNO = SPELL_REMOVED; }
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spell_id; return cpu; }
	};
	struct stAction_Buttons : public PakHead
	{
		stAction_Buttons(){ wProNO = ACTION_BUTTONS; }
		struct stActionButton
		{
			uint32  Action;		//	技能id或物品id
			uint8   Type;		//	定义在C2S.h中 例如ActionButton_Type_Spell
			uint8   Misc;		//	
			CPacketSn& Sn(CPacketSn& cps) const {	cps << Action << Type << Misc; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{	cpu >> Action >> Type >> Misc; return cpu; }
		};
		vector<stActionButton> vActionButtons;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vActionButtons; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vActionButtons; return cpu; }
	};
	struct stSpell_Learned : public PakHead
	{
		stSpell_Learned(){ wProNO = SPELL_LEARNED; }
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spell_id; return cpu; }
	};
	struct stSpell_Superceded : public PakHead
	{
		stSpell_Superceded(){ wProNO = SPELL_SUPERCEDED; }
		ui32	spell_id;
		ui32	superceded_spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << spell_id << superceded_spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> spell_id >> superceded_spell_id; return cpu; }
	};
	struct stSpell_Set_Forced_Reactions : public PakHead
	{
		stSpell_Set_Forced_Reactions(){ wProNO = SMSG_SET_FORCED_REACTIONS; }
		struct stModifier
		{
			ui32	miscValue;
			ui32	amount;
			CPacketSn& Sn(CPacketSn& cps) const { cps << miscValue << amount; return cps; }
			CPacketUsn& Usn(CPacketUsn& cpu)	{ cpu >> miscValue >> amount; return cpu; }
		};
		vector<stModifier> vModifier;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << vModifier; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> vModifier; return cpu; }
	};
}



/************************************************************************/
/* General Spell Go Flags, for documentation reasons                    */
/************************************************************************/
enum SpellGoFlags
{
	//0x01
	//0x02
	//0x04
	//0x08
	//0x10
	SPELL_GO_FLAGS_RANGED           = 0x20,
	//0x40
	//0x80
	SPELL_GO_FLAGS_ITEM_CASTER      = 0x100,
	//0x200
	SPELL_GO_FLAGS_EXTRA_MESSAGE    = 0x400, //TARGET MISSES AND OTHER MESSAGES LIKE "Resist"
	//0x800
	//0x1000
	//0x2000
	//0x4000
	//0x8000
};

enum AuraTickFlags
{
	FLAG_PERIODIC_DAMAGE            = 2,
	FLAG_PERIODIC_TRIGGER_SPELL     = 4,
	FLAG_PERIODIC_HEAL              = 8,
	FLAG_PERIODIC_LEECH             = 16,
	FLAG_PERIODIC_ENERGIZE          = 32,
};

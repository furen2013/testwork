#pragma once

#include "C2S.h"
namespace MSG_C2S
{	
	struct stMove_OP : public PakHead
	{
		stMove_OP(){ wProNO = MOVE_OP; }
		uint64	guid;
		ui8	moveOP;			//	Define in UnitDef.h
		MovementInfo move;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << moveOP << move; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> moveOP >> move; return cpu; }
	};

	struct stMove_Ack : public PakHead
	{
		stMove_Ack(){ wProNO = MOVE_ACK; }
		ui8 moveAck;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << moveAck; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> moveAck; return cpu; }
	};

	struct stMove_Time_Skipped : public PakHead
	{
		stMove_Time_Skipped(){ wProNO = MOVE_TIME_SKIPPED; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};
	struct stMove_Not_Active_Mover : public PakHead
	{
		stMove_Not_Active_Mover(){ wProNO = MOVE_NOT_ACTIVE_MOVER; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); return cpu; }
	};
	struct stMove_Set_Acive_Mover : public PakHead
	{
		stMove_Set_Acive_Mover(){ wProNO = MOVE_SET_ACTIVE_MOVER; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << guid;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> guid;return cpu; }
	};
	struct stMove_Teleport_Ack : public PakHead
	{ 
		stMove_Teleport_Ack(){ wProNO = MOVE_TELEPORT_ACK; }
		ui64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << guid;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> guid;return cpu; }
	};
	struct stMove_WorldPort_Ack : public PakHead
	{
		stMove_WorldPort_Ack(){ wProNO = MOVE_WORLDPORT_ACK; }
		uint32 mapid;
		float x,y,z,o;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid << x << y << z << o; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid >> x >> y >> z >> o; return cpu; }
	};
	struct stMove_World_TelePort : public PakHead
	{
		stMove_World_TelePort(){ wProNO = 	MOVE_WORLD_TELEPORT; }
		uint32 mapid;
		float x,y,z,o;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << mapid << x << y << z << o; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> mapid >> x >> y >> z >> o; return cpu; }
	};
	struct stMove_TelePort_To_Unit : public PakHead
	{
		stMove_TelePort_To_Unit(){ wProNO = 	MOVE_TELEPORT_TO_UNIT; }
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);return cpu; }
	};
	struct stMove_TelePort_Cheat : public PakHead
	{
		stMove_TelePort_Cheat(){ wProNO = 	MOVE_TELEPORT_CHEAT; }
		float x,y,z,o;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << x << y << z << o; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> x >> y >> z >> o; return cpu; }
	};
	struct stMove_Mount_Special_Anim : public PakHead
	{
		stMove_Mount_Special_Anim(){ wProNO = MOVE_MOUNTSPECIAL_ANIM; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stMove_Spline_Done : public PakHead
	{
		stMove_Spline_Done(){ wProNO = MOVE_SPLINE_DONE; }
	};

	//被骑的人邀请骑乘的人
	struct stMount_Invite : public PakHead
	{
		stMount_Invite(){ wProNO = MOUNT_INVITE; }
		uint64 player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_guid; return cpu; }
	};

	//解散队伍
	struct stMount_Disband : public PakHead
	{
		stMount_Disband(){ wProNO = MOUNT_DISBAND; }
	};

	//同意邀请
	struct stMount_Accept : public PakHead
	{
		stMount_Accept(){ wProNO = MOUNT_ACCEPT; }
	};

	//拒绝邀请 
	struct stMount_Decline : public PakHead
	{
		stMount_Decline(){ wProNO = MOUNT_DECLINE; }
	};
}

//
//
//struct stMove_HeartBeat : public stMove_OP
//{
//	stMove_HeartBeat(){ wProNO = MOVE_HEARTBEAT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps); return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu);return cpu; }
//};
//struct stMove_Jump : public stMove_OP
//{
//	stMove_Jump(){ wProNO = MOVE_JUMP; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps); return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu);return cpu; }
//};
//struct stMove_Fly_Pitch_Up_Z : public stMove_OP
//{
//	stMove_Fly_Pitch_Up_Z(){ wProNO = MOVE_FLY_PITCH_UP_Z; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Forward : public stMove_OP
//{
//	stMove_Start_Forward(){ wProNO = MOVE_START_FORWARD; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_BackWard : public stMove_OP
//{
//	stMove_Start_BackWard(){ wProNO = MOVE_START_BACKWARD; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Set_Facing : public stMove_OP
//{
//	stMove_Set_Facing(){ wProNO = MOVE_SET_FACING; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Strafe_Left : public stMove_OP
//{
//	stMove_Start_Strafe_Left(){ wProNO = MOVE_START_STRAFE_LEFT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Strafe_Right : public stMove_OP
//{
//	stMove_Start_Strafe_Right(){ wProNO = MOVE_START_STRAFE_RIGHT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Stop_Strafe : public stMove_OP
//{
//	stMove_Start_Stop_Strafe(){ wProNO = MOVE_STOP_STRAFE; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Turn_Left : public stMove_OP
//{
//	stMove_Start_Turn_Left(){ wProNO = MOVE_START_TURN_LEFT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Turn_Right : public stMove_OP
//{
//	stMove_Start_Turn_Right(){ wProNO = MOVE_START_TURN_RIGHT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Stop_Turn : public stMove_OP
//{
//	stMove_Stop_Turn(){ wProNO = MOVE_STOP_TURN; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Pitch_Up : public stMove_OP
//{
//	stMove_Start_Pitch_Up(){ wProNO = MOVE_START_PITCH_UP; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Pitch_Down : public stMove_OP
//{
//	stMove_Start_Pitch_Down(){ wProNO = MOVE_START_PITCH_DOWN; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Stop_Pitch : public stMove_OP
//{
//	stMove_Stop_Pitch(){ wProNO = MOVE_STOP_PITCH; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Set_Run_Move : public stMove_OP
//{
//	stMove_Set_Run_Move(){ wProNO = MOVE_SET_RUN_MODE; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Set_Walk_Move : public stMove_OP
//{
//	stMove_Set_Walk_Move(){ wProNO = MOVE_SET_WALK_MODE; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Set_Pitch : public stMove_OP
//{
//	stMove_Set_Pitch(){ wProNO = MOVE_SET_PITCH; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Start_Swim : public stMove_OP
//{
//	stMove_Start_Swim(){ wProNO = MOVE_START_SWIM; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Stop_Swim : public stMove_OP
//{
//	stMove_Stop_Swim(){ wProNO = MOVE_STOP_SWIM; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Fall_Land : public stMove_OP
//{
//	stMove_Fall_Land(){ wProNO = MOVE_FALL_LAND; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Stop : public stMove_OP
//{
//	stMove_Stop(){ wProNO = MOVE_STOP; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Fly_Start_And_End : public stMove_OP
//{
//	stMove_Fly_Start_And_End(){ wProNO = MOVE_FLY_START_AND_END; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Fly_Pitch_Down_After_Up : public stMove_OP
//{
//	stMove_Fly_Pitch_Down_After_Up(){ wProNO = MOVE_FLY_PITCH_DOWN_AFTER_UP; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};
//struct stMove_Transport_Step_In_Out : public stMove_OP
//{
//	stMove_Transport_Step_In_Out(){ wProNO = MOVE_TRANSPORT_STEP_IN_OUT; }
//	CPacketSn& Sn(CPacketSn& cps) const {	stMove_OP::Sn(cps);  return cps; }
//	CPacketUsn& Usn(CPacketUsn& cpu)	{	stMove_OP::Usn(cpu); return cpu; }
//};

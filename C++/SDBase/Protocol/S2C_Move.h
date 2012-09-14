#pragma once

#include "S2C.h"

enum PlayerSpeedType
{
	RUN	            = 1,
	RUNBACK         = 2,
	SWIM	        = 3,
	SWIMBACK        = 4,
	WALK	        = 5,
	FLY	            = 6,
	FLY_BACK		= 7,
	TRUN_RATE,
};

enum MoveType
{
	MOVE_TYPE_NORMAL = 0,
	MOVE_TYPE_STOP = 1,
	MOVE_TYPE_UNUSED = 3,
	MOVE_TYPE_POLL = 4,
};

namespace MSG_S2C
{

	enum MirrorTimerType
	{
		FATIGUE_TIMER      = 0,
		BREATH_TIMER       = 1,
		FIRE_TIMER         = 2
	};
	struct stPauseMirrorTimer : public PakHead
	{
		stPauseMirrorTimer(){ wProNO = PAUSE_MIRROR_TIMER; }
		ui32	type;
		ui32	MaxValue;
		ui32	CurValue;
		ui32	BreathRegen;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type << MaxValue << CurValue << BreathRegen; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type >> MaxValue >> CurValue >> BreathRegen; return cpu; }
	};
	struct stStartMirrorTimer : public PakHead
	{
		stStartMirrorTimer(){ wProNO = START_MIRROR_TIMER; }
		ui32	type;
		ui32	MaxValue;
		ui32	CurValue;
		ui32	BreathRegen;
		ui32	spell_id;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type << MaxValue << CurValue << BreathRegen << spell_id; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type >> MaxValue >> CurValue >> BreathRegen >> spell_id; return cpu; }
	};
	struct stStopMirrorTimer : public PakHead
	{
		stStopMirrorTimer(){ wProNO = STOP_MIRROR_TIMER; }
		ui32	type;

		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << type; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> type; return cpu; }
	};


	struct stMove_Monster : public PakHead
	{
		struct stWaypoint
		{
			stWaypoint(){}
			stWaypoint(float x,float y,float z):_x(x),_y(y),_z(z){}
			float _x,_y,_z;
			CPacketSn&  Sn(CPacketSn& cps) const{ cps << _x << _y << _z; return cps;}
			CPacketUsn& Usn(CPacketUsn& cpu){ cpu >> _x >> _y >> _z; return cpu;}
		};
		stMove_Monster()
		{
			wProNO = MONSTER_MOVE;
			borientation = false;
		}
		uint64 guid;
		float x,y,z;				// Point A, starting location
		bool borientation;
		float orientation;
		ui32 timestamp;
		ui8	move_type;//
		ui32 move_flag;// "DontMove = 1"
		ui32 time_between;// Time in between points
		vector<stWaypoint> vWayPoints;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << x << y << z << borientation << orientation << timestamp << move_type << move_flag << time_between << vWayPoints; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> x >> y >> z >> borientation >> orientation >> timestamp >> move_type >> move_flag >> time_between >> vWayPoints; return cpu; }
	};	
	
	struct stMove_Force_Root : public PakHead
	{
		stMove_Force_Root(){ wProNO = MOVE_FORCE_ROOT; }
		uint64 guid;
		uint32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag; return cpu; }
	};
	struct stMove_Force_UnRoot : public PakHead
	{
		stMove_Force_UnRoot(){ wProNO = MOVE_FORCE_UNROOT; }
		uint64 guid;
		uint32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag; return cpu; }
	};
	struct stMove_Water_Walk : public PakHead
	{
		stMove_Water_Walk(){ wProNO = MOVE_WATER_WALK; }
		uint64 guid;
		uint32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag; return cpu; }
	};
	struct stMove_Land_Walk : public PakHead
	{
		stMove_Land_Walk(){ wProNO = MOVE_LAND_WALK; }
		uint64 guid;
		uint32 flag;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << flag; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> flag; return cpu; }
	};
	struct stMove_Set_Fly : public PakHead
	{
		stMove_Set_Fly(){ wProNO = MOVE_SET_FLY; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stMove_Set_UnFly : public PakHead
	{
		stMove_Set_UnFly(){ wProNO = MOVE_SET_UNFLY; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid; return cpu; }
	};
	struct stMove_New_World : public PakHead
	{
		stMove_New_World(){ wProNO = MOVE_NEW_WORLD; }
		ui32	map_id;
		float	pos_x;
		float	pos_y;
		float	pos_z;
		float	orientation;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps);  cps << map_id << pos_x << pos_y << pos_z << orientation;return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu); cpu >> map_id >> pos_x >> pos_y >> pos_z >> orientation;return cpu; }
	};
	struct stMove_Mount_Special_Anim : public PakHead
	{
		stMove_Mount_Special_Anim(){ wProNO = MOVE_MOUNTSPECIAL_ANIM; }
		uint64	guid;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps);	cps << guid; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);	cpu >> guid;return cpu;}
	};

	struct stMove_Teleport_Ack : public PakHead
	{
		stMove_Teleport_Ack(){ wProNO = MOVE_TELEPORT_ACK; }
		uint64	guid;
		float	x,y,z,orientation;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps << guid << x << y << z << orientation; return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu)	{PakHead::Usn(cpu);cpu >> guid >> x >> y >> z >> orientation; return cpu;}
	};
	struct stMove_OP : public PakHead
	{
		uint64	guid;
		ui8	moveOP;			//	Define in UnitDef.h
		MovementInfo move;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << guid << moveOP << move; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> guid >> moveOP >> move; return cpu; }
	};
	struct stMove_Set_Speed : public PakHead
	{
		stMove_Set_Speed(){ wProNO = MOVE_SET_SPEED; }
		uint64 guid;
		ui8	SpeedType;
		uint32 speedChangeCounter;
		ui32	timeNow;
		float	x,y,z,orientation;
		float speed;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid<<SpeedType<<speedChangeCounter<<timeNow<<x<<y<<z<<orientation<<speed;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid>>SpeedType>>speedChangeCounter>>timeNow>>x>>y>>z>>orientation>>speed;return cpu;}
	};
	struct stMove_Knock_Back : public PakHead
	{
		stMove_Knock_Back(){ wProNO = MOVE_KNOCK_BACK; }
		uint64 guid;
		ui32	timeNow;
		float	x,y,z,orientation;
		float affect1,affect2;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid<<timeNow<<x<<y<<z<<orientation<<affect1<<affect2;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid>>timeNow>>x>>y>>z>>orientation>>affect1>>affect2;return cpu;}
	};
	struct stMove_Feather_Fail : public PakHead
	{
		stMove_Feather_Fail(){ wProNO = MOVE_FEATHER_FALL; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid;return cpu;}
	};
	struct stMove_Normal_Fail : public PakHead
	{
		stMove_Normal_Fail(){ wProNO = MOVE_NORMAL_FALL; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid;return cpu;}
	};
	struct stMove_Set_Hover : public PakHead
	{
		stMove_Set_Hover(){ wProNO = MOVE_SET_HOVER; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid;return cpu;}
	};
	struct stMove_UnSet_Hover : public PakHead
	{
		stMove_UnSet_Hover(){ wProNO = MOVE_UNSET_HOVER; }
		uint64 guid;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<guid;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>guid;return cpu;}
	};
	struct stTransfer_Pending : public PakHead
	{
		stTransfer_Pending(){ wProNO = TRANSFER_PENDING; oldmap = 0;transport_entry = 0;}
		ui32	mapid,oldmap,transport_entry;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<mapid<<oldmap<<transport_entry;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>mapid>>oldmap>>transport_entry;return cpu;}
	};
	struct stTransfer_Abouted : public PakHead
	{
		stTransfer_Abouted(){ wProNO = TRANSFER_ABORTED; }
		ui32	mapid,stat;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<mapid<<stat;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>mapid>>stat;return cpu;}
	};
	struct stMove_UnLock_Movement : public PakHead
	{
		stMove_UnLock_Movement(){ wProNO = MOVE_UNLOCK_MOVEMENT; }
		ui32	unk;
		CPacketSn& Sn(CPacketSn& cps) const {PakHead::Sn(cps); cps<<unk;return cps;}
		CPacketUsn& Usn(CPacketUsn& cpu) {PakHead::Usn(cpu);   cpu>>unk;return cpu;}
	};
	

	//被骑的人邀请骑乘的人
	struct stMount_Invite : public PakHead
	{
		stMount_Invite(){ wProNO = MOUNT_INVITE; }
		string player_name;
		uint64	player_guid;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name << player_guid; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name >> player_guid; return cpu; }
	};

	//解散队伍
	struct stMount_Disband : public PakHead
	{
		stMount_Disband(){ wProNO = MOUNT_DISBAND; }
		string player_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name; return cpu; }
	};

	//同意邀请
	struct stMount_Accept : public PakHead
	{
		stMount_Accept(){ wProNO = MOUNT_ACCEPT; }
		string player_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name; return cpu; }
	};

	//拒绝邀请 
	struct stMount_Decline : public PakHead
	{
		stMount_Decline(){ wProNO = MOUNT_DECLINE; }
		string player_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> player_name; return cpu; }
	};

	struct stMount_Result : public PakHead
	{
		stMount_Result(){ wProNO = MOUNT_RESULT; }
		uint32 result;
		string player_name;
		CPacketSn& Sn(CPacketSn& cps) const {	PakHead::Sn(cps); cps << result << player_name; return cps; }
		CPacketUsn& Usn(CPacketUsn& cpu)	{	PakHead::Usn(cpu);cpu >> result >> player_name; return cpu; }
	};

	enum{
		MOUNT_RESULT_BUSY,
		MOUNT_RESULT_ALREADY_RIDE,
		MOUNT_RESULT_NOT_FOUND,
		MOUNT_RESULT_TARGET_SHAPESHIFT,
		MOUNT_RESULT_ALREADY_IN_RIDE,

		MOUNT_RESULT_NOT_RIDE,
		MOUNT_RESULT_NOT_IN_RIDE,
		MOUNT_RESULT_DISBAND,
		MOUNT_RESULT_CANNOTRIDE,
		MOUNT_RESULT_TOO_FAR,
	};
}

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
//

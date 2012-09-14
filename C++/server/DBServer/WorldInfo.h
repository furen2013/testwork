#pragma once

struct CreateInfo_ItemStruct
{
	uint32  protoid;
	uint8   slot;
	uint32  amount;
};

struct CreateInfo_SkillStruct
{
	uint32  skillid;
	uint32  currentval;
	uint32  maxval;
};

struct CreateInfo_ActionBarStruct
{
	uint32  button;
	uint32  action;
	uint32  type;
	uint32  misc;
};
struct PlayerCreateInfo{
	uint8   index;
	uint8   race;
	uint32  factiontemplate;
	uint8   class_;
	uint32  mapId;
	uint32  zoneId;
	float   positionX;
	float   positionY;
	float   positionZ;
	uint32  displayId;
	uint8   strength;
	uint8   ability;
	uint8   stamina;
	uint8   intellect;
	uint8   spirit;
	uint8	vitality;
	uint32  health;
	uint32  mana;
	uint32  rage;
	uint32  focus;
	uint32  energy;
	uint32  attackpower;
	float   mindmg;
	float   maxdmg;
	std::list<CreateInfo_ItemStruct> items;
	std::list<CreateInfo_SkillStruct> skills;
	std::list<CreateInfo_ActionBarStruct> actionbars;
	std::set<uint32> spell_list;
	//uint32 item[10];
	//uint8 item_slot[10];
	//uint16 spell[10];
};

typedef HM_NAMESPACE::hash_map<uint32, PlayerCreateInfo*>           PlayerCreateInfoMap;
class WorldInfo : public Singleton<WorldInfo>
{
public:
	PlayerCreateInfo* GetPlayerCreateInfo(uint8 race, uint8 class_) const;
	void LoadPlayerCreateInfo();
	// Map of all starting infos needed for player creation
	PlayerCreateInfoMap mPlayerCreateInfo;

};
#define sWorldInfo WorldInfo::getSingleton()
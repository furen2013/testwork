#include "StdAfx.h"
#include "CreatureStorage.h"
#include "baseCreature.h"
#include "boost/lexical_cast.hpp"
std::string _defaultStateImageKey[CreatureState_Max];
std::string _defaultDirImageKey[CreatureDir_Max];
initialiseSingleton(CreatureStorage);

CreatureStorage::CreatureStorage(void)
{
	_defaultDirImageKey[CreatureDir_Up] = "up";
	_defaultDirImageKey[CreatureDir_Down] = "down";
	_defaultDirImageKey[CreatureDir_Left] = "left";
	_defaultDirImageKey[CreatureDir_Right] = "right";


	_defaultStateImageKey[CreatureState_Stop] = "stop";
	_defaultStateImageKey[CreatureState_Move] = "walk";
	_defaultStateImageKey[CreatureState_Dead] = "dead";
}


CreatureStorage::~CreatureStorage(void)
{
}

void CreatureStorage::loadXml(const char* xmlPath)
{
	TiXmlDocument xmlfile;
	if (xmlfile.LoadFile(xmlPath, TIXML_ENCODING_UTF8))
	{
		TiXmlNode* node = xmlfile.FirstChild("creatureinfos");
		if (node)
		{
			TiXmlElement* nodeelement = node->FirstChildElement("info");
			while(nodeelement)
			{
				creatureInfo* info = new creatureInfo();
				info->id = boost::lexical_cast<int>(nodeelement->Attribute("id"));
				info->_life = boost::lexical_cast<int>(nodeelement->Attribute("life"));
				info->_speed = boost::lexical_cast<float>(nodeelement->Attribute("speed"));
				info->_name = nodeelement->Attribute("name");
				info->_resourceName = nodeelement->Attribute("resourcename");
				_creatureInfos.insert(MAPCREATURES::value_type(info->id, info));
				nodeelement = nodeelement->NextSiblingElement("info");
			}
		}
	}
}

baseCreature* CreatureStorage::CreateCreature(const char* name)
{
	baseCreature* creature = new baseCreature();
	creature->LoadResource(name);	
	return creature;
}

baseCreature* CreatureStorage::CreateCreature(int id)
{

	MAPCREATURES::iterator it = _creatureInfos.find(id);
	if (it != _creatureInfos.end())
	{
		creatureInfo* info = it->second;
		baseCreature* creature = new baseCreature();
		creature->createCreature(info);
		return creature;
	}

	return NULL;
}
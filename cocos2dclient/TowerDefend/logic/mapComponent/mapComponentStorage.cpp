#include "StdAfx.h"
#include "mapComponentStorage.h"
#include "boost/lexical_cast.hpp"
#include "Platform/Util.h"
#include "mapStaticCell.h"

initialiseSingleton(mapComponentStorage);
mapComponentStorage::mapComponentStorage(void)
{
}


mapComponentStorage::~mapComponentStorage(void)
{
}

void mapComponentStorage::LoadXml(const char* xmlpath)
{
	TiXmlDocument xmlfile;
	if (xmlfile.LoadFile(xmlpath, TIXML_ENCODING_UTF8))
	{
		TiXmlNode* node = xmlfile.FirstChild("mapcells");
		if (node)
		{
			mapComponentTG* tg = NULL;
			TiXmlElement* element = node->FirstChildElement("info");
			while(element)
			{
				tg = new mapComponentTG();
				tg->_id = boost::lexical_cast<int>(element->Attribute("id"));
				tg->_life = boost::lexical_cast<int>(element->Attribute("life"));
				//tg->_block = boost::lexical_cast<bool>("0");
				tg->_block = boost::lexical_cast<bool>(element->Attribute("block"));
				tg->_canattack = boost::lexical_cast<bool>(element->Attribute("canAttack"));
				tg->_animation = element->Attribute("animationname");
				tg->_deadanimation = element->Attribute("deadanimationname");
				tg->_randomdeadbox = boost::lexical_cast<int>(element->Attribute("deadBox"));
				_Data.insert(MAPDATAS::value_type(tg->_id, tg));
				element = element->NextSiblingElement("info");
			}
		}
	}
}

baseMapCell* mapComponentStorage::CreateMapComponent(int id)
{
	mapStaticCell* cell = NULL;
	MAPDATAS::iterator it = _Data.find(id);
	if (it != _Data.end())
	{
		cell = new mapStaticCell();
		cell->CreateCell(it->second);
	}

	return cell;
}
#include "StdAfx.h"
#include "gameMap.h"
#include "boost/lexical_cast.hpp"
#include "Platform/Util.h"
#include "mapComponentStorage.h"
#include "BaseMapCell.h"
#include "../TDWorld.h"
#include "../astar/Astar.h"
gameMap::gameMap()
	:_width(0),
	_height(0),
	_cellwidth(0),
	_cellheight(0),
	_offsetx(0),
	_offsety(0),
	_mapdata(NULL),
	_tile_map(NULL)
{
}

gameMap::~gameMap()
{

}


void gameMap::Create(const char* xml)
{
	TiXmlDocument xmlfile;
	if (xmlfile.LoadFile(xml, TIXML_ENCODING_UTF8))
	{
		TiXmlNode* mapnode = xmlfile.FirstChild("map");
		if (mapnode)
		{
			TiXmlElement* mapInfo = mapnode->FirstChildElement("mapInfo");
			if (mapInfo)
			{
				_width = boost::lexical_cast<int>(mapInfo->Attribute("width"));
				_height = boost::lexical_cast<int>(mapInfo->Attribute("height"));
				_cellheight = boost::lexical_cast<int>(mapInfo->Attribute("cellwidth"));
				_cellwidth = boost::lexical_cast<int>(mapInfo->Attribute("cellheight"));
				_offsetx = boost::lexical_cast<int>(mapInfo->Attribute("offsetx"));
				_offsety =  boost::lexical_cast<int>(mapInfo->Attribute("offsety"));
				TiXmlNode* cellNodes = mapnode->FirstChild("mapCells");
				std::string line;

				if (cellNodes&& _width != 0 && _width != 0)
				{
					if (!_mapdata)
					{
						_mapdata = new char[_width * _height];
						_tile_map = new tile_map();
						_tile_map->column = _width;
						_tile_map->row = _height;
						init_map(_tile_map);
					}
					Tokens sarray;
					TiXmlElement* cellInfoNode = (TiXmlElement*)cellNodes->FirstChild("Info");
					int pos = 0;
					while(cellInfoNode)
					{
						line = cellInfoNode->Attribute("Line");
						sarray = StrSplit(line,",");
						Tokens::iterator it = sarray.begin();
						for (; it != sarray.end(); ++ it)
						{
							int n = boost::lexical_cast<int>(*it);
							*(_mapdata + pos) = n;
							pos ++;
						}
						//line.substr()
						cellInfoNode = cellInfoNode->NextSiblingElement("Info");
					}
					
				}

			}

		}
	}

	createMap();
	
}


bool gameMap::setRoadBlock(int row, int col, bool block)
{
	if (_tile_map&&_tile_map->row < row&& _tile_map->column < col)
	{
		if (block)
		{
			gen_cell(_tile_map, col, block, WALL);
		}
		else
		{
			gen_cell(_tile_map, col, block, EMPTY);
		}

		return true;
	}
	return false;
}

void gameMap::createMap()
{
	if (_mapdata)
	{
		int heightcount = 0;
		for (int i = 0; i < _height; i ++)
		{
			heightcount = i * _width;
			float posY = i * _cellheight;
			
			for (int j = 0; j < _width; j ++)
			{
				
				int n = *(_mapdata + heightcount + j);
				baseMapCell* cell =mapComponentStorage::getSingletonPtr()->CreateMapComponent(n);
				if (cell)
				{
					float posX = j * _cellwidth;
					cell->setPosition(posX/2.f, posY/2.f);
					TDWorld::getSingletonPtr()->addcell(cell);
					if (_tile_map&&cell->is_block())
					{
						setRoadBlock(j, i, true);
					}
					else
					{
						setRoadBlock(j, i, false);
					}
					//_mapObjs.push_back(cell);
				}

			}
		}
	}
}
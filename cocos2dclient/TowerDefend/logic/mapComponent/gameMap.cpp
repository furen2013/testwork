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
	if (_tile_map&&_tile_map->row > row&& _tile_map->column > col)
	{
		if (block)
		{
			gen_cell(_tile_map, col, row, WALL);
		}
		else
		{
			gen_cell(_tile_map, col, row, EMPTY);
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
			float posY = i * _cellheight + _offsety;
			
			for (int j = 0; j < _width; j ++)
			{
				
				int n = *(_mapdata + heightcount + j);


				baseMapCell* cell =mapComponentStorage::getSingletonPtr()->CreateMapComponent(n);
				if (cell)
				{
					float posX = j * _cellwidth + _offsetx;
					if (n == 2)
					{
						_endCellCenterPoint.x = posX + _cellwidth / 2.f;;
						_endCellCenterPoint.y = posY + _cellheight / 2.f;;
						_endPoint = getCell(_endCellCenterPoint);
					}
					else if (n == 3)
					{
						_startCellCenterPoint.x = posX + _cellwidth / 2.f;
						_startCellCenterPoint.y = posY + _cellheight / 2.f;
					}
					
					cell->setPosition(posX, posY);
					TDWorld::getSingletonPtr()->addcell(cell);
					if (_tile_map)
					{
						if (cell->is_block())
						{
							setRoadBlock(i, j, true);
						}
						else
						{
							setRoadBlock(i, j, false);
						}
					}
					//_mapObjs.push_back(cell);
				}

			}
		}
	}
}

bool gameMap::getNextRoad(CCPoint startPoint, CCPoint& nextPoint)
{
	aPoint p = getCell(startPoint);
	
	aPoint nextstep;
	if (astar_next_step(_tile_map, p.posX, p.posY, _endPoint.posX, _endPoint.posY, nextstep, manhattan_distance))
	{
		nextPoint = getCellCenterPoint(nextstep.posX, nextstep.posY);
		return true;
	}
	return false;
}

CCPoint gameMap::getCellCenterPoint(int posX, int posY)
{
	CCPoint point;
	point.x = posX * _cellwidth + _offsetx;
	point.y = posY * _cellheight + _offsety;
	return point;
}

aPoint gameMap::getCell(CCPoint point)
{
	aPoint cellpoint;
	cellpoint.posX = (point.x - _offsetx) / _cellwidth;
	cellpoint.posY = (point.y - _offsety) / _cellheight;
	return cellpoint;
}

bool gameMap::getFullWay(CCPoint startPoint, std::vector<CCPoint>& way)
{
	aPoint p = getCell(startPoint);

	aPoint nextstep;
	if (astar_full_road(_tile_map, p.posX, p.posY, _endPoint.posX, _endPoint.posY, way, _cellwidth,
		_cellheight, _offsetx, _offsety, manhattan_distance))
	{
		//nextPoint = getCellCenterPoint(nextstep.posX, nextstep.posY);
		return true;
	}
	return false;
}

bool gameMap::isArrived(CCPoint pos)
{
	if (_endCellCenterPoint.x == pos.x && _endCellCenterPoint.y == pos.y)
	{
		return true;
	}
	return false;
}

CCPoint gameMap::getStartPt()
{
	return _startCellCenterPoint;
}

CCPoint gameMap::getEndPt()
{
	return _endCellCenterPoint;
}
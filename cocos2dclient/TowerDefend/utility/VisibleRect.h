#pragma once
#ifndef __VISIBLERECT_H__
#define __VISIBLERECT_H__

//#include "cocos2d.h"
class utilityRectPoisition;
USING_NS_CC;

class VisibleRect
{
public:
    static CCRect* getVisibleRect();

    static CCPoint left();
    static CCPoint right();
    static CCPoint top();
    static CCPoint bottom();
    static CCPoint center();
    static CCPoint leftTop();
    static CCPoint rightTop();
    static CCPoint leftBottom();
    static CCPoint rightBottom();
private:
    static void lazyInit();
    static CCRect s_visibleRect;
};

struct utilityRectPosX
{
	utilityRectPosX();
	enum posXType{
		posXType_Left,
		PosXType_Middle,
		posXType_Right,
	};
	posXType    _en;
	float       _offsetX; 
	utilityRectPoisition* _parent;
	float _getRectMidX();
	float _getLeftPosX();
	float _getRightPosX();
	float _getMiddlePosX();

};

struct utilityRectPosY
{
	utilityRectPosY();
	enum posYType{
		posYType_Top,
		PosYType_Middle,
		posYType_Bottom,
	};
	posYType     _en;
	float       _offsetY; 
	utilityRectPoisition* _parent;
	float _getMidRectY();
	float _getTopPosY();
	float _getBottomPosY();
	float _getMiddlePosY();
};

#endif /* __VISIBLERECT_H__ */

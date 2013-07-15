#pragma once
#include "cocos2d.h"
#include "cocoa/CCGeometry.h"
#include "GdiPlusEnums.h"
#include "GdiPlusTypes.h"
#include "VisibleRect.h"
#include <assert.h>

USING_NS_CC;


class utilityRectPoisition
{
public:
	utilityRectPoisition(utilityRectPosX::posXType enX, float offsetX, utilityRectPosY::posYType enY, float offsetY, CCRect* rect);
	utilityRectPoisition(utilityRectPosX& PosX, utilityRectPosY& PosY, CCRect* rect);
	utilityRectPoisition();
	~utilityRectPoisition(void);
public:
	void _setRect(CCRect* Rect);
	void _setPosX(utilityRectPosX PosX);
	void _setPosY(utilityRectPosY PosY);
	float _getLeftPosX();
	float _getRightPosX();
	float _getMiddlePosX();
	float _getTopPosY();
	float _getBottomPosY();
	float _getMiddlePosY();

	Point _getRectLTpt();
	Point _getRectLMpt();
	Point _getRectLBpt();
	Point _getRectMTpt();
	Point _getRectMMpt();
	Point _getRectMBpt();
	Point _getRectRTpt();
	Point _getRectRMpt();
	Point _getRectRBpt();

	CCPoint _getRectLTccpt();
	CCPoint _getRectLMccpt();
	CCPoint _getRectLBccpt();
	CCPoint _getRectMTccpt();
	CCPoint _getRectMMccpt();
	CCPoint _getRectMBccpt();
	CCPoint _getRectRTccpt();
	CCPoint _getRectRMccpt();
	CCPoint _getRectRBccpt();


	Point _getLTpt();
	Point _getLMpt();
	Point _getLBpt();
	Point _getMTpt();
	Point _getMMpt();
	Point _getMBpt();
	Point _getRTpt();
	Point _getRMpt();
	Point _getRBpt();

	CCPoint _getLTccpt();
	CCPoint _getLMccpt();
	CCPoint _getLBccpt();
	CCPoint _getMTccpt();
	CCPoint _getMMccpt();
	CCPoint _getMBccpt();
	CCPoint _getRTccpt();
	CCPoint _getRMccpt();
	CCPoint _getRBccpt();
	CCRect* _getRect(){return _Rect;}

private:
	utilityRectPosX _PosX;
	utilityRectPosY	_PosY;	
	CCRect*		_Rect;	
};


#include "StdAfx.h"
#include "utilityPoisition.h"
#include <assert.h>



utilityRectPoisition::utilityRectPoisition(utilityRectPosX::posXType enX, float offsetX, utilityRectPosY::posYType enY, float offsetY, CCRect* rect)
{
	_PosX._offsetX = offsetX;
	_PosX._en = enX;
	_PosY._offsetY = offsetY;
	_PosY._en = enY;
	_Rect = rect;
}
utilityRectPoisition::utilityRectPoisition(utilityRectPosX& PosX, utilityRectPosY& PosY , CCRect* rect)
{
	_PosX = PosX;
	_PosY = PosY;
	_Rect = rect;
}

utilityRectPoisition::utilityRectPoisition()
{

}
utilityRectPoisition::~utilityRectPoisition(void)
{
}


void utilityRectPoisition::_setRect(CCRect* Rect)
{
	_Rect = Rect;
}
void utilityRectPoisition::_setPosX(utilityRectPosX PosX)
{
	_PosX = PosX;
}
void utilityRectPoisition::_setPosY(utilityRectPosY PosY)
{
	_PosY = PosY;
}

float utilityRectPoisition::_getLeftPosX()
{
	return _PosX._getLeftPosX();
}
float utilityRectPoisition::_getRightPosX()
{
	return _PosX._getRightPosX();
}
float utilityRectPoisition::_getMiddlePosX()
{
	return _PosX._getMiddlePosX();
}

float utilityRectPoisition::_getTopPosY()
{
	return _PosY._getTopPosY();
}
float utilityRectPoisition::_getBottomPosY()
{
	return _PosY._getBottomPosY();
}
float utilityRectPoisition::_getMiddlePosY()
{
	return _PosY._getMiddlePosY();
}
Point utilityRectPoisition::_getRectLTpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMinX(), _Rect->getMaxY());
	return pt;

}
Point utilityRectPoisition::_getRectLMpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMinX(), _Rect->getMidY());
	return pt;
}
Point utilityRectPoisition::_getRectLBpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMinX(), _Rect->getMinY());
	return pt;
}
Point utilityRectPoisition::_getRectMTpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMidX(), _Rect->getMaxY());
	return pt;
}
Point utilityRectPoisition::_getRectMMpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMidX(), _Rect->getMidY());
	return pt;
}
Point utilityRectPoisition::_getRectMBpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMidX(), _Rect->getMinY());
	return pt;
}
Point utilityRectPoisition::_getRectRTpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMaxX(), _Rect->getMaxY());
	return pt;
}
Point utilityRectPoisition::_getRectRMpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMaxX(), _Rect->getMidY());
	return pt;
}
Point utilityRectPoisition::_getRectRBpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	Point pt(_Rect->getMaxX(), _Rect->getMinY());
	return pt;
}

CCPoint utilityRectPoisition::_getRectLTccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMinX(), _Rect->getMaxY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectLMccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMinX(), _Rect->getMidY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectLBccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMinX(), _Rect->getMinY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectMTccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMidX(), _Rect->getMaxY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectMMccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMidX(), _Rect->getMidY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectMBccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMidX(), _Rect->getMinY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectRTccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMaxX(), _Rect->getMaxY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectRMccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMaxX(), _Rect->getMidY());
	return pt;
}
CCPoint utilityRectPoisition::_getRectRBccpt()
{
	if (!_Rect)
	{
		assert(!_Rect);
	}
	CCPoint pt(_Rect->getMaxX(), _Rect->getMinY());
	return pt;
}


Point utilityRectPoisition::_getLTpt()
{
	Point pt(_getLeftPosX(), _getTopPosY());
	return pt;
}
Point utilityRectPoisition::_getLMpt()
{
	Point pt(_getLeftPosX(), _getMiddlePosY());
	return pt;
}
Point utilityRectPoisition::_getLBpt()
{
	Point pt(_getLeftPosX(), _getMiddlePosY());
	return pt;
}
Point utilityRectPoisition::_getMTpt()
{
	Point pt(_getMiddlePosX(), _getTopPosY());
	return pt;
}
Point utilityRectPoisition::_getMMpt()
{
	Point pt(_getMiddlePosX(), _getMiddlePosY());
	return pt;
}
Point utilityRectPoisition::_getMBpt()
{
	Point pt(_getMiddlePosX(), _getTopPosY());
	return pt;
}
Point utilityRectPoisition::_getRTpt()
{
	Point pt(_getRightPosX(), _getTopPosY());
	return pt;
}
Point utilityRectPoisition::_getRMpt()
{
	Point pt(_getRightPosX(), _getMiddlePosY());
	return pt;
}
Point utilityRectPoisition::_getRBpt()
{
	Point pt(_getRightPosX(), _getBottomPosY());
	return pt;
}

CCPoint utilityRectPoisition::_getLTccpt()
{
	CCPoint pt(_getLeftPosX(), _getTopPosY());
	return pt;
}
CCPoint utilityRectPoisition::_getLMccpt()
{
	CCPoint pt(_getLeftPosX(), _getMiddlePosY());
	return pt;
}
CCPoint utilityRectPoisition::_getLBccpt()
{
	CCPoint pt(_getLeftPosX(), _getBottomPosY());
	return pt;
}
CCPoint utilityRectPoisition::_getMTccpt()
{
	CCPoint pt(_getMiddlePosX(), _getTopPosY());
	return pt;
}
CCPoint utilityRectPoisition::_getMMccpt()
{
	CCPoint pt(_getMiddlePosX(), _getMiddlePosY());
	return pt;
}
CCPoint utilityRectPoisition::_getMBccpt()
{

	CCPoint pt(_getMiddlePosX(), _getBottomPosY());
	return pt;
}
CCPoint utilityRectPoisition::_getRTccpt()
{
	CCPoint pt(_getRightPosX(),_getTopPosY());
	return pt;
}
CCPoint utilityRectPoisition::_getRMccpt()
{
	CCPoint pt(_getRightPosX(),_getMiddlePosY());
	return pt;

}
CCPoint utilityRectPoisition::_getRBccpt()
{
	CCPoint pt(_getRightPosX(),_getBottomPosY());
	return pt;
}
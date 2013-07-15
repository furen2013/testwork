#include "stdafx.h"
#include "VisibleRect.h"
#include "utilityPoisition.h"

CCRect VisibleRect::s_visibleRect;

void VisibleRect::lazyInit()
{
    if (s_visibleRect.size.width == 0.0f && s_visibleRect.size.height == 0.0f)
    {
        CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
        s_visibleRect.origin = pEGLView->getVisibleOrigin();
        s_visibleRect.size = pEGLView->getVisibleSize();
    }
}

CCRect* VisibleRect::getVisibleRect()
{
    lazyInit();
    return &s_visibleRect;
}

CCPoint VisibleRect::left()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::right()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::top()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::bottom()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

CCPoint VisibleRect::center()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::leftTop()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::rightTop()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::leftBottom()
{
    lazyInit();
    return s_visibleRect.origin;
}

CCPoint VisibleRect::rightBottom()
{
    lazyInit();
    return ccp(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}




utilityRectPosX::utilityRectPosX()
{
	_en = posXType_Left;
	_offsetX = 0.f;
	_parent = NULL;
}
float utilityRectPosX::_getRectMidX()
{
	CCRect* Rect = _parent->_getRect();
	if (Rect == NULL)
	{
		assert(!Rect);
		return 0.f;
	}
	float TempX = (Rect->getMinX() + Rect->getMaxX())/2.f;
	return TempX;
}

float utilityRectPosX::_getLeftPosX()
{
	CCRect* Rect = _parent->_getRect();
	if (Rect == NULL)
	{
		assert(!Rect);
		return 0.f;
	}

	float minX = Rect->getMinX();
	float maxX = Rect->getMaxX();

	float TempX = 0;
	switch(_en)
	{
	case PosXType_Middle:
		{
			TempX = _offsetX -  _getRectMidX();
		}
		break;
	case posXType_Right:
		{
			TempX =_offsetX - maxX;
		}
		break;
	case posXType_Left:
		{
			TempX =  _offsetX;
		}
		break;
	}
	return TempX;
}
float utilityRectPosX::_getRightPosX()
{
	CCRect* Rect = _parent->_getRect();
	float minX = Rect->getMinX();
	float maxX = Rect->getMaxX();

	float TempX = 0;

	switch(_en)
	{
	case PosXType_Middle:
		{
			TempX = _offsetX -_getRectMidX();
		}
		break;
	case posXType_Right:
		{
			TempX = _offsetX;
		}
		break;
	case posXType_Left:
		{
			TempX = _offsetX - maxX;
		}
		break;

	}
	return TempX;
}
float utilityRectPosX::_getMiddlePosX()
{
	CCRect* Rect = _parent->_getRect();
	float minX = Rect->getMinX();
	float maxX = Rect->getMaxX();

	float TempX = 0.f;
	switch(_en)
	{
	case PosXType_Middle:
		{
			TempX = _offsetX;
		}
		break;
	case posXType_Right:
		{
			TempX = _offsetX + _getMiddlePosX();
		}
		break;
	case posXType_Left:
		{
			TempX = maxX + _offsetX;
		}
		break;
	}

	return TempX;
}



utilityRectPosY::utilityRectPosY()
{

	_en = posYType_Top;
	_parent = NULL;
	_offsetY = 0.f;
}
float utilityRectPosY::_getMidRectY()
{
	CCRect* Rect = _parent->_getRect();
	if (!Rect)
	{
		assert(!Rect);

	}
	float mid = (Rect->getMaxY() + Rect->getMinY())/2.f;
	return mid;

}
float utilityRectPosY::_getTopPosY()
{
	CCRect* Rect = _parent->_getRect();
	if (!Rect)
	{
		assert(!Rect);

	}
	float tempPosY = 0.f;
	float minPosY = Rect->getMinY();
	float maxPosY = Rect->getMaxY();
	float midY = _getMidRectY();
	switch(_en)
	{
	case posYType_Top:
		{
			tempPosY = _offsetY;
		}
		break;
	case PosYType_Middle:
		{
			tempPosY = _offsetY - midY;
		}
		break;
	case posYType_Bottom:
		{
			tempPosY = maxPosY + _offsetY;
		}
	}
	return tempPosY;
}
float utilityRectPosY::_getBottomPosY()
{
	CCRect* Rect = _parent->_getRect();
	if (!Rect)
	{
		assert(!Rect);

	}
	float tempPosY = 0.f;
	float minPosY = Rect->getMinY();
	float maxPosY = Rect->getMaxY();
	float midY = _getMidRectY();
	switch(_en)
	{
	case posYType_Top:
		{
			tempPosY = _offsetY - maxPosY;
		}
		break;
	case PosYType_Middle:
		{
			tempPosY = _offsetY - midY;
		}
		break;
	case posYType_Bottom:
		{
			tempPosY = _offsetY;
		}
	}
	return tempPosY;
}
float utilityRectPosY::_getMiddlePosY()
{
	CCRect* Rect = _parent->_getRect();
	if (!Rect)
	{
		assert(!Rect);

	}
	float tempPosY = 0.f;
	float minPosY = Rect->getMinY();
	float maxPosY = Rect->getMaxY();
	float midY = _getMidRectY();
	switch(_en)
	{
	case posYType_Top:
		{
			tempPosY = _offsetY - midY;
		}
		break;
	case PosYType_Middle:
		{
			tempPosY = _offsetY;
		}
		break;
	case posYType_Bottom:
		{
			tempPosY = _offsetY + midY;
		}
	}
	return tempPosY;
}

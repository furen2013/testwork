#include "StdAfx.h"
#include "myLayer.h"
#include "../../utility/utilityItemComponent.h"

myLayer::myLayer(void)
{
}


myLayer::~myLayer(void)
{
}


CCMenuItemImage* myLayer::CreateMenuItemImage(ItemImageResource* pImagePath, SEL_MenuHandler selector)
{
	const ItemImageResurcePath& path = pImagePath->imagepath;
	CCMenuItemImage* p = CCMenuItemImage::create(path._ItemImage[ItemImagePath_Normal].c_str(),
		path._ItemImage[ItemImagePath_Selected].c_str(), path._ItemImage[ItemImagePath_Disabled].c_str(),
		this, selector);
	p->setPosition(pImagePath->ItemPos._getLBccpt());
	return p;

}

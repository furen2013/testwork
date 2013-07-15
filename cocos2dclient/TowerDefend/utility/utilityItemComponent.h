#pragma once
#ifndef UTILITYITEMCOMPONENT_H
#define UTILITYITEMCOMPONENT_H
#include "utilityPoisition.h"
#include <iostream>
enum ItemImageTypePath
{
	ItemImagePath_Normal,
	ItemImagePath_Selected,
	ItemImagePath_Disabled,
	ItemImagePath_Max,
};


struct ItemImageResurcePath
{
	ItemImageResurcePath()
	{

	}
	std::string _ItemImage[ItemImagePath_Max];
};

struct ItemImageResource
{
	ItemImageResurcePath imagepath;
	utilityRectPoisition ItemPos;

};
#endif
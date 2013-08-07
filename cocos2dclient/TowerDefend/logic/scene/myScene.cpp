#include "StdAfx.h"
#include "myScene.h"
#include "myLayer.h"


myScene::myScene(void)
	:_layer(NULL)
{
}


myScene::~myScene(void)
{
}

void myScene::init(myLayer* layer)
{
	_layer = layer;
	if (_layer)
	{
		_layer->init();
		addChild(_layer);
	}
}

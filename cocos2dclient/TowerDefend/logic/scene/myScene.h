#pragma once
#ifndef MYSCENE_H
#define MYSCENE_H
class myLayer;
class myScene  : public cocos2d::CCScene
{
public:
	myScene(void);
	virtual ~myScene(void);
public:
	virtual void init(myLayer* layer);
protected:
	myLayer* _layer;
};

#endif
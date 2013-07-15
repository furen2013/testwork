#ifndef LOGINSCENE_H
#define LOGINSCENE_H


#pragma once
#include "cocos2d.h"
#include <iostream>
#include "../../utility/utilityItemComponent.h"
#include "../../utility/utilityPoisition.h"
class KeyboardNotificationLayer;

/**
@brief    TextInputTest for retain prev, reset, next, main menu buttons.
*/
class LoginController : public CCLayer
{

public:
	LoginController();
	virtual ~LoginController();
public:
	void TextInputTest();

	void Login(CCObject* pSender);
	void Logout(CCObject* pSender);
	void addKeyboardNotificationLayer(KeyboardNotificationLayer * pLayer);


	virtual void onEnter();
protected:
	CCMenuItemImage* CreateMenuItemImage(ItemImageResource* p, SEL_MenuHandler selector);

private:
	KeyboardNotificationLayer * m_pNotificationLayer;
	ItemImageResource _LoginImagePath;
	ItemImageResource _LogoutImagePath;

	CCMenuItemImage* _pLoginMenuItemImage;
	CCMenuItemImage* _pLogoutMenuItemImage;
};


//////////////////////////////////////////////////////////////////////////
// KeyboardNotificationLayer for test IME keyboard notification.
//////////////////////////////////////////////////////////////////////////

class KeyboardNotificationLayer : public CCLayer, public CCIMEDelegate
{
public:
	KeyboardNotificationLayer();

	virtual std::string subtitle() = 0;
	virtual void onClickTrackNode(bool bClicked) = 0;

	virtual void registerWithTouchDispatcher();
	virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo& info);

	// CCLayer
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

protected:
	CCNode * m_pTrackNode;
	CCPoint  m_beginPos;
};

//////////////////////////////////////////////////////////////////////////
// TextFieldTTFDefaultTest for test TextFieldTTF default behavior.
//////////////////////////////////////////////////////////////////////////

class TextFieldTTFDefaultTest : public KeyboardNotificationLayer
{
public:
	// KeyboardNotificationLayer
	virtual std::string subtitle();
	virtual void onClickTrackNode(bool bClicked);

	// CCLayer
	virtual void onEnter();
};

//////////////////////////////////////////////////////////////////////////
// TextFieldTTFActionTest
//////////////////////////////////////////////////////////////////////////

class TextFieldTTFActionTest : public KeyboardNotificationLayer, public CCTextFieldDelegate
{
	CCTextFieldTTF *    m_pTextField;
	CCAction *          m_pTextFieldAction;
	bool                m_bAction;
	int                 m_nCharLimit;       // the textfield max char limit

public:
	void callbackRemoveNodeWhenDidAction(CCNode * pNode);

	// KeyboardNotificationLayer
	virtual std::string subtitle();
	virtual void onClickTrackNode(bool bClicked);

	// CCLayer
	virtual void onEnter();
	virtual void onExit();

	// CCTextFieldDelegate
	virtual bool onTextFieldAttachWithIME(CCTextFieldTTF * pSender);
	virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
	virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
	virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);
	virtual bool onDraw(CCTextFieldTTF * pSender);
};


class LoginScene : public cocos2d::CCScene
{
public:
	LoginScene();
	~LoginScene();
public:
};
//////////////////////
#endif
#pragma once
#ifndef LOGINSCENE_H
#define LOGINSCENE_H
//#include "cocos2d.h"
#include <iostream>
#include "../../utility/utilityItemComponent.h"
#include "../../utility/utilityPoisition.h"
#include "myLayer.h"
#include "myScene.h"
class KeyboardNotificationLayer;
class TextFieldTTFActionTest;
class baseCreature;
/**
@brief    TextInputTest for retain prev, reset, next, main menu buttons.
*/
class LoginController : public myLayer
{

public:
	LoginController();
	virtual ~LoginController();
public:
	virtual void init();
	void TextInputTest();

	void Login(CCObject* pSender);
	void Logout(CCObject* pSender);
	void addKeyboardNotificationLayer(KeyboardNotificationLayer * pLayer);
	virtual void onEnter();
private:
	ItemImageResource _LoginImagePath;
	ItemImageResource _LogoutImagePath;

	CCMenuItemImage* _pLoginMenuItemImage;
	CCMenuItemImage* _pLogoutMenuItemImage;
	CCMenu* _Menu; 

	TextFieldTTFActionTest* _account;
	TextFieldTTFActionTest* _password;
	baseCreature*		    _baseCreature;	
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
	void _setRectPos(utilityRectPoisition& pos);

protected:
	utilityRectPoisition _RectPos;
};

//////////////////////////////////////////////////////////////////////////
// TextFieldTTFActionTest
//////////////////////////////////////////////////////////////////////////

class TextFieldTTFActionTest : public KeyboardNotificationLayer, public CCTextFieldDelegate
{
public:
	enum enType{
		TextFieldTTFAction_Normal,
		TextFieldTTFAction_Password,
	};
public:
	TextFieldTTFActionTest();
	~TextFieldTTFActionTest();
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


	void _setRectPos(utilityRectPoisition& pos);
	void _setType(enType en){_editType = en;}

protected:
	//virtual void draw();

protected:
	utilityRectPoisition _RectPos;
	CCTextFieldTTF *    m_pTextField;
	CCAction *          m_pTextFieldAction;
	bool                m_bAction;
	int                 m_nCharLimit;       // the textfield max char limit
	std::string			_text;
	enType				_editType;
};


class LoginScene : public myScene
{
public:
	LoginScene();
	virtual ~LoginScene();
public:
	virtual void init(myLayer* layer);
};
//////////////////////
#endif
#include "StdAfx.h"
#include "LoginScene.h"
#include "../../utility/VisibleRect.h"
#include "../../utility/passwordTextFieldTTF.h"

enum 
{
	kTextFieldTTFDefaultTest = 0,
	kTextFieldTTFActionTest,
	kTextInputTestsCount,
}; 

#define FONT_NAME                       "Thonburi"
#define FONT_SIZE                       36

static int testIdx = -1; 
static CCRect getRect(CCNode * pNode)
{
	CCRect rc;
	rc.origin = pNode->getPosition();
	rc.size = pNode->getContentSize();
	rc.origin.x -= rc.size.width / 2;
	rc.origin.y -= rc.size.height / 2;
	return rc;
}

CCMenuItemImage* LoginController::CreateMenuItemImage(ItemImageResource* pImagePath, SEL_MenuHandler selector)
{
	const ItemImageResurcePath& path = pImagePath->imagepath;
	CCMenuItemImage* p = CCMenuItemImage::create(path._ItemImage[ItemImagePath_Normal].c_str(),
		path._ItemImage[ItemImagePath_Selected].c_str(), path._ItemImage[ItemImagePath_Disabled].c_str(),
		this, selector);
	p->setPosition(pImagePath->ItemPos._getLBccpt());
	return p;

}

void LoginController::Login(CCObject* pSender)
{

}
void LoginController::Logout(CCObject* pSender)
{

}

void LoginController::onEnter()
{
	CCLayer::onEnter();
}

LoginController::LoginController()
{
	// add close menu
	utilityRectPosX posX;
	posX._en = utilityRectPosX::PosXType_Middle;
	posX._offsetX = - 20;
	utilityRectPosY posY;
	posY._en = utilityRectPosY::posYType_Bottom;
	posY._offsetY =  40.f;

	_LoginImagePath.ItemPos._setRect(VisibleRect::getVisibleRect());
	_LoginImagePath.ItemPos._setPosX(posX);
	_LoginImagePath.ItemPos._setPosY(posY);
	
	posX._offsetX = 20.f;
	_LogoutImagePath.ItemPos._setRect(VisibleRect::getVisibleRect());
	_LogoutImagePath.ItemPos._setPosX(posX);
	_LogoutImagePath.ItemPos._setPosY(posY);

	for (int i = ItemImagePath_Normal; i < ItemImagePath_Max; i ++)
	{
		_LoginImagePath.imagepath._ItemImage[i] = "res/CloseNormal.png";
		_LogoutImagePath.imagepath._ItemImage[i] = "res/CloseNormal.png";
	}
	

	_pLoginMenuItemImage = CreateMenuItemImage(&_LoginImagePath, menu_selector(LoginController::Login));
	_pLogoutMenuItemImage = CreateMenuItemImage(&_LogoutImagePath, menu_selector(LoginController::Logout));
	_Menu  =CCMenu::create(_pLoginMenuItemImage, NULL);
	_Menu->addChild(_pLogoutMenuItemImage);

	_Menu->setPosition( CCPointZero );
	posX._en = utilityRectPosX::PosXType_Middle;
	posX._offsetX = - 20;

	posY._en = utilityRectPosY::PosYType_Middle;
	posY._offsetY =  40.f;
	utilityRectPoisition pos;
	pos._setPosX(posX);
	pos._setPosY(posY);
	pos._setRect(VisibleRect::getVisibleRect());
	_account = new TextFieldTTFActionTest();
	_account->_setRectPos(pos);
	_password = new TextFieldTTFActionTest();
	posY._offsetY = 0.f;
	pos._setRect(VisibleRect::getVisibleRect());
	pos._setPosY(posY);
	_password->_setRectPos(pos);
	_password->_setType(TextFieldTTFActionTest::TextFieldTTFAction_Password);
	addChild(_Menu);
	addChild(_account);
	addChild(_password);

	// add menu items for tests
}


LoginController::~LoginController()
{

}

LoginScene::LoginScene(void)
{
}


LoginScene::~LoginScene(void)
{
}

//////////////////////////////////////////////////////////////////////////
// implement KeyboardNotificationLayer
//////////////////////////////////////////////////////////////////////////

KeyboardNotificationLayer::KeyboardNotificationLayer()
	: m_pTrackNode(0)
{
	setTouchEnabled(true);
}

void KeyboardNotificationLayer::registerWithTouchDispatcher()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

void KeyboardNotificationLayer::keyboardWillShow(CCIMEKeyboardNotificationInfo& info)
{
	CCLOG("TextInputTest:keyboardWillShowAt(origin:%f,%f, size:%f,%f)",
		info.end.origin.x, info.end.origin.y, info.end.size.width, info.end.size.height);

	if (! m_pTrackNode)
	{
		return;
	}

	CCRect rectTracked = getRect(m_pTrackNode);
	CCLOG("TextInputTest:trackingNodeAt(origin:%f,%f, size:%f,%f)",
		rectTracked.origin.x, rectTracked.origin.y, rectTracked.size.width, rectTracked.size.height);

	// if the keyboard area doesn't intersect with the tracking node area, nothing need to do.
	if (! rectTracked.intersectsRect(info.end))
	{
		return;
	}

	// assume keyboard at the bottom of screen, calculate the vertical adjustment.
	float adjustVert = info.end.getMaxY() - rectTracked.getMinY();
	CCLOG("TextInputTest:needAdjustVerticalPosition(%f)", adjustVert);

	// move all the children node of KeyboardNotificationLayer
	CCArray * children = getChildren();
	CCNode * node = 0;
	int count = children->count();
	CCPoint pos;
	for (int i = 0; i < count; ++i)
	{
		node = (CCNode*)children->objectAtIndex(i);
		pos = node->getPosition();
		pos.y += adjustVert;
		node->setPosition(pos);
	}
}

// CCLayer function

bool KeyboardNotificationLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("++++++++++++++++++++++++++++++++++++++++++++");
	m_beginPos = pTouch->getLocation();    
	return true;
}

void KeyboardNotificationLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (! m_pTrackNode)
	{
		return;
	}

	CCPoint endPos = pTouch->getLocation();    

	float delta = 5.0f;
	if (::abs(endPos.x - m_beginPos.x) > delta
		|| ::abs(endPos.y - m_beginPos.y) > delta)
	{
		// not click
		m_beginPos.x = m_beginPos.y = -1;
		return;
	}

	// decide the trackNode is clicked.
	CCRect rect;
	CCPoint point = convertTouchToNodeSpaceAR(pTouch);
	CCLOG("KeyboardNotificationLayer:clickedAt(%f,%f)", point.x, point.y);

	rect = getRect(m_pTrackNode);
	CCLOG("KeyboardNotificationLayer:TrackNode at(origin:%f,%f, size:%f,%f)",
		rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);

	this->onClickTrackNode(rect.containsPoint(point));
	CCLOG("----------------------------------");
}

//////////////////////////////////////////////////////////////////////////
// implement TextFieldTTFDefaultTest
//////////////////////////////////////////////////////////////////////////

std::string TextFieldTTFDefaultTest::subtitle()
{
	return "TextFieldTTF with default behavior test";
}

void TextFieldTTFDefaultTest::onClickTrackNode(bool bClicked)
{
	CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pTrackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFDefaultTest:CCTextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}

void TextFieldTTFDefaultTest::onEnter()
{
	KeyboardNotificationLayer::onEnter();

	// add CCTextFieldTTF
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	CCTextFieldTTF * pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
		FONT_NAME,
		FONT_SIZE);
	addChild(pTextField);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)    
	// on android, CCTextFieldTTF cannot auto adjust its position when soft-keyboard pop up
	// so we had to set a higher position to make it visable
	pTextField->setPosition(_RectPos._getLBccpt());
#else
	pTextField->setPosition(_RectPos._getLBccpt());
#endif

	m_pTrackNode = pTextField;
}


void TextFieldTTFDefaultTest::_setRectPos(utilityRectPoisition& pos)
{
	_RectPos = pos;
}


//////////////////////////////////////////////////////////////////////////
// implement TextFieldTTFActionTest
//////////////////////////////////////////////////////////////////////////

std::string TextFieldTTFActionTest::subtitle()
{
	return "CCTextFieldTTF with action and char limit test";
}

void TextFieldTTFActionTest::onClickTrackNode(bool bClicked)
{
	CCTextFieldTTF * pTextField = (CCTextFieldTTF*)m_pTrackNode;
	if (bClicked)
	{
		// TextFieldTTFTest be clicked
		CCLOG("TextFieldTTFActionTest:CCTextFieldTTF attachWithIME");
		pTextField->attachWithIME();
	}
	else
	{
		// TextFieldTTFTest not be clicked
		CCLOG("TextFieldTTFActionTest:CCTextFieldTTF detachWithIME");
		pTextField->detachWithIME();
	}
}


void TextFieldTTFActionTest::_setRectPos(utilityRectPoisition& pos)
{
	_RectPos._setData(pos);

	_RectPos._getLBccpt();
}

void TextFieldTTFActionTest::onEnter()
{
	KeyboardNotificationLayer::onEnter();

	m_nCharLimit = 12;

	m_pTextFieldAction = CCRepeatForever::create(
		(CCActionInterval*)CCSequence::create(
		CCFadeOut::create(0.25),
		CCFadeIn::create(0.25),
		0
		));
	m_pTextFieldAction->retain();
	m_bAction = false;

	// add CCTextFieldTTF
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	switch(_editType)
	{
	case TextFieldTTFAction_Password:
		{
			m_pTextField  = passwordTextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
				FONT_NAME,
				FONT_SIZE);
		}
		break;
	default:
		{
			m_pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for input>",
				FONT_NAME,
				FONT_SIZE);
		}
	}


	addChild(m_pTextField);

	m_pTextField->setDelegate(this);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)    
	// on android, CCTextFieldTTF cannot auto adjust its position when soft-keyboard pop up
	// so we had to set a higher position
	m_pTextField->setPosition(_RectPos._getLBccpt());
#else
	m_pTextField->setPosition(_RectPos._getLBccpt());
#endif

	m_pTrackNode = m_pTextField;
}

void TextFieldTTFActionTest::onExit()
{
	KeyboardNotificationLayer::onExit();
	m_pTextFieldAction->release();
}

// CCTextFieldDelegate protocol
bool TextFieldTTFActionTest::onTextFieldAttachWithIME(CCTextFieldTTF * pSender)
{
	if (! m_bAction)
	{
		m_pTextField->runAction(m_pTextFieldAction);
		m_bAction = true;
	}
	return false;
}

bool TextFieldTTFActionTest::onTextFieldDetachWithIME(CCTextFieldTTF * pSender)
{
	if (m_bAction)
	{
		m_pTextField->stopAction(m_pTextFieldAction);
		m_pTextField->setOpacity(255);
		m_bAction = false;
	}
	return false;
}

bool TextFieldTTFActionTest::onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen)
{
	// if insert enter, treat as default to detach with ime
	if ('\n' == *text)
	{
		return false;
	}

	// if the textfield's char count more than m_nCharLimit, doesn't insert text anymore.
	if (pSender->getCharCount() >= m_nCharLimit)
	{
		return true;
	}
	CCLabelTTF * label = NULL;
	// create a insert text sprite and do some action
	switch(_editType)
	{
	case TextFieldTTFAction_Normal:
		{
			label = CCLabelTTF::create(text, FONT_NAME, FONT_SIZE);
		}
		break;
	case  TextFieldTTFAction_Password:
		{
			label = CCLabelTTF::create("*", FONT_NAME, FONT_SIZE);
		}
		break;
	}
	if (label != NULL)
	{
		addChild(label);
		ccColor3B color = { 226, 121, 7};
		label->setColor(color);
	}

	_text += text;
	// move the sprite from top to position
	CCPoint endPos = pSender->getPosition();
	if (pSender->getCharCount())
	{
		endPos.x += pSender->getContentSize().width / 2;
	}
	CCSize  inputTextSize = label->getContentSize();
	CCPoint beginPos(endPos.x, CCDirector::sharedDirector()->getWinSize().height - inputTextSize.height * 2); 

	float duration = 0.5;
	label->setPosition(beginPos);
	label->setScale(8);

	CCAction * seq = CCSequence::create(
		CCSpawn::create(
		CCMoveTo::create(duration, endPos),
		CCScaleTo::create(duration, 1),
		CCFadeOut::create(duration),
		0),
		CCCallFuncN::create(this, callfuncN_selector(TextFieldTTFActionTest::callbackRemoveNodeWhenDidAction)),
		0);
	label->runAction(seq);
	return false;
}



bool TextFieldTTFActionTest::onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen)
{
	// create a delete text sprite and do some action
	CCLabelTTF * label = CCLabelTTF::create(delText, FONT_NAME, FONT_SIZE);
	this->addChild(label);

	// move the sprite to fly out
	CCPoint beginPos = pSender->getPosition();
	CCSize textfieldSize = pSender->getContentSize();
	CCSize labelSize = label->getContentSize();
	beginPos.x += (textfieldSize.width - labelSize.width) / 2.0f;

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint endPos(- winSize.width / 4.0f, winSize.height * (0.5 + (float)rand() / (2.0f * RAND_MAX)));
	
	float duration = 1;
	float rotateDuration = 0.2f;
	int repeatTime = 5; 
	label->setPosition(beginPos);
	_text.find_last_of(delText);
	_text.erase(_text.find_last_of(delText), nLen);
	CCAction * seq = CCSequence::create(
		CCSpawn::create(
		CCMoveTo::create(duration, endPos),
		CCRepeat::create(
		CCRotateBy::create(rotateDuration, (rand()%2) ? 360 : -360),
		repeatTime),
		CCFadeOut::create(duration),
		0),
		CCCallFuncN::create(this, callfuncN_selector(TextFieldTTFActionTest::callbackRemoveNodeWhenDidAction)),
		0);
	label->runAction(seq);
	return false;
}

bool TextFieldTTFActionTest::onDraw(CCTextFieldTTF * pSender)
{
	//m_pInputText;
	return false;
}

void TextFieldTTFActionTest::callbackRemoveNodeWhenDidAction(CCNode * pNode)
{
	this->removeChild(pNode, true);
}


TextFieldTTFActionTest::TextFieldTTFActionTest()
{
	
	m_pTextField = NULL;;
	m_pTextFieldAction = NULL;
	_editType = TextFieldTTFAction_Normal;
}
TextFieldTTFActionTest::~TextFieldTTFActionTest()
{

}
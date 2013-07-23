#include "StdAfx.h"
#include "passwordTextFieldTTF.h"

#include "CCDirector.h"
#include "CCEGLView.h"
static int _calcCharCount(const char * pszText)
{
	int n = 0;
	char ch = 0;
	while ((ch = *pszText))
	{
		CC_BREAK_IF(! ch);

		if (0x80 != (0xC0 & ch))
		{
			++n;
		}
		++pszText;
	}
	return n;
}

passwordTextFieldTTF::passwordTextFieldTTF(void)
{
	m_pInputText = NULL;

	_drawcode = '*';
}


passwordTextFieldTTF::~passwordTextFieldTTF(void)
{
}

void passwordTextFieldTTF::setString(const char *text)
{
	CC_SAFE_DELETE(m_pInputText);

	if (text)
	{
		m_pInputText = new std::string(text);
	}
	else
	{
		m_pInputText = new std::string;
	}

	// if there is no input text, display placeholder instead
	if (! m_pInputText->length())
	{
		CCLabelTTF::setString(m_pPlaceHolder->c_str());
	}
	else
	{
		std::string input;
		std::string::iterator it = m_pInputText->begin();
		for (; it != m_pInputText->end(); ++ it)
		{
			input.push_back(_drawcode);
		}
		
 
		CCLabelTTF::setString(input.c_str());
	}
	m_nCharCount = _calcCharCount(m_pInputText->c_str());
}

CCTextFieldTTF * passwordTextFieldTTF::textFieldWithPlaceHolder(const char *placeholder, const CCSize& dimensions, CCTextAlignment alignment, const char *fontName, float fontSize)
{        
	CCTextFieldTTF *pRet = new passwordTextFieldTTF();
	if(pRet && pRet->initWithPlaceHolder("", dimensions, alignment, fontName, fontSize))
	{
		pRet->autorelease();
		if (placeholder)
		{
			pRet->setPlaceHolder(placeholder);
		}
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CCTextFieldTTF * passwordTextFieldTTF::textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize)
{
	CCTextFieldTTF *pRet = new passwordTextFieldTTF();
	if(pRet && pRet->initWithString("", fontName, fontSize))
	{
		pRet->autorelease();
		if (placeholder)
		{
			pRet->setPlaceHolder(placeholder);
		}
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
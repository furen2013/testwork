#pragma once
#ifndef PASSWORDTEXTFIELDTTF_H
#define PASSWORDTEXTFIELDTTF_H

#include "text_input_node\cctextfieldttf.h"

USING_NS_CC;
class passwordTextFieldTTF :
	public CCTextFieldTTF
{
public:
	passwordTextFieldTTF(void);
	virtual ~passwordTextFieldTTF(void);

public:
	virtual void setString(const char *text);
	void setDrawCode(char c){_drawcode = c;}
public:
	static CCTextFieldTTF * textFieldWithPlaceHolder(const char *placeholder, const CCSize& dimensions, CCTextAlignment alignment, const char *fontName, float fontSize);
	/** creates a CCLabelTTF from a fontname and font size */
	static CCTextFieldTTF * textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize);

protected:
	char		_drawcode;
};

#endif
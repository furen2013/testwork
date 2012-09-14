#pragma once
#include <string>

//=================================================================
//类名：CBase64
//说明：base64编码，简单加密类型，主要用于对数据进行简单转换
//作者：lbr
//创建日期：2007-11-8
//修改纪录：
//=================================================================
class CBase64
{
private:
	CBase64(void);
	~CBase64(void);
public:
	static std::string Encode(const char* pcData, unsigned long dwDataLen);//base64编码
	static std::string Decode(const char* pcData, unsigned long dwDataLen);//base64解码
private:
	//编码表
	static const unsigned char m_cEncodeTable[];
	//解码表
	static const unsigned char m_cDecodeTable[];
};


#pragma once
#include <string>

//=================================================================
//������CBase64
//˵����base64���룬�򵥼������ͣ���Ҫ���ڶ����ݽ��м�ת��
//���ߣ�lbr
//�������ڣ�2007-11-8
//�޸ļ�¼��
//=================================================================
class CBase64
{
private:
	CBase64(void);
	~CBase64(void);
public:
	static std::string Encode(const char* pcData, unsigned long dwDataLen);//base64����
	static std::string Decode(const char* pcData, unsigned long dwDataLen);//base64����
private:
	//�����
	static const unsigned char m_cEncodeTable[];
	//�����
	static const unsigned char m_cDecodeTable[];
};


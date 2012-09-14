#include "Base64.h"

//编码表
const unsigned char CBase64::m_cEncodeTable[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//解码表
const unsigned char CBase64::m_cDecodeTable[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,62, 0, 0, 0,63,
		52,53,54,55,56,57,58,59,60,61, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,
		15,16,17,18,19,20,21,22,23,24,25, 0, 0, 0, 0, 0,
		0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
		41,42,43,44,45,46,47,48,49,50,51
};

CBase64::CBase64(void)
{
}

CBase64::~CBase64(void)
{
}

//base64编码
std::string CBase64::Encode(const char* pcData, unsigned long dwDataLen)
{
	//返回值
	std::string strEncoded;
	unsigned char cTmp[3]={0};
	int iDiv3Num = dwDataLen/3;
	int iMod3Num = dwDataLen % 3;

	for(int i=0;i<iDiv3Num;i++)
	{
		cTmp[0] = *pcData++;
		cTmp[1] = *pcData++;
		cTmp[2] = *pcData++;

		strEncoded+= m_cEncodeTable[cTmp[0] >> 2];
		strEncoded+= m_cEncodeTable[((cTmp[0] << 4) | (cTmp[1] >> 4)) & 0x3F];
		strEncoded+= m_cEncodeTable[((cTmp[1] << 2) | (cTmp[2] >> 6)) & 0x3F];
		strEncoded+= m_cEncodeTable[cTmp[2] & 0x3F];
	}

	//对剩余数据进行编码
	if(iMod3Num==1)
	{
		cTmp[0] = *pcData++;
		strEncoded+= m_cEncodeTable[(cTmp[0] & 0xFC) >> 2];
		strEncoded+= m_cEncodeTable[((cTmp[0] & 0x03) << 4)];
		strEncoded+= "==";
	}
	else if(iMod3Num==2)
	{
		cTmp[0] = *pcData++;
		cTmp[1] = *pcData++;
		strEncoded+= m_cEncodeTable[(cTmp[0] & 0xFC) >> 2];
		strEncoded+= m_cEncodeTable[((cTmp[0] & 0x03) << 4) | ((cTmp[1] & 0xF0) >> 4)];
		strEncoded+= m_cEncodeTable[((cTmp[1] & 0x0F) << 2)];
		strEncoded+= "=";
	}

	return strEncoded;

}

//base64解码
std::string CBase64::Decode(const char* pcData, unsigned long dwDataLen)
{
	//返回值
	std::string strDecoded;

	int nValue;
	int i= 0;

	while (i < (int)dwDataLen)
	{
		nValue = m_cDecodeTable[*pcData++] << 18;
		nValue += m_cDecodeTable[*pcData++] << 12;
		strDecoded+=(nValue & 0x00FF0000) >> 16;

		if (*pcData != '=')
		{
			nValue += m_cDecodeTable[*pcData++] << 6;
			strDecoded+=(nValue & 0x0000FF00) >> 8;

			if (*pcData != '=')
			{
				nValue += m_cDecodeTable[*pcData++];
				strDecoded+=nValue & 0x000000FF;
			}
		}
		i += 4;
	}
	return strDecoded;
}

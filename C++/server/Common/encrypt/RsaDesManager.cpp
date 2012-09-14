#include "RsaDesManager.h"
bool CRsaDesManager::m_bInitRSA = false;//初始化标志，标示是否初始化了rsa公钥和私钥。
RSA * CRsaDesManager::m_pPriRSA[RSA_KEY_PAIR_NUM] = {NULL};//rsa私钥数组
RSA * CRsaDesManager::m_pPubRSA[RSA_KEY_PAIR_NUM] = {NULL};//rsa公钥数组
string CRsaDesManager::m_strPubKeys[RSA_KEY_PAIR_NUM] = {""};

CRsaDesManager::CRsaDesManager(void)
{
}

CRsaDesManager::~CRsaDesManager(void)
{
}

//初始化
bool CRsaDesManager::Init()
{
	m_bInitRSA = false;
	if(!LoadRsaKeypairs())
	{
		if(!GenRsaKeypairs())
			return false;
	}

	m_bInitRSA = true;
	return true;
}

void CRsaDesManager::Destroy()
{
	for(int i = 0; i < RSA_KEY_PAIR_NUM; ++i)
	{
		if(m_pPriRSA[i])
		{
			RSA_free(m_pPriRSA[i]);
			m_pPriRSA[i] = NULL;
		}
		if(m_pPubRSA[i])
		{
			RSA_free(m_pPubRSA[i]);
			m_pPubRSA[i] = NULL;
		}
	}
}
//rsa密钥对产生
bool CRsaDesManager::GenRsaKeypairs(void)
{
	RSA *rsa = NULL;
	FILE *fKeyFile = NULL;
	fKeyFile = fopen("raskeys.key", "wb");
	if(fKeyFile == NULL)
	{
		return false;
	}

	int i = 0;
	//把密钥对写入文件，以后从文件里读取
	unsigned char ucPubKey[RSA_KEY_LEN] = {0}, ucPriKey[RSA_KEY_LEN] = {0};
	for(i = 0; i < RSA_KEY_PAIR_NUM; ++i)
	{
		//生成RSA密钥对：
		rsa = RSA_new();
		rsa = RSA_generate_key(RSA_KEY_LEN, RSA_F4, NULL, NULL);

		unsigned char* pt = ucPubKey;
		ui32 len = i2d_RSAPublicKey(rsa, &pt);
		if(!GetPubKey(ucPubKey, len, &m_pPubRSA[i]))
			break;
		fwrite((unsigned char*)&len, 1, sizeof(ui32), fKeyFile);
		fwrite(ucPubKey, 1, len, fKeyFile);
		m_strPubKeys[i].clear();
		m_strPubKeys[i].append((char*)ucPubKey, len);

		unsigned char* pt2 = ucPriKey;
		len = i2d_RSAPrivateKey(rsa,&pt2);
		if(!GetPriKey(ucPriKey, len, &m_pPriRSA[i]))
			break;
		fwrite((unsigned char*)&len, 1, sizeof(ui32), fKeyFile);
		fwrite(ucPriKey, 1, len, fKeyFile);

		if(rsa != NULL)
		{
			RSA_free(rsa);
			rsa = NULL;
		}
	}
	fclose(fKeyFile);
	if(i < RSA_KEY_PAIR_NUM)
		return false;
	return true;
}

//rsa密钥对载入
bool CRsaDesManager::LoadRsaKeypairs(void)
{
	FILE *fKeyFile = NULL;
	fKeyFile = fopen("raskeys.key", "rb");
	if(fKeyFile == NULL)
	{
		return false;
	}
	fseek(fKeyFile, 0, SEEK_SET);
	char szLen[sizeof(ui32)];
	char szKey[RSA_KEY_LEN];
	int iLen = 0;
	size_t iReadLen = 0;
	int i = 0;
	for(i = 0; i < RSA_KEY_PAIR_NUM ; ++i)
	{
		iReadLen = fread(szLen, 1, sizeof(ui32), fKeyFile);
		if(iReadLen != sizeof(ui32))
			break;
		iLen  = *(ui32*)szLen;
		iReadLen = fread(szKey, 1, iLen, fKeyFile);
		if(iReadLen != iLen)
			break;
		if(!GetPubKey((unsigned char*)szKey, iLen, &m_pPubRSA[i]))
			break;

		m_strPubKeys[i].clear();
		m_strPubKeys[i].append(szKey, iLen);

		iReadLen = fread(szLen, 1, sizeof(ui32), fKeyFile);
		if(iReadLen != sizeof(ui32))
			break;
		iLen = *(ui32*)szLen;
		iReadLen = fread(szKey, 1, iLen, fKeyFile);
		if(iReadLen != iLen)
			break;
		if(!GetPriKey((unsigned char*)szKey, iLen, &m_pPriRSA[i]))
			break;
	}
	fclose(fKeyFile);
	if(i < RSA_KEY_PAIR_NUM)
		return false;
	return true;
}

//公钥加密会话密钥：
bool CRsaDesManager::RSAPubEncode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen)
{
	if(!CheckRSAKeyIdx(wKeyIdx))
		return false;

	*ulOutLen = 0;
	unsigned long ulInTmpLen = std::min<int>(ulInLen, RSA_ENCODE_LEN_UNIT);
	unsigned long ulOutTmpLen = 0;
	while(ulInLen)
	{
		ulOutTmpLen = RSA_public_encrypt(ulInTmpLen, pcInData, pcOutData+(*ulOutLen), m_pPubRSA[wKeyIdx], 1);
		if(ulOutTmpLen <= 0)
			break;

		*ulOutLen = (*ulOutLen) + ulOutTmpLen;
		pcInData = pcInData+ulInTmpLen;
		ulInLen -= ulInTmpLen;
		ulInTmpLen = std::min<int>(ulInLen, RSA_ENCODE_LEN_UNIT);
	}

	if(ulInLen <= 0)
		return true;
	else
		return false;
}

 bool CRsaDesManager::RSAPubEncode(const string& strRsaPubKey, const string& strInData, string& strOutData)
 {
	 RSA * pRsa;
	 if(!GetPubKey((unsigned char*)strRsaPubKey.c_str(), strRsaPubKey.size(), &pRsa))
		 return false;

	 unsigned char pcOutData[1024];
	 unsigned char *pcInData = (unsigned char *)strInData.c_str();
	 unsigned long ulOutLen = 0, ulInLen = strInData.size();
	 unsigned long ulInTmpLen = std::min<int>(ulInLen, RSA_ENCODE_LEN_UNIT);
	 unsigned long ulOutTmpLen = 0;
	 while(ulInLen)
	 {
		 ulOutTmpLen = RSA_public_encrypt(ulInTmpLen, pcInData, pcOutData+ulOutLen, pRsa, 1);
		 if(ulOutTmpLen <= 0)
			 break;

		 ulOutLen = ulOutLen + ulOutTmpLen;
		 pcInData = pcInData+ulInTmpLen;
		 ulInLen -= ulInTmpLen;
		 ulInTmpLen = std::min<int>(ulInLen, RSA_ENCODE_LEN_UNIT);
	 }

	 RSA_free(pRsa);

	 strOutData.clear();
	 if(ulInLen <= 0)
	 {
		 strOutData.append((char*)pcOutData, ulOutTmpLen);
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }

 string CRsaDesManager::RSAPubEncode(const string& strRsaPubKey, const string& strInData)
 {
	 string strEncoded;
	 RSAPubEncode(strRsaPubKey, strInData, strEncoded);
	 return strEncoded;
 }

//私钥解密会话密钥：
bool CRsaDesManager::RSAPriDecode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen)
{
	if(!CheckRSAKeyIdx(wKeyIdx))
		return false;

	*ulOutLen = 0;
	unsigned long ulInTmpLen = std::min<int>(ulInLen, RSA_DECODE_LEN_UNIT);
	unsigned long ulOutTmpLen = 0;
	while(ulInLen)
	{
		ulOutTmpLen = RSA_private_decrypt(ulInTmpLen, pcInData, pcOutData+(*ulOutLen), m_pPriRSA[wKeyIdx], 1);
		if(ulOutTmpLen <= 0 || ulOutTmpLen > RSA_ENCODE_LEN_UNIT)
			break;

		*ulOutLen = (*ulOutLen) + ulOutTmpLen;
		pcInData = pcInData+ulInTmpLen;
		ulInLen -= ulInTmpLen;
		ulInTmpLen = std::min<int>(ulInLen, RSA_DECODE_LEN_UNIT);
	}

	if(ulInLen <= 0)
		return true;
	else
		return false;
}

string CRsaDesManager::RSAPriDecode(ui16 wKeyIdx, const string& strEncoded)
{
	string strRet = "";
	unsigned char szDecodeBuf[4096];
	unsigned long ulDecodeLen = 0;
	if(RSAPriDecode(wKeyIdx, (unsigned char*)strEncoded.c_str(), strEncoded.size(), szDecodeBuf, &ulDecodeLen) && ulDecodeLen > 0)
	{
		strRet.append((char*)szDecodeBuf, ulDecodeLen);
	}
	return strRet;
}

//des加密函数
string CRsaDesManager::DESEncode(const string& strDesKey, const string& strInData)
{
	DES_cblock key;
	DES_key_schedule key_schedule;
	DES_string_to_key(strDesKey.c_str(), &key);
	if (DES_set_key_checked(&key, &key_schedule) != 0)
		return "";

	size_t len = (strInData.size()+7)/8 * 8;

	unsigned char pcOutData[4096];
	if(DESEncode(key_schedule, (unsigned char *)strInData.c_str(), len, pcOutData))
	{
		string strEncoded;
		strEncoded.append((char*)pcOutData, len);
		return strEncoded;
	}
	else
	{
		return "";
	}
}

//des加密函数
bool CRsaDesManager::DESEncode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData)
{
	DES_cblock key;
	DES_key_schedule key_schedule;
	DES_string_to_key(strDesKey.c_str(), &key);
	if (DES_set_key_checked(&key, &key_schedule) != 0)
		return false;

	size_t len = (ulInLen+7)/8 * 8;

	return DESEncode(key_schedule, pcInData, len, pcOutData);
}

//des加密函数
bool CRsaDesManager::DESEncode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData)
{
	DES_cblock ivec;

	// 加密
	memset((char*)&ivec, 0, sizeof(ivec));
	DES_ncbc_encrypt(pcInData, pcOutData, ulInLen, &key_schedule, &ivec, 1);
	return true;
}

//des解密函数
bool CRsaDesManager::DESDecode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData)
{
	DES_cblock key;
	DES_key_schedule key_schedule;
	DES_string_to_key(strDesKey.c_str(), &key);
	if (DES_set_key_checked(&key, &key_schedule) != 0)
		return false;

	size_t len = (ulInLen+7)/8 * 8;

	return DESDecode(key_schedule, pcInData, ulInLen, pcOutData);
}

//des解密函数
bool CRsaDesManager::DESDecode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData)
{
	DES_cblock ivec;

	// 加密
	memset((char*)&ivec, 0, sizeof(ivec));//ivec清0
	DES_ncbc_encrypt(pcInData, pcOutData, ulInLen, &key_schedule, &ivec, 0);
	return true;
}

string CRsaDesManager::DESDecode(const string& strDesKey, const string& strEncoded)
{
	string strRet = "";
	unsigned char szDecodeBuf[4096] = { 0 };
	if(DESDecode(strDesKey, (unsigned char*)strEncoded.c_str(), strEncoded.size(), szDecodeBuf))
	{
		//strRet.append((char*)szDecodeBuf, strEncoded.size());
		strRet = (char*)szDecodeBuf;
	}
	return strRet;
}


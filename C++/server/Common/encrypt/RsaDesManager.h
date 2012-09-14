#pragma once
#include "../../../SDBase/Public/TypeDef.h"
#include "../openssl-0.9.8b/inc32/openssl/rsa.h"
#include "../openssl-0.9.8b/inc32/openssl/des.h"
#include <string>

using namespace std;

#define RSA_KEY_PAIR_NUM 100
#define RSA_KEY_LEN 512
#define RSA_ENCODE_LEN_UNIT 53
#define RSA_DECODE_LEN_UNIT 64

//=================================================================
//类名：CRsaDesManager
//说明：针对openssl中rsa、des加密解密的封装，对外提供rsa、des加密解密接口
//作者：lbr
//创建日期：2007-11-7
//修改纪录：
//=================================================================
class CRsaDesManager
{
	//私有化构造函数，该类的调用都是静态函数的方式
	CRsaDesManager(void);
	~CRsaDesManager(void);
public:
	//对外接口函数
	//初始化
	static bool Init();
	static void Destroy();
	static inline bool IsInited()
	{
		return m_bInitRSA;
	};
	//rsa密钥对产生
	static bool GenRsaKeypairs(void);
	//rsa密钥对载入
	static bool LoadRsaKeypairs(void);

	//公钥加密会话密钥：
	static bool RSAPubEncode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen);
	static bool RSAPubEncode(const string& strRsaPubKey, const string& strInData, string& strOutData);
	static string RSAPubEncode(const string& strRsaPubKey, const string& strInData);

	//私钥解密会话密钥：
	static bool RSAPriDecode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen);
	static string RSAPriDecode(ui16 wKeyIdx, const string& strEncoded);

	//des加密函数
	static bool DESEncode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static bool DESEncode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static string DESEncode(const string& strDesKey, const string& strInData);

	//des解密函数
	static bool DESDecode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static bool DESDecode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static string DESDecode(const string& strDesKey, const string& strEncoded);

	//获取随机rsa索引
	static inline ui16 GetRandRsaPubKey(string& strPubKey)
	{
		ui16 wIdx = rand()%RSA_KEY_PAIR_NUM;
		strPubKey = m_strPubKeys[wIdx];
		return wIdx;
	};
private:
	//内部函数
	//判断rsa密钥索引的有效性
	static inline bool CheckRSAKeyIdx(ui16 wIdx)
	{
		return (wIdx < RSA_KEY_PAIR_NUM); 
	};

	//取得RSA格式的私钥：
	static inline bool GetPriKey(unsigned char *pucPriKeyData, unsigned long KeyDataLen, RSA* *priRsa)
	{
		unsigned char *Pt = pucPriKeyData;
		*priRsa = d2i_RSAPrivateKey(NULL, (const unsigned char**)&Pt, KeyDataLen);
		return (priRsa != NULL);
	}

	//取得RSA格式的公钥：
	static inline bool GetPubKey(unsigned char *pucPubKeyData,unsigned long KeyDataLen, RSA* *pubRsa)
	{
		unsigned char *Pt = pucPubKeyData;
		*pubRsa = d2i_RSAPublicKey(NULL, (const unsigned char**)&Pt, KeyDataLen);
		return (pubRsa != NULL);
	}

	//成员变量
	static bool m_bInitRSA;//初始化标志，标示是否初始化了rsa公钥和私钥。
	static RSA * m_pPriRSA[RSA_KEY_PAIR_NUM];//rsa私钥数组
	static RSA * m_pPubRSA[RSA_KEY_PAIR_NUM];//rsa公钥数组
	static string m_strPubKeys[RSA_KEY_PAIR_NUM];
};


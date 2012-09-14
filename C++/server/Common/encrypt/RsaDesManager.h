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
//������CRsaDesManager
//˵�������openssl��rsa��des���ܽ��ܵķ�װ�������ṩrsa��des���ܽ��ܽӿ�
//���ߣ�lbr
//�������ڣ�2007-11-7
//�޸ļ�¼��
//=================================================================
class CRsaDesManager
{
	//˽�л����캯��������ĵ��ö��Ǿ�̬�����ķ�ʽ
	CRsaDesManager(void);
	~CRsaDesManager(void);
public:
	//����ӿں���
	//��ʼ��
	static bool Init();
	static void Destroy();
	static inline bool IsInited()
	{
		return m_bInitRSA;
	};
	//rsa��Կ�Բ���
	static bool GenRsaKeypairs(void);
	//rsa��Կ������
	static bool LoadRsaKeypairs(void);

	//��Կ���ܻỰ��Կ��
	static bool RSAPubEncode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen);
	static bool RSAPubEncode(const string& strRsaPubKey, const string& strInData, string& strOutData);
	static string RSAPubEncode(const string& strRsaPubKey, const string& strInData);

	//˽Կ���ܻỰ��Կ��
	static bool RSAPriDecode(ui16 wKeyIdx, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData, unsigned long *ulOutLen);
	static string RSAPriDecode(ui16 wKeyIdx, const string& strEncoded);

	//des���ܺ���
	static bool DESEncode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static bool DESEncode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static string DESEncode(const string& strDesKey, const string& strInData);

	//des���ܺ���
	static bool DESDecode(const string& strDesKey, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static bool DESDecode(DES_key_schedule& key_schedule, unsigned char *pcInData, unsigned long ulInLen, unsigned char *pcOutData);
	static string DESDecode(const string& strDesKey, const string& strEncoded);

	//��ȡ���rsa����
	static inline ui16 GetRandRsaPubKey(string& strPubKey)
	{
		ui16 wIdx = rand()%RSA_KEY_PAIR_NUM;
		strPubKey = m_strPubKeys[wIdx];
		return wIdx;
	};
private:
	//�ڲ�����
	//�ж�rsa��Կ��������Ч��
	static inline bool CheckRSAKeyIdx(ui16 wIdx)
	{
		return (wIdx < RSA_KEY_PAIR_NUM); 
	};

	//ȡ��RSA��ʽ��˽Կ��
	static inline bool GetPriKey(unsigned char *pucPriKeyData, unsigned long KeyDataLen, RSA* *priRsa)
	{
		unsigned char *Pt = pucPriKeyData;
		*priRsa = d2i_RSAPrivateKey(NULL, (const unsigned char**)&Pt, KeyDataLen);
		return (priRsa != NULL);
	}

	//ȡ��RSA��ʽ�Ĺ�Կ��
	static inline bool GetPubKey(unsigned char *pucPubKeyData,unsigned long KeyDataLen, RSA* *pubRsa)
	{
		unsigned char *Pt = pucPubKeyData;
		*pubRsa = d2i_RSAPublicKey(NULL, (const unsigned char**)&Pt, KeyDataLen);
		return (pubRsa != NULL);
	}

	//��Ա����
	static bool m_bInitRSA;//��ʼ����־����ʾ�Ƿ��ʼ����rsa��Կ��˽Կ��
	static RSA * m_pPriRSA[RSA_KEY_PAIR_NUM];//rsa˽Կ����
	static RSA * m_pPubRSA[RSA_KEY_PAIR_NUM];//rsa��Կ����
	static string m_strPubKeys[RSA_KEY_PAIR_NUM];
};


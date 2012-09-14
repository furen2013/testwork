#pragma once

#include "../Public/TypeDef.h"


//消息号分类
namespace SDBase
{
	enum
	{
		PROTOCOL_VERSION_MAJOR = 0,		//	协议主版本号
		PROTOCOL_VERSION_MINOR = 0,		//	协议次版本号

		MSG_BASE_C2LS = 100,
		MSG_BASE_LS2C = 200,

		MSG_BASE_C2GT = 300,
		MSG_BASE_GT2C = 400,

		MSG_BASE_LS2CS = 500,
		MSG_BASE_CS2LS = 600,

		MSG_BASE_CS2GT = 700,
		MSG_BASE_GT2CS = 800,

		MSG_BASE_DB2GT = 900,
		MSG_BASE_GT2DB = 1000,

		MSG_BASE_DB2GS = 1100,
		MSG_BASE_GS2DB = 1200,

		MSG_BASE_GS2GT = 1300,
		MSG_BASE_GT2GS = 1400,

		MSG_BASE_GS2MS = 1500,
		MSG_BASE_MS2GS = 1600,

		MSG_BASE_C2GS = 10000,
		MSG_BASE_GS2C = 20000
	};
};

const unsigned int MAX_BUF_SIZE = 65000 * 10;

#include "../../new_common/Source/utilities/mt_buffer.h"

class packet_exception
{
public:
	packet_exception( const char* p ) : m_what( p ){}
	virtual ~packet_exception(){}

	virtual const char* what() const {
		return m_what.c_str();
	}

private:
	std::string m_what;
};

#ifdef _MESSAGE_LARGE_THREAD
typedef mt_buffer_mgr<20, MAX_BUF_SIZE> packet_buffer_mgr;
#else
typedef mt_buffer_mgr<2, MAX_BUF_SIZE> packet_buffer_mgr;
#endif

typedef packet_buffer_mgr::buffer_type packet_buffer;

static packet_buffer_mgr s_pbm;

class CPacketSn
{
	friend struct tagItemData;//TODO: temp code
public:
	CPacketSn():m_pos(0), m_pb( s_pbm.get_free_buffer() ), m_buff( NULL )
	{
		//m_buff = (char*)malloc( MAX_BUF_SIZE );
		while( !m_pb.get() )
			m_pb = s_pbm.get_free_buffer();

		m_buff = m_pb->get_buff();
		assert( m_buff );
	}
	~CPacketSn()
	{
		//free( m_buff );
	}
private:
	mt_auto_ptr<packet_buffer*> m_pb;
	char* m_buff;
	size_t m_pos;//当前位置

public:
	void AddBuf(const void* nItem, size_t uiSize)
	{
		if(m_pos + uiSize > MAX_BUF_SIZE)
		{
			throw packet_exception( "CPacketSn::AddBuf:packet too big" );
			return;
		}

		memcpy(m_buff+m_pos, nItem, uiSize);
		m_pos += uiSize;
	}
	char* GetBuf() {return m_buff;}
	size_t GetSize() {return m_pos;}
	void SetProLen() {*(ui16*)m_buff = (ui16)m_pos;}

	CPacketSn& operator << (const bool prop) {AddBuf(&prop, sizeof(bool)); return *this;}
	CPacketSn& operator << (const char prop) {AddBuf(&prop, sizeof(char)); return *this;}
	CPacketSn& operator << (const unsigned char prop) {AddBuf(&prop, sizeof(unsigned char)); return *this;}
	CPacketSn& operator << (const short prop) {AddBuf(&prop, sizeof(short)); return *this;}
	CPacketSn& operator << (const unsigned short prop) {AddBuf(&prop, sizeof(unsigned short)); return *this;}
	CPacketSn& operator << (const int prop) {AddBuf(&prop, sizeof(int)); return *this;}
	CPacketSn& operator << (const unsigned int prop) {AddBuf(&prop, sizeof(unsigned int)); return *this;}
	CPacketSn& operator << (const long prop) {AddBuf(&prop, sizeof(long)); return *this;}
	CPacketSn& operator << (const unsigned long prop) {AddBuf(&prop, sizeof(unsigned long)); return *this;}
	CPacketSn& operator << (const int64 prop) {AddBuf(&prop, sizeof(int64)); return *this;}
	CPacketSn& operator << (const uint64 prop) {AddBuf(&prop, sizeof(uint64)); return *this;}
	CPacketSn& operator << (const float prop) {AddBuf(&prop, sizeof(float)); return *this;}

	template <typename T>
	CPacketSn& operator << (const T& prop) {prop.Sn(*this); return *this;}

	CPacketSn& operator << (const std::string& prop)
	{
		size_t slen = prop.length();
		if(m_pos + sizeof(size_t) + slen > MAX_BUF_SIZE)
		{
			throw packet_exception( "CPacketSn::<< :packet too big" );
			return *this;
		}

		*this << (unsigned int)slen;
		memcpy(m_buff+m_pos, prop.c_str(), slen);
		m_pos += slen;
		return *this;
	}

	template<typename T>
	CPacketSn& operator << (const std::list<T>& prop)
	{
		size_t slen = prop.size();

		*this << (unsigned int)slen;
		for(typename std::list<T>::const_iterator it=prop.begin();it!=prop.end();++it)
		{
			*this << *it;
		}
		return *this;
	}

	template<typename T>
	 CPacketSn& operator << (const std::deque<T>& prop)
	{
		size_t slen = prop.size();

		*this << (unsigned int)slen;
		for(typename std::deque<T>::const_iterator it=prop.begin();it!=prop.end();++it)
		{
			*this << *it;
		}
		return *this;
	}

	template<typename T>
	CPacketSn& operator << (const std::vector<T>& prop)
	{
		size_t slen = prop.size();

		*this << (unsigned int)slen;
		for(typename std::vector<T>::const_iterator it=prop.begin();it!=prop.end();++it)
		{
			*this << *it;
		}
		return *this;
	}

	template<typename T>
	CPacketSn& operator << (const std::set<T>& prop)
	{
		size_t slen = prop.size();

		*this << (unsigned int)slen;
		for(typename std::set<T>::const_iterator it=prop.begin();it!=prop.end();++it)
		{
			*this << *it;
		}
		return *this;
	}

	template<typename T1, typename T2>
	CPacketSn& operator << (const std::map<T1,T2>& prop)
	{
		size_t slen = prop.size();

		*this << (unsigned int)slen;
		for(typename std::map<T1,T2>::const_iterator it=prop.begin();it!=prop.end();++it)
		{
			*this << it->first << it->second;
		}
		return *this;
	}
};


/*--------------------------------------------------------------------------------*/





class CPacketUsn
{
	friend struct tagItemData;
public:
	CPacketUsn(char* buff, size_t nSize):m_buff(buff),m_pos(0),m_size(nSize) {}
	~CPacketUsn() {}

	char* m_buff;
	size_t m_pos;//当前处理位置
	size_t m_size;//包的大小

public:
	void GetBuf(void* nItem, size_t uiSize)
	{
		if(m_pos + uiSize > m_size)
		{
			throw packet_exception( "CPacketUsn::GetBuf:packet too small" );
			return;
		}

		memcpy(nItem, m_buff+m_pos, uiSize);
		m_pos += uiSize;
	}
	ui16 GetProNo()		{ return *(ui16*)(m_buff+sizeof(ui16));	  }
	void SetProNo(ui16 proto)		{ *(ui16*)(m_buff+sizeof(ui16)) = proto; }
	ui32 GetTransID()	{ return *(ui32*)(m_buff+2*sizeof(ui16)); }
	void SetTransID(ui32 nID)	{ *(ui32*)(m_buff+2*sizeof(ui16)) = nID; }
	ui64 GetPlayerGUID(){ return *(ui64*)(m_buff+5*sizeof(ui16)); }
	void SetPlayerGUID(ui64 guid){ *(ui64*)(m_buff+5*sizeof(ui16)) = guid; }
	ui32 GetSubproto()	{ return *(ui32*)(m_buff+4*sizeof(ui16)); }
	void SetSubproto(ui32 nID)	{ *(ui32*)(m_buff+4*sizeof(ui16)) = nID; }
	CPacketUsn& operator >> (bool& prop) {GetBuf(&prop, sizeof(bool)); return *this;}
	CPacketUsn& operator >> (char& prop) {GetBuf(&prop, sizeof(char)); return *this;}
	CPacketUsn& operator >> (unsigned char& prop) {GetBuf(&prop, sizeof(unsigned char)); return *this;}
	CPacketUsn& operator >> (short& prop) {GetBuf(&prop, sizeof(short)); return *this;}
	CPacketUsn& operator >> (unsigned short& prop) {GetBuf(&prop, sizeof(unsigned short)); return *this;}
	CPacketUsn& operator >> (int& prop) {GetBuf(&prop, sizeof(int)); return *this;}
	CPacketUsn& operator >> (unsigned int& prop) {GetBuf(&prop, sizeof(unsigned int)); return *this;}
	CPacketUsn& operator >> (long& prop) {GetBuf(&prop, sizeof(long)); return *this;}
	CPacketUsn& operator >> (unsigned long& prop) {GetBuf(&prop, sizeof(unsigned long)); return *this;}
	CPacketUsn& operator >> (int64& prop) {GetBuf(&prop, sizeof(int64)); return *this;}
	CPacketUsn& operator >> (uint64& prop) {GetBuf(&prop, sizeof(uint64)); return *this;}
	CPacketUsn& operator >> (float& prop) {GetBuf(&prop, sizeof(float)); return *this;}

	template <typename T>
	CPacketUsn& operator >> (T& prop) {prop.Usn(*this); return *this;}

	CPacketUsn& operator >> (std::string& prop)
	{
		size_t slen = 0;
		*this >> slen;
		if(m_pos + slen > m_size)
		{
			throw packet_exception( "CPacketUsn >> string: packet too small" );
			return *this;
		}

		prop.clear();
		prop.append(m_buff+m_pos, slen);
		m_pos += slen;
		return *this;
	}

	template<typename T>
	CPacketUsn& operator >> (std::list<T>& prop)
	{
		size_t slen = 0;
		*this >> slen;

		prop.clear();
		T temp;
		for(size_t i=0;i<slen;++i)
		{
			*this >> temp;
			prop.push_back(temp);
		}
		return *this;
	}

	template<typename T>
	CPacketUsn& operator >> (std::deque<T>& prop)
	{
		size_t slen= 0;
		*this >> slen;

		prop.clear();
		T temp;
		for(size_t i=0;i<slen;++i)
		{
			*this >> temp;
			prop.push_back(temp);
		}
		return *this;
	}

	template<typename T>
	CPacketUsn& operator >> (std::vector<T>& prop)
	{
		size_t slen = 0;
		*this >> slen;

		prop.clear();
		T temp;
		for(size_t i=0;i<slen;++i)
		{
			*this >> temp;
			prop.push_back(temp);
		}
		return *this;
	}

	template<typename T>
	CPacketUsn& operator >> (std::set<T>& prop)
	{
		size_t slen = 0;
		*this >> slen;

		prop.clear();
		T temp;
		for(size_t i=0;i<slen;++i)
		{
			*this >> temp;
			prop.insert(temp);
		}
		return *this;
	}

	template<typename T1, typename T2>
	CPacketUsn& operator >> (std::map<T1,T2>& prop)
	{
		size_t slen = 0;
		*this >> slen;

		prop.clear();
		T1 temp1;
		T2 temp2;
		for(size_t i=0;i<slen;++i)
		{
			*this >> temp1 >> temp2;
			//prop.insert(std::map<T1,T2>::value_type(temp1, temp2));
			prop[temp1] = temp2;
		}
		return *this;
	}
};

typedef struct _tagPakHead
{
	ui16	wLen;
	ui16	wProNO;
	ui32	nTransID;			//	used for server
	ui32	checksum;
	virtual CPacketSn& Sn(CPacketSn& cps) const {cps << wLen << wProNO << nTransID << checksum; return cps;}
	virtual CPacketUsn& Usn(CPacketUsn& cpu)    {cpu >> wLen >> wProNO >> nTransID >> checksum; return cpu;}
	ui16	GetLen() { return sizeof(_tagPakHead); }
	_tagPakHead() : wLen( 0 ), wProNO( 0 ), nTransID( 0 ), checksum( 0 ) {}

}PakHead,*PPakHead;

struct _tagPakProxyHead : public PakHead
{
	ui16	subproto;
	ui64	playerguid;
	virtual CPacketSn& Sn(CPacketSn& cps) const	{ PakHead::Sn(cps); cps << subproto << playerguid; return cps;}
	virtual CPacketUsn& Usn(CPacketUsn& cpu)	{ PakHead::Usn(cpu); cpu >> subproto >> playerguid; return cpu;}
	ui16	GetLen() { return sizeof(_tagPakProxyHead); }
};

typedef struct _tagPakProxyHead PakProxyHead;

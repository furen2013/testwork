
#ifndef STREAM_H
#define STREAM_H

class CStream
{
public:
	enum SeekType
	{
		SeekBegin = 0,
		SeekCurrent = 1,
		SeekEnd = 2,
	};

	CStream()
		:m_uiSize(0)
		,m_uiPos(0)
	{
	}

	virtual ~CStream()
	{
	}

	virtual bool Read(void* pBuf, unsigned int uiSize) = 0;
	virtual bool Write(const void* pBuf, unsigned int uiSize) = 0;
	virtual bool Seek(int offset, int origin = SeekCurrent) = 0;

	unsigned int GetSize() const
	{
		return m_uiSize;
	}

	unsigned int GetPosition() const
	{
		return m_uiPos;
	}

	//template<typename T>
	//bool Read(T& value)
	//{
	//	return Read(&value, sizeof(T));
	//}
	//
	//template<typename T>
	//bool Write(const T& value)
	//{
	//	return Write(&value, sizeof(T));
	//}

	int ReadInt()
	{
		int value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteInt( int value )
	{
		return Write(&value, sizeof(value));
	}

	unsigned int ReadUInt()
	{
		unsigned int value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteInt( unsigned int value )
	{
		return Write(&value, sizeof(value));
	}

	short ReadShort()
	{
		short value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteShort( short value )
	{
		return Write(&value, sizeof(value));
	}

	unsigned short ReadUShort()
	{
		unsigned short value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteUShort( unsigned short value )
	{
		return Write(&value, sizeof(value));
	}

	char ReadChar()
	{
		char value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteChar( char value )
	{
		return Write(&value, sizeof(value));
	}

	unsigned char ReadUChar()
	{
		unsigned char value = 0;
		Read(&value, sizeof(value));

		return value;
	}

	bool WriteUChar( unsigned char value )
	{
		return Write(&value, sizeof(value));
	}

protected:
	unsigned int m_uiSize;
	unsigned int m_uiPos;
};

#endif //STREAM_H
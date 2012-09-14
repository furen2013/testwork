
#include "Stream.h"

class CFileStream : public CStream
{
public:
	enum AccessMode
	{
		InvalidMode,
		ReadMode,
		WriteMode,
	};

	enum
	{
		BUFFER_SIZE = 32*1024,
	};

	CFileStream()
		:m_pFile(0)
	{
		m_Buffer = new char[BUFFER_SIZE];
	}

	virtual ~CFileStream();

	virtual bool Read(void* pBuf, unsigned int uiSize);
	virtual bool Write(const void* pBuf, unsigned int uiSize);
	virtual bool Seek(int offset, int origin = SeekCurrent);

	bool Open(const char* pcFilename, AccessMode eMode = ReadMode);
	void Close();

private:
	void* m_pFile;
	AccessMode m_eAccessMode;


	char* m_Buffer;
	unsigned int m_uiBufferTail;

	//m_uiPos <= m_uiBuffTail
};
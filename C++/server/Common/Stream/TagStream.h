
#include "Stream.h"

class CTagStream : public CStream
{
public:
	enum
	{
		BUFFER_SIZE = 32*1024,
	};

	CTagStream();

	virtual ~CTagStream();

	virtual bool Read(void* pBuf, unsigned int uiSize);
	virtual bool Write(const void* pBuf, unsigned int uiSize) { return false; }
	virtual bool Seek(int offset, int origin = SeekCurrent);

	bool ReadFromStream(CStream& stream);
	inline unsigned int GetTag() const { return m_uiTag; }

	void Close();

private:
	char* m_pBuffer;

	unsigned int m_uiTag;
};
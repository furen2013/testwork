#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include "FileStream.h"

CFileStream::~CFileStream()
{
	Close();
	delete m_Buffer;
}

bool CFileStream::Open(const char* pcFilename, AccessMode eMode)
{
	Close();

	char* pcMode;
	if( eMode == ReadMode )
	{
		pcMode = "r";
	}
	else if( eMode == WriteMode )
	{
		pcMode = "w";
	}
	else
	{
		assert(false);
	}

	m_pFile = fopen(pcFilename, pcMode);
	if( m_pFile == NULL )
		return false;

	m_eAccessMode = eMode;

	Seek(0, SeekEnd);
	m_uiSize = ftell((FILE*)m_pFile);
	Seek(0, SeekBegin);

	return true;
}

void CFileStream::Close()
{
	if( m_pFile )
		fclose((FILE*)m_pFile);

	
	m_eAccessMode = InvalidMode;

	m_uiPos = 0;
	m_uiBufferTail = 0;
	m_uiSize = 0;
}

#define ALIGN(pos) ((pos)&~(BUFFER_SIZE - 1))

bool CFileStream::Read(void* pBuf, unsigned int uiSize)
{
	assert( m_pFile );
	assert( m_eAccessMode == ReadMode );

	unsigned int uiRemain = uiSize;
	char* pcBufPtr = (char*)pBuf;

	if( m_uiPos < m_uiBufferTail )
	{
		unsigned int uiReadSize = m_uiBufferTail - m_uiPos;

		if( uiReadSize > uiRemain )
			uiReadSize = uiRemain;

		memcpy(pcBufPtr, m_Buffer + (m_uiPos - ALIGN(m_uiPos)), uiReadSize);
		m_uiPos += uiReadSize;
		pcBufPtr += uiReadSize;
		uiRemain -= uiReadSize;

		if( uiRemain == 0 )
			return true;
	}

	if( uiRemain > BUFFER_SIZE )
	{
		unsigned int uiReadSize = ALIGN(uiRemain);

		if( fread(pcBufPtr, 1, uiReadSize, (FILE*)m_pFile) == uiReadSize )
		{
			m_uiPos += uiReadSize;
			pcBufPtr += uiReadSize;
			uiRemain -= uiReadSize;

			m_uiBufferTail = m_uiPos;

			if( uiRemain == 0 )
				return true;
		}
		else
		{
			return false;
		}
	}

	assert( uiRemain < BUFFER_SIZE && uiRemain > 0 );

	unsigned int uiRead = fread(m_Buffer, 1, BUFFER_SIZE, (FILE*)m_pFile);
	if( uiRemain > uiRead )
		return false;

	memcpy(pcBufPtr, m_Buffer, uiRemain);
	m_uiBufferTail = m_uiPos + uiRead;
	m_uiPos += uiRemain;

	return true;
}

bool CFileStream::Write(const void* pBuf, unsigned int uiSize)
{
	assert( m_pFile );
	assert( m_eAccessMode == WriteMode );

	return fwrite(pBuf, 1, uiSize, (FILE*)m_pFile) == uiSize;
}

bool CFileStream::Seek(int offset, int origin)
{
	assert( m_pFile );

	unsigned int uiNewPos;
	if( origin == SeekBegin )
	{
		uiNewPos = offset;
	}
	else if( origin == SeekCurrent )
	{
		uiNewPos = m_uiPos + offset;
	}
	else if( origin == SeekEnd )
	{
		uiNewPos = m_uiSize + offset;
	}
	else
	{
		assert( false );
	}

	assert( uiNewPos < m_uiSize );

	m_uiPos = uiNewPos;
	if( ALIGN(m_uiPos) == ALIGN(m_uiBufferTail) )
		return true;

	m_uiBufferTail = ALIGN(m_uiPos);
	return fseek((FILE*)m_pFile, m_uiPos, SEEK_SET) == 0;
}
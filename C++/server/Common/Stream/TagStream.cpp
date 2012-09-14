
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include "TagStream.h"

bool CTagStream::Read(void* pBuf, unsigned int uiSize)
{
	if( m_uiPos + uiSize < m_uiSize )
	{
		memcpy(pBuf, m_pBuffer + m_uiPos, uiSize);
		m_uiPos += uiSize;
		return true;
	}

	return false;
}

bool CTagStream::Seek(int offset, int origin)
{
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
	return true;
}

bool CTagStream::ReadFromStream(CStream& stream)
{
	Close();

	if( !stream.Read(&m_uiTag, sizeof(unsigned int)) )
		return false;

	stream.Read(&m_uiSize, sizeof(unsigned int));

	if( m_pBuffer )
	{
		if( m_uiSize > BUFFER_SIZE )
		{
			m_pBuffer = (char*)realloc( m_pBuffer, m_uiSize );
		}
	}
	else
		m_pBuffer = (char*)malloc( BUFFER_SIZE );
	stream.Read(m_pBuffer, m_uiSize);
	return true;
}

void CTagStream::Close()
{
	if( m_pBuffer )
	{
		free( m_pBuffer );
		m_pBuffer = NULL;
	}

	m_uiSize = 0;
	m_uiPos = 0;
}

CTagStream::CTagStream()
{
	m_pBuffer = (char*)malloc( BUFFER_SIZE );
	assert( m_pBuffer );
}

CTagStream::~CTagStream()
{
	Close();
}
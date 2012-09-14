#include "StdAfx.h"
#include "MyNetGlobleObj.h"

void MyNetGlobleObj::InitMsg(int MsgHeadLen, int MsgBasicHeadLen)
{
	mMessageHeadLen = MsgHeadLen;
	mMessageBasicHeadLen = MsgBasicHeadLen;
	mQueueMessageLimitSize = mMessageBasicHeadLen + mMessageBasicHeadLen;


}
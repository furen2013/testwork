#include "StdAfx.h"
#include "MyNetGlobleObj.h"
#include "MsgHead.pb.h"

void MyNetGlobleObj::InitMsg(int MsgHeadLen, int MsgBasicHeadLen)
{
	mMessageHeadLen = MsgHeadLen;
	mMessageBasicHeadLen = MsgBasicHeadLen;
	mQueueMessageLimitSize = mMessageBasicHeadLen + mMessageBasicHeadLen;
	pMsgHead = new MsgHead();
	pMsgHead->set_type(MsgType::C2Gate_MsgNull);
	pMsgHead->set_msgsize(52);
	



}
#include "StdAfx.h"
#include "MyNetGlobleObj.h"
#include "MsgHead.pb.h"

int MyNetGlobleObj::mMessageBasicHeadLen = 0;
int MyNetGlobleObj::mMessageHeadLen = 0;
int MyNetGlobleObj::mQueueMessageLimitSize = MAX_MESSAGE_LEN * 10;;
void MyNetGlobleObj::InitMsg(int MsgHeadLen, int MsgBasicHeadLen)
{
	mMessageHeadLen = MsgHeadLen;
	mMessageBasicHeadLen = MsgBasicHeadLen;
	mQueueMessageLimitSize = MAX_MESSAGE_LEN * 10;;
	//pMsgHead = new MsgHead();
	//pMsgHead->set_type(MsgType::C2Gate_MsgNull);
	//pMsgHead->set_msgsize(52);
	//



}
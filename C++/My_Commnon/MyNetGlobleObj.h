#ifndef MYNETGLOBLEOBJ_HEAD
#define MYNETGLOBLEOBJ_HEAD

#pragma once
#include "asiodef.h"
struct MyNetGlobleObj : public net_global
{
public:
	static void InitMsg(int MsgHeadLen, int MsgBasicHeadLen);
	static inline int GetMsgHeadLen(){return mMessageHeadLen;}
	static int GetMsgBasicHeadLen(){return mMessageBasicHeadLen;}
	static int GetQueueMsgLimitSize(){return mQueueMessageLimitSize;};

private:
	static int mMessageHeadLen;
	static int mMessageBasicHeadLen;
	static int mQueueMessageLimitSize;
	static bool bIsInit;
};



#endif
// protoClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProtoNet/ProtoSocket.h"


#include "../new_common/Source/new_common.h"

#ifdef WIN32
#include "../server/Common/Platform/ServiceWin32.h"
zip_compress_strategy impcs;
#endif
int _tmain(int argc, _TCHAR* argv[])
{

#ifdef _WIN32
	MyNetGlobleObj::init_net_service( 2, 5, &impcs, true, 100 );
#else
	MyNetGlobleObj::init_net_service( 32, 5, &impcs, true, 9000 );
#endif
	int HeadLen = 2 * sizeof(unsigned short);
	MyNetGlobleObj::InitMsg(HeadLen, 0);
	CProtoSocket* protoSocket = new CProtoSocket(*MyNetGlobleObj::get_io_service());
	protoSocket->connect("127.0.0.1", 95501);
	while (true)
	{
		protoSocket->run();
		Sleep(50);
	}
	
	int n = 0;
	n ++;
	return 0;
}


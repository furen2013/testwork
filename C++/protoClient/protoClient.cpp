// protoClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ProtoNet/ProtoSocket.h"


#include "../new_common/Source/new_common.h"
#include "../new_common/Source/log4cpp-1.0/MyLog.h"
#include <boost/thread.hpp>   
#include <iostream>  

#ifdef WIN32
#include "../server/Common/Platform/ServiceWin32.h"
zip_compress_strategy impcs;
#endif

CProtoSocket* protoSocket = NULL;
void thread()
{
	while(protoSocket)
	{
		protoSocket->run();
		boost::this_thread::sleep(boost::posix_time::seconds(10)); 
	}

}


int _tmain(int argc, _TCHAR* argv[])
{

	MyLog::Init();

#ifdef _WIN32
	MyNetGlobleObj::init_net_service( 2, 5, &impcs, true, 100 );
#else
	MyNetGlobleObj::init_net_service( 32, 5, &impcs, true, 9000 );
#endif
	int HeadLen = 2 * sizeof(unsigned short);
	MyNetGlobleObj::InitMsg(HeadLen, 0);
	protoSocket = new CProtoSocket(*MyNetGlobleObj::get_io_service());
	protoSocket->connect("127.0.0.1", 95501);
	boost::thread t(thread);   
	t.join();  
	while (true)
	{
		int n = 0;
		std::cin >> n;
		switch(n)
		{
		case 1:
			{

			}
			break;
		case 2:
			{

			}
			break;
		}
	}
	
	int n = 0;
	n ++;
	return 0;
}


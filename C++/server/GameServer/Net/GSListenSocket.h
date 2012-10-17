#pragma once
#include "../../new_common/Source/net/tcpserver.h"
#include <map>
#include <boost/thread.hpp>

class CGSListenSocket :
	public tcp_server
{
public:
	CGSListenSocket(void);
	virtual ~CGSListenSocket(void);

	virtual void stop();
	virtual tcp_basesession* create_session();

private:
	

};


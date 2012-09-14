#pragma once
#include "../../new_common/Source/net/tcpserver.h"

class CGSListenSocket :
	public tcp_server
{
public:
	CGSListenSocket(void);
	virtual ~CGSListenSocket(void);

	virtual void stop();
	virtual tcp_session* create_session();

private:


};


#include "call_back.h"


void call_back_mgr::poll()
{
	std::list<i_call*> temp;
	{
		boost::mutex::scoped_lock lock( m_mutex );
		if( !m_listcb.empty() )
			std::swap( temp, m_listcb );
		else
			return;
	}
	for( std::list<i_call*>::iterator it = temp.begin(); it != temp.end(); ++it )
	{
		i_call* p = *it;
		p->call();
		delete p;
	}
}

void call_back_mgr::clear()
{
	boost::mutex::scoped_lock lock( m_mutex );
	m_listcb.clear();
}

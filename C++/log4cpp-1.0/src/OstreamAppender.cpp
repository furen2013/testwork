/*
 * OstreamAppender.cpp
 *
 * Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2000, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#include "PortabilityImpl.hh"
#ifdef LOG4CPP_HAVE_UNISTD_H
#    include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <log4cpp/OstreamAppender.hh>


#ifndef _WIN32
static const char* colorstrings[TBLUE+1] = {
	"",
	"\033[22;31m",
	"\033[22;32m",
	"\033[01;33m",
	//"\033[22;37m",
	"\033[0m",
	"\033[01;37m",
	"\033[22;36m",
};
#endif


const int colorPriority[] =
{
	TYELLOW,	//FATAL,EMERG
	TYELLOW,	//ALERT
	TYELLOW,	//CRIT
	TRED,		//ERROR
	TYELLOW,	//WARN
	TNORMAL,	//NOTICE
	TGREEN,		//INFO
	TBLUE,		//DEBUG
	TWHITE		//NOTSET
};

namespace log4cpp {
	int gColorCode = TNORMAL;
#ifdef _WIN32
	HANDLE stdout_handle, stderr_handle;
#endif

    OstreamAppender::OstreamAppender(const std::string& name, std::ostream* stream) :
        LayoutAppender(name),
        _stream(stream) {
#ifdef _WIN32
			stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
			stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

    }

    OstreamAppender::~OstreamAppender() {
        close();
    }

    void OstreamAppender::close() {
        // empty
    }

    void OstreamAppender::_append(const LoggingEvent& event) {
		if( gColorCode != colorPriority[event.priority/100] )
		{
			gColorCode = colorPriority[event.priority/100];
#ifdef _WIN32
			SetConsoleTextAttribute(stdout_handle, gColorCode);
#else
			printf(colorstrings[gColorCode]);
#endif
		}
        (*_stream) << _getLayout().format(event);
        if (!_stream->good()) {
            // XXX help! help!
        }
    }

    bool OstreamAppender::reopen() {
        return true;
    }
}

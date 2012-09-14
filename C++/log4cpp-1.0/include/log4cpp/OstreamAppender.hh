/*
 * OstreamAppender.hh
 *
 * Copyright 2000, LifeLine Networks BV (www.lifeline.nl). All rights reserved.
 * Copyright 2000, Bastiaan Bakker. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4CPP_OSTREAMAPPENDER_HH
#define _LOG4CPP_OSTREAMAPPENDER_HH

#include <log4cpp/Portability.hh>
#include <string>
#include <iostream>
#include <log4cpp/LayoutAppender.hh>


#ifdef _WIN32

#define TRED FOREGROUND_RED | FOREGROUND_INTENSITY
#define TGREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define TYELLOW FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define TNORMAL FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE
#define TWHITE TNORMAL | FOREGROUND_INTENSITY
#define TBLUE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#else

#define TRED 1
#define TGREEN 2
#define TYELLOW 3
#define TNORMAL 4
#define TWHITE 5
#define TBLUE 6

#endif
namespace log4cpp {

    /**
     * OstreamAppender appends LoggingEvents to ostreams.
     **/
    class LOG4CPP_EXPORT OstreamAppender : public LayoutAppender {
        public:
        OstreamAppender(const std::string& name, std::ostream* stream);
        virtual ~OstreamAppender();
        
        virtual bool reopen();
        virtual void close();

        protected:
        virtual void _append(const LoggingEvent& event);

        std::ostream* _stream;
    };
}

#endif // _LOG4CPP_OSTREAMAPPENDER_HH

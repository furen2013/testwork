#ifndef MANGOSSERVER_ERRORS_H
#define MANGOSSERVER_ERRORS_H

#define WPAssert( assertion ) { if( !(assertion) ) { fprintf( stderr, "\n%s:%i ASSERTION FAILED:\n  %s\n", __FILE__, __LINE__, #assertion ); assert( #assertion &&0 ); } }
#define WPError( assertion, errmsg ) if( ! (assertion) ) { MyLog::log->error( "%s:%i ERROR:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); assert( false ); }
#define WPWarning( assertion, errmsg ) if( ! (assertion) ) { MyLog::log->error( "%s:%i WARNING:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); }

#define WPFatal( assertion, errmsg ) if( ! (assertion) ) { MyLog::log->error( "%s:%i FATAL ERROR:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); assert( #assertion &&0 ); abort(); }

#define ASSERT WPAssert
#endif

AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=DBServerD
DBServerD_SOURCES=\
		AccountMgr.cpp \
		Config.cpp \
		DataInterface.cpp \
		DBServer.cpp Server.cpp \
		WorldInfo.cpp \
		Net/GSBuilder.cpp \
		Net/GSParser.cpp \
		Net/GTBuilder.cpp \
		Net/GTParser.cpp \
		Net/GSListenSocket.cpp \
		Net/GSSocket.cpp \
		Net/GTListenSocket.cpp \
		Net/GTSocket.cpp

AM_CPPFLAGS=-I/home/gui/work/boost_1_44_0/ -I../../new_common/Source -I../../new_common/Source/log4cpp-1.0/include -I../Common -I../Common/share
DBServerD_LDFLAGS=-L/usr/lib -lpthread -lnew_common -lCommon -lssl -lmysqlclient_r -lac_client -lboost_thread -lboost_system


AUTOMAKE_OPTIONS=foreign
AM_CPPFLAGS=-I/home/gui/work/boost_1_44_0/ -I../../new_common/Source -I../../new_common/Source/log4cpp-1.0/include -I../Common -I../Common/share
bin_PROGRAMS=GateServerD
GateServerD_SOURCES=\
		Config.cpp\
		GateServer.cpp\
		Server.cpp\
		UserManager.cpp\
		Net/CListenSocket.cpp\
		Net/CParser.cpp\
		Net/CSocket.cpp\
		Net/CSParser.cpp\
		Net/CSSocket.cpp\
		Net/DSParser.cpp\
		Net/DSSocket.cpp\
		Net/GSParser.cpp\
		Net/GSSocket.cpp

GateServerD_LDFLAGS=-L/usr/lib -lpthread -lnew_common -lCommon -lssl -lmysqlclient_r -lac_client -lboost_thread -lboost_system


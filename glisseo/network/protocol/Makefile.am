AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-network-protocol.la

libglisseo_network_protocol_la_SOURCES = \
    GenericJsonOverNetstringServerConnection.cpp \
    GenericJsonOverNetstringServerConnection.h \
    GenericJsonRpcServerConnection.cpp \
    GenericJsonRpcServerConnection.h \
    GenericNetstringServerConnection.cpp \
    GenericNetstringServerConnection.h \
    GenericServer.cpp \
    GenericServer.h \
    GenericServerConnection.cpp \
    GenericServerConnection.h \
    GenericTelnetService.cpp \
    GenericTelnetService.h \
    JsonRpc.cpp \
    JsonRpc.h \
    JsonRpcInvalidParamsException.cpp \
    JsonRpcInvalidParamsException.h \
    JsonRpcMethodNotFoundException.cpp \
    JsonRpcMethodNotFoundException.h \
    JsonTags.h \
    NetstringDecoder.cpp \
    NetstringDecoder.h \
    NetstringEncoder.cpp \
    NetstringEncoder.h \
    Slip.cpp \
    Slip.h \
    TelnetServer.cpp \
    TelnetServer.h \
    TelnetServerConnection.cpp \
    TelnetServerConnection.h

libglisseo_network_protocol_la_CPPFLAGS = \
    $(AM_CPPFLAGS) \
    $(JSONCPP_CFLAGS)

libglisseo_network_protocol_la_LIBADD = \
    $(JSONCPP_LIBS)

headerdir = $(includedir)/glisseo/network/protocol
header_HEADERS = \
    GenericJsonOverNetstringServerConnection.h \
    GenericJsonRpcServerConnection.h \
    GenericNetstringServerConnection.h \
    GenericServer.h \
    GenericServerConnection.h \
    GenericTelnetService.h \
    JsonRpc.h \
    JsonRpcInvalidParamsException.h \
    JsonRpcMethodNotFoundException.h \
    NetstringDecoder.h \
    NetstringEncoder.h \
    Slip.h \
    TelnetServer.h \
    TelnetServerConnection.h

MAINTAINERCLEANFILES = \
    Makefile.in

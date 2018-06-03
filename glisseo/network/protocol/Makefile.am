AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-network-protocol.la

libglisseo_network_protocol_la_SOURCES = \
    GenericServer.cpp \
    GenericServer.h \
    GenericServerConnection.cpp \
    GenericServerConnection.h \
    GenericTelnetService.cpp \
    GenericTelnetService.h \
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

headerdir = $(includedir)/glisseo/network/protocol
header_HEADERS = \
    GenericServer.h \
    GenericServerConnection.h \
    GenericTelnetService.h \
    NetstringDecoder.h \
    NetstringEncoder.h \
    Slip.h \
    TelnetServer.h \
    TelnetServerConnection.h

MAINTAINERCLEANFILES = \
    Makefile.in

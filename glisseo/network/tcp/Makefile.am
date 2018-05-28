AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-network-tcp.la

libglisseo_network_tcp_la_SOURCES = \
    GenericTcp.cpp \
    GenericTcp.h \
    GenericTcpConnection.cpp \
    GenericTcpConnection.h \
    TcpClient.cpp \
    TcpClient.h \
    TcpServer.cpp \
    TcpServer.h \
    TcpServerConnection.cpp \
    TcpServerConnection.h

headerdir = $(includedir)/glisseo/network/tcp
header_HEADERS = \
    GenericTcp.h \
    GenericTcpConnection.h \
    TcpClient.h \
    TcpServer.h \
    TcpServerConnection.h

MAINTAINERCLEANFILES = \
    Makefile.in

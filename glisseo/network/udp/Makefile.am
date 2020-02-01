AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-network-udp.la

libglisseo_network_udp_la_SOURCES = \
    GenericUdp.cpp \
    GenericUdp.h \
    UdpClient.cpp \
    UdpClient.h \
    UdpServer.cpp \
    UdpServer.h

headerdir = $(includedir)/glisseo/network/udp
header_HEADERS = \
    GenericUdp.h \
    UdpClient.h \
    UdpServer.h

MAINTAINERCLEANFILES = \
    Makefile.in

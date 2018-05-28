AM_CPPFLAGS = \
    -I$(top_srcdir)

SUBDIRS = \
    protocol \
    serial \
    tcp

noinst_LTLIBRARIES = libglisseo-network.la

libglisseo_network_la_SOURCES = \
    Protocol.cpp \
    Protocol.h

libglisseo_network_la_LIBADD = \
    $(top_builddir)/glisseo/network/protocol/libglisseo-network-protocol.la \
    $(top_builddir)/glisseo/network/serial/libglisseo-network-serial.la \
    $(top_builddir)/glisseo/network/tcp/libglisseo-network-tcp.la

headerdir = $(includedir)/glisseo/network
header_HEADERS = \
    Protocol.h

MAINTAINERCLEANFILES = \
    Makefile.in

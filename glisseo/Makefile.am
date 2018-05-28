SUBDIRS = \
    digest \
    network \
    utils

AM_CPPFLAGS = \
    -I$(top_srcdir)

lib_LTLIBRARIES = libglisseo.la

libglisseo_la_SOURCES = \
    Glisseo.cpp \
    Glisseo.h

libglisseo_la_LIBADD = \
    $(top_builddir)/glisseo/digest/libglisseo-digest.la \
    $(top_builddir)/glisseo/network/libglisseo-network.la \
    $(top_builddir)/glisseo/utils/libglisseo-utils.la

headerdir = $(includedir)/glisseo
header_HEADERS = \
    Glisseo.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = glisseo.pc

MAINTAINERCLEANFILES = \
    Autoconf.h.in \
    Makefile.in

AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-utils.la

libglisseo_utils_la_SOURCES = \
    Conversion.cpp \
    Conversion.h \
    GenericThread.cpp \
    GenericThread.h \
    Log.cpp \
    Log.h \
    LogLevel.cpp \
    LogLevel.h \
    Select.cpp \
    Select.h

libglisseo_utils_la_LDFLAGS = \
    -pthread

headerdir = $(includedir)/glisseo/utils
header_HEADERS = \
    Conversion.h \
    GenericThread.h \
    Log.h \
    LogLevel.h \
    Select.h

MAINTAINERCLEANFILES = \
    Makefile.in

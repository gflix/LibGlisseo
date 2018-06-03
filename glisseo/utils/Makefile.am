AM_CPPFLAGS = \
    -I$(top_srcdir)

noinst_LTLIBRARIES = libglisseo-utils.la

libglisseo_utils_la_SOURCES = \
    Conversion.cpp \
    Conversion.h \
    GenericThread.cpp \
    GenericThread.h \
    Invocation.cpp \
    Invocation.h \
    InvocationArgument.cpp \
    InvocationArgument.h \
    Join.cpp \
    Join.h \
    Log.cpp \
    Log.h \
    LogLevel.cpp \
    LogLevel.h \
    Range.cpp \
    Range.h \
    Select.cpp \
    Select.h \
    Split.cpp \
    Split.h \
    Trim.cpp \
    Trim.h

libglisseo_utils_la_LDFLAGS = \
    -pthread

headerdir = $(includedir)/glisseo/utils
header_HEADERS = \
    Conversion.h \
    GenericThread.h \
    Invocation.h \
    InvocationArgument.h \
    Join.h \
    Log.h \
    LogLevel.h \
    Range.h \
    Select.h \
    Split.h \
    Trim.h

MAINTAINERCLEANFILES = \
    Makefile.in

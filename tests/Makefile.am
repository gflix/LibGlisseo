AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = \
    -I$(top_srcdir) \
    -I$(top_srcdir)/external/googletest/include

AM_LDFLAGS = \
    $(top_builddir)/glisseo/libglisseo.la \
    $(top_builddir)/external/googletest/libgtest.la

TESTS = \
    conversion \
    glisseo \
    invocation \
    protocol \
    select \
    sha1 \
    tcp-client \
    tcp-server
 
check_PROGRAMS = $(TESTS)

conversion_SOURCES = TestConversion.cpp
glisseo_SOURCES = TestGlisseo.cpp
invocation_SOURCES = TestInvocation.cpp
protocol_SOURCES = TestProtocol.cpp
select_SOURCES = TestSelect.cpp
sha1_SOURCES = TestSha1.cpp
tcp_client_SOURCES = TestTcpClient.cpp
tcp_server_SOURCES = TestTcpServer.cpp

MAINTAINERCLEANFILES = \
    Makefile.in

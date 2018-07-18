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
    join \
    netstring-encoder \
    netstring-decoder \
    protocol \
    range \
    select \
    sha1 \
    split \
    stringtest \
    trim \
    tcp-client \
    tcp-server
 
check_PROGRAMS = $(TESTS)

conversion_SOURCES = TestConversion.cpp
glisseo_SOURCES = TestGlisseo.cpp
invocation_SOURCES = TestInvocation.cpp
join_SOURCES = TestJoin.cpp
netstring_encoder_SOURCES = TestNetstringEncoder.cpp
netstring_decoder_SOURCES = TestNetstringDecoder.cpp
protocol_SOURCES = TestProtocol.cpp
range_SOURCES = TestRange.cpp
select_SOURCES = TestSelect.cpp
sha1_SOURCES = TestSha1.cpp
split_SOURCES = TestSplit.cpp
stringtest_SOURCES = TestString.cpp
trim_SOURCES = TestTrim.cpp
tcp_client_SOURCES = TestTcpClient.cpp
tcp_server_SOURCES = TestTcpServer.cpp

MAINTAINERCLEANFILES = \
    Makefile.in

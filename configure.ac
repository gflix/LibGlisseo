#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libglisseo], [0.5.5], [felix.mellmann@gmail.com])
AC_CONFIG_SRCDIR([glisseo/Glisseo.cpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([glisseo/Autoconf.h])

AM_INIT_AUTOMAKE()

# Checks for programs.
AM_PROG_AR
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AX_CXX_COMPILE_STDCXX_11()

LT_INIT

# Checks for libraries.
PKG_CHECK_MODULES([JSONCPP],[jsoncpp >= 1.6.0],[],AC_MSG_ERROR([Could not find jsoncpp >= 1.6.0.]))

# Checks for header files.
AC_CHECK_HEADER_STDBOOL
AC_CHECK_HEADERS([netdb.h unistd.h arpa/inet.h fcntl.h float.h limits.h])
AC_CHECK_HEADERS([stddef.h sys/socket.h sys/time.h sys/timeb.h wchar.h wctype.h])
AC_CHECK_HEADERS([systemd/sd-daemon.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_CHECK_TYPES([ptrdiff_t])
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_CHECK_FUNCS([bzero socket dup2 fchdir getcwd getpagesize gettimeofday localtime_r memset mkdir munmap regcomp rmdir])
AC_CHECK_FUNCS([select strcasecmp strchr strdup strerror strrchr strstr strtol strtoull])
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_STRERROR_R

DX_INIT_DOXYGEN([libglisseo], [Doxyfile], [doc])

AC_CONFIG_FILES([
    Makefile
    Doxyfile
    examples/Makefile
    external/googletest/Makefile
    glisseo/Makefile
    glisseo/glisseo.pc
    glisseo/digest/Makefile
    glisseo/network/Makefile
    glisseo/network/serial/Makefile
    glisseo/network/protocol/Makefile
    glisseo/network/tcp/Makefile
    glisseo/utils/Makefile
    tests/Makefile
])
AC_OUTPUT

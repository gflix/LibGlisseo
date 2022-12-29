# add the root of this source tree to the include path
include_directories(
    ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/extern/gtest/include ${CMAKE_SOURCE_DIR}/extern/gtest
)

set(
    UNITTEST_SOURCE_FILES
    unittest/TestConversion.cpp
    unittest/TestDateTime.cpp
    unittest/TestEnumMapper.cpp
    unittest/TestGlisseo.cpp
    unittest/TestHexdump.cpp
    unittest/TestInvocation.cpp
    unittest/TestJoin.cpp
    unittest/TestNetstringDecoder.cpp
    unittest/TestNetstringEncoder.cpp
    unittest/TestProtocol.cpp
    unittest/TestRange.cpp
    unittest/TestSelect.cpp
    unittest/TestSha1.cpp
    unittest/TestSplit.cpp
    unittest/TestString.cpp
    unittest/TestTcpClient.cpp
    unittest/TestTcpServer.cpp
    unittest/TestTrim.cpp
)

add_executable(
    gtest
    EXCLUDE_FROM_ALL

    ${LIBRARY_SOURCE_FILES}
    ${UNITTEST_SOURCE_FILES}

    extern/gtest/src/gtest-all.cc
    extern/gtest/src/gtest_main.cc
)

# extra compiler options
target_compile_options(
    gtest
    PRIVATE
    -O0 -coverage
)

target_link_libraries(
    gtest
    PkgConfig::JSONCPP
    Threads::Threads
    -coverage
)

# when a target "check" exists the unittests will be automatically run on building the Debian package
add_custom_target(
    check
    gtest
)

# add the root of this source tree to the include path
include_directories(
    ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}
)

set(
    LIBRARY_SOURCE_FILES
    glisseo/Glisseo.cpp
    glisseo/datetime/LocalDate.cpp
    glisseo/datetime/LocalDateTime.cpp
    glisseo/datetime/LocalTime.cpp
    glisseo/datetime/Weekday.cpp
    glisseo/digest/Sha1.cpp
    glisseo/network/Protocol.cpp
    glisseo/network/protocol/GenericJsonOverNetstringClient.cpp
    glisseo/network/protocol/GenericJsonOverNetstringServerConnection.cpp
    glisseo/network/protocol/GenericJsonRpcClient.cpp
    glisseo/network/protocol/GenericJsonRpcServerConnection.cpp
    glisseo/network/protocol/GenericNetstringClient.cpp
    glisseo/network/protocol/GenericNetstringServerConnection.cpp
    glisseo/network/protocol/GenericServer.cpp
    glisseo/network/protocol/GenericServerConnection.cpp
    glisseo/network/protocol/GenericTelnetService.cpp
    glisseo/network/protocol/JsonRpc.cpp
    glisseo/network/protocol/JsonRpcErrorResponse.cpp
    glisseo/network/protocol/JsonRpcInvalidParamsException.cpp
    glisseo/network/protocol/JsonRpcMethodNotFoundException.cpp
    glisseo/network/protocol/JsonRpcNotification.cpp
    glisseo/network/protocol/JsonRpcResponse.cpp
    glisseo/network/protocol/NetstringDecoder.cpp
    glisseo/network/protocol/NetstringEncoder.cpp
    glisseo/network/protocol/Slip.cpp
    glisseo/network/protocol/TelnetServer.cpp
    glisseo/network/protocol/TelnetServerConnection.cpp
    glisseo/network/serial/Baudrate.cpp
    glisseo/network/serial/SerialPort.cpp
    glisseo/network/tcp/GenericTcp.cpp
    glisseo/network/tcp/GenericTcpConnection.cpp
    glisseo/network/tcp/TcpClient.cpp
    glisseo/network/tcp/TcpServer.cpp
    glisseo/network/tcp/TcpServerConnection.cpp
    glisseo/network/udp/GenericUdp.cpp
    glisseo/network/udp/UdpClient.cpp
    glisseo/network/udp/UdpServer.cpp
    glisseo/utils/ByteArray.cpp
    glisseo/utils/Conversion.cpp
    glisseo/utils/EnumMapper.cpp
    glisseo/utils/GenericDescriptor.cpp
    glisseo/utils/GenericThread.cpp
    glisseo/utils/Hexdump.cpp
    glisseo/utils/Invocation.cpp
    glisseo/utils/InvocationArgument.cpp
    glisseo/utils/Join.cpp
    glisseo/utils/Log.cpp
    glisseo/utils/LogLevel.cpp
    glisseo/utils/Range.cpp
    glisseo/utils/Select.cpp
    glisseo/utils/Split.cpp
    glisseo/utils/String.cpp
    glisseo/utils/Timer.cpp
    glisseo/utils/Trim.cpp
)

# generate pkg-config file
configure_file(
    glisseo/Autoconf.h.in
    glisseo/Autoconf.h
    @ONLY
)

add_library(
    glisseo SHARED
    ${LIBRARY_SOURCE_FILES}
)

# extra compiler options
target_compile_options(
    glisseo
    PRIVATE
    -Wall -Werror
)

target_link_libraries(
    glisseo
    PkgConfig::JSONCPP
    PkgConfig::SYSTEMD
    Threads::Threads
)

# set properties on the generated library
set_target_properties(
    glisseo PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
)

# install binaries to the target
install(
    TARGETS
    glisseo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# generate pkg-config file
configure_file(
    glisseo/glisseo.pc.in
    glisseo/glisseo.pc
    @ONLY
)

# install pkg-config file to the target
install(
    FILES
    ${CMAKE_BINARY_DIR}/glisseo/glisseo.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

# install header files
install(
    FILES
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/
)

# install header files
install(
    FILES
    glisseo/Glisseo.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo
)

install(
    FILES
    glisseo/datetime/LocalDate.h
    glisseo/datetime/LocalDateTime.h
    glisseo/datetime/LocalTime.h
    glisseo/datetime/Weekday.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/datetime
)

install(
    FILES
    glisseo/digest/Sha1.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/digest
)

install(
    FILES
    glisseo/network/Protocol.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/network
)

install(
    FILES
    glisseo/network/protocol/GenericJsonOverNetstringClient.h
    glisseo/network/protocol/GenericJsonOverNetstringServerConnection.h
    glisseo/network/protocol/GenericJsonRpcClient.h
    glisseo/network/protocol/GenericJsonRpcServerConnection.h
    glisseo/network/protocol/GenericNetstringClient.h
    glisseo/network/protocol/GenericNetstringServerConnection.h
    glisseo/network/protocol/GenericServer.h
    glisseo/network/protocol/GenericServerConnection.h
    glisseo/network/protocol/GenericTelnetService.h
    glisseo/network/protocol/JsonRpc.h
    glisseo/network/protocol/JsonRpcErrorResponse.h
    glisseo/network/protocol/JsonRpcInvalidParamsException.h
    glisseo/network/protocol/JsonRpcMethodNotFoundException.h
    glisseo/network/protocol/JsonRpcNotification.h
    glisseo/network/protocol/JsonRpcResponse.h
    glisseo/network/protocol/JsonTags.h
    glisseo/network/protocol/Messages.h
    glisseo/network/protocol/NetstringDecoder.h
    glisseo/network/protocol/NetstringEncoder.h
    glisseo/network/protocol/Slip.h
    glisseo/network/protocol/TelnetServer.h
    glisseo/network/protocol/TelnetServerConnection.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/network/protocol
)

install(
    FILES
    glisseo/network/serial/Baudrate.h
    glisseo/network/serial/SerialPort.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/network/serial
)

install(
    FILES
    glisseo/network/tcp/GenericTcp.h
    glisseo/network/tcp/GenericTcpConnection.h
    glisseo/network/tcp/TcpClient.h
    glisseo/network/tcp/TcpServer.h
    glisseo/network/tcp/TcpServerConnection.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/network/tcp
)

install(
    FILES
    glisseo/network/udp/GenericUdp.h
    glisseo/network/udp/UdpClient.h
    glisseo/network/udp/UdpServer.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/network/udp
)

install(
    FILES
    glisseo/utils/ByteArray.h
    glisseo/utils/Conversion.h
    glisseo/utils/EnumMapper.h
    glisseo/utils/GenericDescriptor.h
    glisseo/utils/GenericThread.h
    glisseo/utils/Hexdump.h
    glisseo/utils/Invocation.h
    glisseo/utils/InvocationArgument.h
    glisseo/utils/Join.h
    glisseo/utils/Log.h
    glisseo/utils/LogLevel.h
    glisseo/utils/Range.h
    glisseo/utils/Select.h
    glisseo/utils/Split.h
    glisseo/utils/String.h
    glisseo/utils/Timer.h
    glisseo/utils/Trim.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glisseo/utils
)

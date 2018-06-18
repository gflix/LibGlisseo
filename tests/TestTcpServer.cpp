#include <gtest/gtest.h>
#include <glisseo/network/tcp/TcpServer.h>

TEST(TcpServer, StartValueRanges)
{
    Glisseo::TcpServer tcpServer;

    int invalidTcpPortLow = 0;
    int invalidTcpPortHigh = 65536;
    Glisseo::Protocol dummyProtocol = Glisseo::Protocol::IPV4;
    int dummyTcpPort = 6635;
    Glisseo::Protocol invalidProtocol = static_cast<Glisseo::Protocol>(-1);

    EXPECT_ANY_THROW(tcpServer.start(invalidTcpPortLow, dummyProtocol));
    EXPECT_ANY_THROW(tcpServer.start(invalidTcpPortHigh, dummyProtocol));
    EXPECT_ANY_THROW(tcpServer.start(dummyTcpPort, invalidProtocol));
}

TEST(TcpServer, Defaults)
{
    Glisseo::TcpServer tcpServer;

    EXPECT_FALSE(tcpServer.isConnected());
    EXPECT_EQ(tcpServer.getDescriptor(), INVALID_DESCRIPTOR);
}

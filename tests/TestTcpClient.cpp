#include <gtest/gtest.h>
#include <glisseo/network/tcp/TcpClient.h>

TEST(TcpClient, ConnectValueRanges)
{
    Glisseo::TcpClient tcpClient;

    std::string invalidHost;
    std::string dummyHost { "127.0.0.1" };
    int invalidTcpPortLow = 0;
    int invalidTcpPortHigh = 65536;
    int dummyTcpPort = 6635;

    EXPECT_ANY_THROW(tcpClient.connect(invalidHost, dummyTcpPort));
    EXPECT_ANY_THROW(tcpClient.connect(dummyHost, invalidTcpPortLow));
    EXPECT_ANY_THROW(tcpClient.connect(dummyHost, invalidTcpPortHigh));
}

TEST(TcpClient, Defaults)
{
    Glisseo::TcpClient tcpClient;

    EXPECT_FALSE(tcpClient.isConnected());
    EXPECT_EQ(tcpClient.getDescriptor(), INVALID_DESCRIPTOR);
}

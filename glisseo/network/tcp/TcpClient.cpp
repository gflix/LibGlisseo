#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <glisseo/utils/Range.h>
#include <glisseo/utils/Split.h>
#include <glisseo/network/tcp/TcpClient.h>

namespace Glisseo {

TcpClient::TcpClient(void):
    GenericTcpConnection(),
    protocol(Protocol::UNDEFINED)
{
}

TcpClient::~TcpClient()
{
    disconnect();
}

void TcpClient::connect(std::string peer, int defaultPort)
{
    disconnect();

    std::string host;
    int port = 0;

    splitHostPort(peer, defaultPort, host, port);

    addrinfo getAddrInfoHints;
    addrinfo* getAddrInfoResult = nullptr;
    addrinfo* addressInfo = nullptr;

    bzero(&getAddrInfoHints, sizeof(getAddrInfoHints));
    getAddrInfoHints.ai_family = AF_UNSPEC;
    getAddrInfoHints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host.c_str(), std::to_string(port).c_str(), &getAddrInfoHints, &getAddrInfoResult) != 0)
    {
        throw std::runtime_error("could not resolve host");
    }

    for (addressInfo = getAddrInfoResult; addressInfo; addressInfo = addressInfo->ai_next)
    {
        descriptor = socket(addressInfo->ai_family, addressInfo->ai_socktype, addressInfo->ai_protocol);
        if (!descriptorIsValid())
        {
            continue;
        }
        if (::connect(descriptor, addressInfo->ai_addr, addressInfo->ai_addrlen) != 0)
        {
            disconnect();
            continue;
        }

        if (addressInfo->ai_family == AF_INET)
        {
            sockaddr_in clientAddressInfo;
            socklen_t clientAddressInfoLength = sizeof(clientAddressInfo);
            bzero(&clientAddressInfo, sizeof(clientAddressInfo));
            if (getsockname(descriptor, (sockaddr*)&clientAddressInfo, &clientAddressInfoLength) != 0)
            {
                throw std::runtime_error("could not determine own IPv4 address from connection");
            }
            char socketAddressBuffer[INET_ADDRSTRLEN];
            bzero(socketAddressBuffer, sizeof(socketAddressBuffer));
            inet_ntop(addressInfo->ai_family, &clientAddressInfo.sin_addr, socketAddressBuffer, sizeof(socketAddressBuffer));
            ownAddress = std::string(socketAddressBuffer) + ":" + std::to_string(ntohs(clientAddressInfo.sin_port));

            bzero(socketAddressBuffer, sizeof(socketAddressBuffer));
            sockaddr_in* peerAddressInfo = (sockaddr_in*)addressInfo->ai_addr;
            inet_ntop(addressInfo->ai_family, &peerAddressInfo->sin_addr, socketAddressBuffer, sizeof(socketAddressBuffer));
            peerAddress = std::string(socketAddressBuffer) + ":" + std::to_string(ntohs(peerAddressInfo->sin_port));
            protocol = Protocol::IPV4;
        }
        else if (addressInfo->ai_family == AF_INET6)
        {
            sockaddr_in6 clientAddressInfo;
            socklen_t clientAddressInfoLength = sizeof(clientAddressInfo);
            bzero(&clientAddressInfo, sizeof(clientAddressInfo));
            if (getsockname(descriptor, (sockaddr*)&clientAddressInfo, &clientAddressInfoLength) != 0)
            {
                throw std::runtime_error("could not determine own IPv6 address from connection");
            }
            char socketAddressBuffer[INET6_ADDRSTRLEN];
            bzero(socketAddressBuffer, sizeof(socketAddressBuffer));
            inet_ntop(addressInfo->ai_family, &clientAddressInfo.sin6_addr, socketAddressBuffer, sizeof(socketAddressBuffer));
            ownAddress = std::string(socketAddressBuffer) + ":" + std::to_string(ntohs(clientAddressInfo.sin6_port));

            bzero(socketAddressBuffer, sizeof(socketAddressBuffer));
            sockaddr_in6* peerAddressInfo = (sockaddr_in6*)addressInfo->ai_addr;
            inet_ntop(addressInfo->ai_family, &peerAddressInfo->sin6_addr, socketAddressBuffer, sizeof(socketAddressBuffer));
            peerAddress = std::string(socketAddressBuffer) + ":" + std::to_string(ntohs(peerAddressInfo->sin6_port));
            protocol = Protocol::IPV6;
        }

        break;
    }
    freeaddrinfo(getAddrInfoResult);

    if (!isConnected())
    {
        throw std::runtime_error("could not connect to host");
    }
}

void TcpClient::disconnect(void)
{
    GenericTcpConnection::disconnect();
    ownAddress.clear();
}

const std::string& TcpClient::getOwnAddress(void) const
{
    return ownAddress;
}

const std::string& TcpClient::getPeerAddress(void) const
{
    return peerAddress;
}

Protocol TcpClient::getProtocol(void) const
{
    return protocol;
}

} /* namespace Glisseo */

#include <netdb.h>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <glisseo/utils/Range.h>
#include <glisseo/utils/Split.h>
#include <glisseo/network/tcp/TcpClient.h>

namespace Glisseo {

TcpClient::TcpClient(void):
    GenericTcpConnection()
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
        break;
    }
    freeaddrinfo(getAddrInfoResult);

    if (!isConnected())
    {
        throw std::runtime_error("could not connect to host");
    }
}

} /* namespace Glisseo */

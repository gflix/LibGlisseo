#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include <stdexcept>
#include <glisseo/network/udp/GenericUdp.h>
#include <glisseo/network/udp/UdpServer.h>
#include <glisseo/utils/Range.h>

#define UDP_RECEIVE_BUFFER_SIZE (16384)

namespace Glisseo
{

UdpServer::UdpServer(void):
    GenericDescriptor()
{
}

UdpServer::~UdpServer()
{
    stop();
}

void UdpServer::start(const std::string& bindAddress, int port, Protocol protocol)
{
    stop();

    if (!withinRange(port, UDP_PORT_MIN, UDP_PORT_MAX))
    {
        throw std::invalid_argument("invalid port number");
    }

    addrinfo addressInfoHints;
    bzero(&addressInfoHints, sizeof(addressInfoHints));
    addressInfoHints.ai_family = protocol == Protocol::IPV4 ? AF_INET : AF_INET6;
    addressInfoHints.ai_socktype = SOCK_DGRAM;
    addressInfoHints.ai_flags = bindAddress.empty() ? AI_PASSIVE : 0;

    addrinfo* addressInfoResult = nullptr;
    auto getaddrinfoResult = getaddrinfo(
        bindAddress.empty() ? nullptr : bindAddress.c_str(),
        std::to_string(port).c_str(),
        &addressInfoHints,
        &addressInfoResult);
    if (getaddrinfoResult != 0)
    {
        throw std::runtime_error(
            "getaddrinfo() returned an error (" + std::string(gai_strerror(getaddrinfoResult)) + ")");
    }

    auto item = addressInfoResult;
    for (; item != nullptr; item = item->ai_next)
    {
        descriptor = socket(item->ai_family, item->ai_socktype, item->ai_protocol);
        if (descriptor < 0)
        {
            continue;
        }

        if (bind(descriptor, item->ai_addr, item->ai_addrlen) == 0)
        {
            break;
        }

        close(descriptor);
        invalidateDescriptor();
    }
    freeaddrinfo(addressInfoResult);

    if (!item)
    {
        throw std::runtime_error("error binding to the UDP socket");
    }
}

void UdpServer::stop(void)
{
    if (descriptor >= 0)
    {
        ::close(descriptor);
        invalidateDescriptor();
    }
}

void UdpServer::receiveByteArray(ByteArray& array)
{
    static uint8_t receiveBuffer[UDP_RECEIVE_BUFFER_SIZE];

    if (!descriptorIsValid())
    {
        throw std::runtime_error("invalid descriptor");
    }

    auto bytesReceived = recv(descriptor, &receiveBuffer, UDP_RECEIVE_BUFFER_SIZE, 0);
    if (bytesReceived < 0)
    {
        throw std::runtime_error("error receiving UDP message");
    }
    array = ByteArray(receiveBuffer, bytesReceived);
}

void UdpServer::receiveString(std::string& text)
{
    static char receiveBuffer[UDP_RECEIVE_BUFFER_SIZE];

    if (!descriptorIsValid())
    {
        throw std::runtime_error("invalid descriptor");
    }

    auto bytesReceived = recv(descriptor, &receiveBuffer, UDP_RECEIVE_BUFFER_SIZE, 0);
    if (bytesReceived < 0)
    {
        throw std::runtime_error("error receiving UDP message");
    }
    text = std::string(receiveBuffer, bytesReceived);
}

} /* namespace Glisseo */

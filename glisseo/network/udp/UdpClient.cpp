#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include <glisseo/network/udp/UdpClient.h>
#include <glisseo/utils/Split.h>

namespace Glisseo
{

UdpClient::UdpClient(std::string peer, int defaultPort):
    GenericDescriptor()
{
    std::string host;
    int port = 0;

    splitHostPort(peer, defaultPort, host, port);

    addrinfo addressInfoHints;
    bzero(&addressInfoHints, sizeof(addressInfoHints));
    addressInfoHints.ai_family = AF_UNSPEC;
    addressInfoHints.ai_socktype = SOCK_DGRAM;

    addrinfo* addressInfoResult = nullptr;
    auto getaddrinfoResult = getaddrinfo(
        host.c_str(),
        std::to_string(port).c_str(),
        &addressInfoHints,
        &addressInfoResult);
    if (getaddrinfoResult != 0)
    {
        throw std::runtime_error(
            "getaddrinfo() failed for " + host + ":" + std::to_string(port) +
            ": " + std::string(gai_strerror(getaddrinfoResult)));
    }

    auto item = addressInfoResult;
    for (; item; item = item->ai_next)
    {
        descriptor = socket(item->ai_family, item->ai_socktype, item->ai_protocol);
        if (descriptor < 0)
        {
            continue;
        }

        if (connect(descriptor, item->ai_addr, item->ai_addrlen) != -1)
        {
            break;
        }

        close(descriptor);
        invalidateDescriptor();
    }

    freeaddrinfo(addressInfoResult);

    if (!item || !descriptorIsValid())
    {
        throw std::runtime_error("connecting to UDP socket " + host + ":" + std::to_string(port) + " failed");
    }
}

UdpClient::~UdpClient()
{
    if (descriptor >= 0)
    {
        ::close(descriptor);
    }
}

void UdpClient::sendByteArray(const ByteArray& array)
{
    if (!descriptorIsValid())
    {
        throw std::runtime_error("invalid descriptor");
    }

    auto arrayLength = array.size();
    auto bytesSent = send(descriptor, array.c_str(), arrayLength, 0);
    if (bytesSent < 0)
    {
        throw std::runtime_error("error sending UDP message (" + std::string(strerror(errno)) + ")");
    }
    if (bytesSent != (ssize_t)arrayLength)
    {
        throw std::runtime_error(
            "sent bytes differ from the UDP message size "
            "(" + std::to_string(bytesSent) + "/" + std::to_string(arrayLength) + ")");
    }
}

void UdpClient::sendString(const std::string& text)
{
    if (!descriptorIsValid())
    {
        throw std::runtime_error("invalid descriptor");
    }

    auto textLength = text.size();
    auto bytesSent = send(descriptor, text.c_str(), textLength, 0);
    if (bytesSent < 0)
    {
        throw std::runtime_error("error sending UDP message (" + std::string(strerror(errno)) + ")");
    }
    if (bytesSent != (ssize_t)textLength)
    {
        throw std::runtime_error(
            "sent bytes differ from the UDP message size "
            "(" + std::to_string(bytesSent) + "/" + std::to_string(textLength) + ")");
    }
}

} /* namespace Glisseo */

#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <stdexcept>
#include <glisseo/network/udp/UdpSocket.h>

namespace Glisseo {

UdpSocket::UdpSocket(void)
{
    descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if (descriptor < 0)
    {
        throw std::runtime_error("failed setting up UDP socket (" + std::string(strerror(errno)) + ")");
    }
}

UdpSocket::~UdpSocket()
{
    close(descriptor);
}

} /* namespace Glisseo */

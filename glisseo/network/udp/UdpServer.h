#ifndef GLISSEO_NETWORK_UDP_UDPSERVER_H_
#define GLISSEO_NETWORK_UDP_UDPSERVER_H_

#include <string>
#include <glisseo/network/Protocol.h>
#include <glisseo/utils/ByteArray.h>
#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo
{

class UdpServer: public GenericDescriptor
{
public:
    UdpServer(void);
    virtual ~UdpServer();

    /// Starts the UDP server on a given port
    void start(const std::string& bindAddress, int port, Protocol protocol = Protocol::IPV4);
    /// Stops the UDP server
    void stop(void);

    void receiveByteArray(ByteArray& array);
    void receiveString(std::string& text);

protected:
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_UDP_UDPSERVER_H_ */

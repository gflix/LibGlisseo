#ifndef GLISSEO_NETWORK_UDP_UDPCLIENT_H_
#define GLISSEO_NETWORK_UDP_UDPCLIENT_H_

#include <string>
#include <glisseo/network/udp/GenericUdp.h>
#include <glisseo/utils/ByteArray.h>
#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo
{

class UdpClient: public GenericDescriptor
{
public:
    UdpClient(std::string peer, int defaultPort);
    virtual ~UdpClient();

    void sendByteArray(const ByteArray& array);
    void sendString(const std::string& text);
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_UDP_UDPCLIENT_H_ */

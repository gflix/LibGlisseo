#ifndef GLISSEO_NETWORK_UDP_UDPCLIENT_H_
#define GLISSEO_NETWORK_UDP_UDPCLIENT_H_

#include <glisseo/network/udp/GenericUdp.h>

namespace Glisseo {

class UdpClient: public GenericUdp {
public:
    UdpClient(void);
    virtual ~UdpClient() = default;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_UDP_UDPCLIENT_H_ */

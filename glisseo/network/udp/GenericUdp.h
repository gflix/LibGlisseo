#ifndef GLISSEO_NETWORK_UDP_GENERICUDP_H_
#define GLISSEO_NETWORK_UDP_GENERICUDP_H_

#include <glisseo/network/udp/UdpSocket.h>

namespace Glisseo {

class GenericUdp {
public:
    GenericUdp(void);
    virtual ~GenericUdp() = default;

protected:
    UdpSocket socket;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_UDP_GENERICUDP_H_ */

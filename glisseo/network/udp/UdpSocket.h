#ifndef GLISSEO_NETWORK_UDP_UDPSOCKET_H_
#define GLISSEO_NETWORK_UDP_UDPSOCKET_H_

#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo {

class UdpSocket: GenericDescriptor {
public:
    UdpSocket(void);
    virtual ~UdpSocket();
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_UDP_UDPSOCKET_H_ */

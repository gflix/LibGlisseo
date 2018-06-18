#ifndef NETWORKING_TCP_TCPSERVER_H_
#define NETWORKING_TCP_TCPSERVER_H_

#include <glisseo/network/Protocol.h>
#include <glisseo/network/tcp/GenericTcp.h>

namespace Glisseo {

class TcpServer: public GenericTcp {
public:
    TcpServer();
    virtual ~TcpServer();

    void start(int port, Protocol protocol = Protocol::IPV4);
    void stop(void);
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_TCPSERVER_H_ */

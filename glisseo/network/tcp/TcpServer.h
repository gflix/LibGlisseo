#ifndef NETWORKING_TCP_TCPSERVER_H_
#define NETWORKING_TCP_TCPSERVER_H_

#include <glisseo/network/Protocol.h>
#include <glisseo/network/tcp/GenericTcp.h>

namespace Glisseo {

/// Implementation of a TCP server
class TcpServer: public GenericTcp {
public:
    TcpServer(void);
    virtual ~TcpServer();

    /// Starts the TCP server on a given port using a given protocol (IPv4 or IPv6)
    void start(int port, Protocol protocol = Protocol::IPV4);
    /// Stops the TCP server
    void stop(void);
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_TCPSERVER_H_ */

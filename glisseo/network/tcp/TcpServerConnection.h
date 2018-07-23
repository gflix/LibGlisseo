#ifndef NETWORKING_TCP_TCPSERVERCONNECTION_H_
#define NETWORKING_TCP_TCPSERVERCONNECTION_H_

#include <string>
#include <glisseo/network/tcp/GenericTcpConnection.h>

namespace Glisseo {

/// Implements a TCP server connection
class TcpServerConnection: public GenericTcpConnection {
public:
    /// Initializes the connection with a POSIX descriptor
    explicit TcpServerConnection(int descriptor);
    virtual ~TcpServerConnection() = default;
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_TCPSERVERCONNECTION_H_ */

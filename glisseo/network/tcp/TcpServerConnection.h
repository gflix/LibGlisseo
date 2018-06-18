#ifndef NETWORKING_TCP_TCPSERVERCONNECTION_H_
#define NETWORKING_TCP_TCPSERVERCONNECTION_H_

#include <string>
#include <glisseo/network/tcp/GenericTcpConnection.h>

namespace Glisseo {

class TcpServerConnection: public GenericTcpConnection {
public:
    TcpServerConnection(int descriptor);
    virtual ~TcpServerConnection();
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_TCPSERVERCONNECTION_H_ */

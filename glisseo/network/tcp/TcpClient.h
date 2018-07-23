#ifndef TCPCLIENT_TCPCLIENT_H_
#define TCPCLIENT_TCPCLIENT_H_

#include <string>
#include <glisseo/network/tcp/GenericTcpConnection.h>

namespace Glisseo {

/// Implementation of a TCP client
class TcpClient: public GenericTcpConnection {
public:
    TcpClient(void);
    virtual ~TcpClient();

    /// Tries to connect to a given host on a given default TCP port, if hostname:port is given the default is overridden
    virtual void connect(std::string host, int port);
};

} /* namespace Glisseo */

#endif /* TCPCLIENT_TCPCLIENT_H_ */

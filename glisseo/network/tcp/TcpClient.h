#ifndef TCPCLIENT_TCPCLIENT_H_
#define TCPCLIENT_TCPCLIENT_H_

#include <string>
#include <glisseo/network/tcp/GenericTcpConnection.h>

namespace Glisseo {

class TcpClient: public GenericTcpConnection {
public:
    TcpClient(void);
    virtual ~TcpClient();

    virtual void connect(std::string host, int port);
};

} /* namespace Glisseo */

#endif /* TCPCLIENT_TCPCLIENT_H_ */

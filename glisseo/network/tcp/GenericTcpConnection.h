#ifndef NETWORKING_TCP_GENERICTCPCONNECTION_H_
#define NETWORKING_TCP_GENERICTCPCONNECTION_H_

#include <string>
#include <glisseo/network/tcp/GenericTcp.h>

#define TCP_RECEIVE_BUFFER_SIZE_DEFAULT (1024)

namespace Glisseo {

/// Basic class for TCP connections
class GenericTcpConnection: public GenericTcp {
public:
    GenericTcpConnection(void);
    virtual ~GenericTcpConnection() = default;

    /// Close the connection
    void disconnect(void);

    /// Send a message through the connection, blocking operation
    void send(const std::string& data) const;
    /// Receive a message from the connection, blocking operation
    void receive(std::string& data, size_t bufferSize = TCP_RECEIVE_BUFFER_SIZE_DEFAULT) const;
};

} /* namespace Glisseo */

#endif /* NETWORKING_TCP_GENERICTCPCONNECTION_H_ */

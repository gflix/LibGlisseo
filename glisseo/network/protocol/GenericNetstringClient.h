#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_

#include <string>
#include <vector>
#include <glisseo/network/protocol/NetstringDecoder.h>
#include <glisseo/network/protocol/Messages.h>
#include <glisseo/network/tcp/TcpClient.h>

namespace Glisseo {

/// Basic class of a TCP client which uses netstrings for communication
class GenericNetstringClient: public TcpClient {
public:
    GenericNetstringClient(void);
    virtual ~GenericNetstringClient() = default;

    /// Connect to a given host using a default TCP port, if hostname:port is given the port is overridden
    virtual void connect(std::string host, int port) override;

    /// Send a message through the connection and wrap the message into a netstring
    void sendMessage(const std::string& message) const;
    /// Receive a netstring wrapped message from the connection
    void receiveMessages(Messages& messages);

private:
    NetstringDecoder netstringDecoder;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGCLIENT_H_ */

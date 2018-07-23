#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_

#include <glisseo/network/protocol/GenericServerConnection.h>
#include <glisseo/network/protocol/NetstringDecoder.h>

namespace Glisseo {

/// Basic class for netstring based server connections
class GenericNetstringServerConnection: public GenericServerConnection {
public:
    /// Initializes the connection with the given arguments
    GenericNetstringServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericNetstringServerConnection() = default;

    /// Send a message through the server connection, the message is wrapped into a netstring
    virtual void send(const std::string& message) override;

protected:
    /// Overridden thread setup method
    virtual bool setup(void) override;
    /// Overridden thread task method
    virtual bool task(const Select& select) override;

    /// Process a single message
    virtual void processMessage(const std::string& message) = 0;

private:
    NetstringDecoder netstringDecoder;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICNETSTRINGSERVERCONNECTION_H_ */

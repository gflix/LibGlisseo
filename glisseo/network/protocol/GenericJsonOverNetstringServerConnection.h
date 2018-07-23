#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_

#include <json/json.h>
#include <glisseo/network/protocol/GenericNetstringServerConnection.h>

namespace Glisseo {

/// Basic class for a server connection transporting JSON using netstrings
class GenericJsonOverNetstringServerConnection: public GenericNetstringServerConnection {
public:
    /// Initialize the server connection with the given arguments
    GenericJsonOverNetstringServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericJsonOverNetstringServerConnection() = default;

    /// Send a JSON encoded message through the server connection
    virtual void send(const Json::Value& message);

protected:
    /// Process a received message
    virtual void processMessage(const std::string& message) override;
    /// Process a received JSON message
    virtual void processMessage(const Json::Value& message) = 0;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONOVERNETSTRINGSERVERCONNECTION_H_ */

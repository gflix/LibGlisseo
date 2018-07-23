#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_

#include <glisseo/network/protocol/GenericJsonOverNetstringServerConnection.h>

namespace Glisseo {

/// Basic class for a JSON-RPC server connection using netstrings over TCP
class GenericJsonRpcServerConnection: public GenericJsonOverNetstringServerConnection {
public:
    /// Initializes the server connection with the given arguments
    GenericJsonRpcServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericJsonRpcServerConnection() = default;

protected:
    /// Process a received JSON-RPC message
    virtual void processMessage(const Json::Value& message) override;
    /// Process a JSON-RPC message which is a method call
    virtual void processCall(const Json::Value& message) = 0;
    /// Process a JSON-RPC message which is a notification
    virtual void processNotification(const Json::Value& message) = 0;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_ */

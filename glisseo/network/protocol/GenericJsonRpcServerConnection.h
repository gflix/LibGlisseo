#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_

#include <glisseo/network/protocol/GenericJsonOverNetstringServerConnection.h>

namespace Glisseo {

class GenericJsonRpcServerConnection: public GenericJsonOverNetstringServerConnection {
public:
    GenericJsonRpcServerConnection(
        const std::string& identifier,
        int descriptor,
        const std::string& peer);
    virtual ~GenericJsonRpcServerConnection() = default;

protected:
    virtual void processMessage(const Json::Value& message) override;
    virtual void processCall(const Json::Value& message) = 0;
    virtual void processNotification(const Json::Value& message) = 0;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCSERVERCONNECTION_H_ */

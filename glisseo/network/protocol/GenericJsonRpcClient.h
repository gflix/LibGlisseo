#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_

#include <glisseo/network/protocol/GenericJsonOverNetstringClient.h>

namespace Glisseo {

/// Basic class of JSON-RPC client using netstrings
class GenericJsonRpcClient: public GenericJsonOverNetstringClient {
public:
    GenericJsonRpcClient(void);
    virtual ~GenericJsonRpcClient() = default;

    /// Send a JSON-RPC message to the server
    void sendJsonRpcMessage(const Json::Value& jsonRpcMessage) const;
    /// Receive a JSON-RPC message from the server
    void receiveJsonRpcMessages(JsonMessages& jsonRpcMessages);
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_ */

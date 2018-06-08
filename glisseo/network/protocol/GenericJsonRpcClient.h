#ifndef GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_
#define GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_

#include <glisseo/network/protocol/GenericJsonOverNetstringClient.h>

namespace Flix {

class GenericJsonRpcClient: public GenericJsonOverNetstringClient {
public:
    GenericJsonRpcClient();
    virtual ~GenericJsonRpcClient();

    void sendJsonRpcMessage(const Json::Value& jsonRpcMessage) const;
    void receiveJsonRpcMessages(JsonMessages& jsonRpcMessages);
};

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_GENERICJSONRPCCLIENT_H_ */

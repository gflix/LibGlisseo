#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_

#include <string>
#include <json/json.h>

namespace Flix {

void initializeJsonRpcMessage(
        Json::Value& message,
        const std::string& method,
        const Json::Value& id = Json::nullValue);

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_ */

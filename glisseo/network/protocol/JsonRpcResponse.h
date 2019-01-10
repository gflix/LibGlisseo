#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCRESPONSE_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCRESPONSE_H_

#include <string>
#include <json/json.h>

namespace Glisseo {

struct JsonRpcResponse
{
    JsonRpcResponse(void);

    void deserialize(const Json::Value& json);
    void serialize(Json::Value& json);

    int id;
    Json::Value result;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCRESPONSE_H_ */

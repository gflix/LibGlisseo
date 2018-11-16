#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCERRORRESPONSE_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCERRORRESPONSE_H_

#include <string>
#include <json/json.h>

namespace Glisseo {

struct JsonRpcErrorResponse
{
    JsonRpcErrorResponse(void);

    void deserialize(const Json::Value& json);
    void serialize(Json::Value& json);

    int id;
    Json::Value error;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCERRORRESPONSE_H_ */

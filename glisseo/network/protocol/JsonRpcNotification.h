#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCNOTIFICATION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCNOTIFICATION_H_

#include <string>
#include <json/json.h>

namespace Glisseo {

struct JsonRpcNotification {
    JsonRpcNotification();

    void deserialize(const Json::Value& json);
    void serialize(Json::Value& json);

    std::string method;
    Json::Value result;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCNOTIFICATION_H_ */

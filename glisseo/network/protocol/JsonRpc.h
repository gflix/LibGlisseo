#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_

#include <string>
#include <json/json.h>
#include <glisseo/network/protocol/JsonTags.h>

namespace Flix {

void initializeJsonRpcMessage(
    Json::Value& message,
    const std::string& method,
    const Json::Value& id = Json::nullValue);
void initializeJsonRpcErrorResponse(
    Json::Value& response,
    int errorCode,
    const std::string& errorMessage,
    Json::Value id = Json::nullValue);
void checkJsonRpcTag(const Json::Value& message);
void checkJsonRpcClientRequestValidity(const Json::Value& message);
void checkJsonRpcClientResponseValidity(const Json::Value& message);
template<typename T>
void checkJsonRpcServerRequestValidity(const Json::Value& message, T callback)
{
    Json::Value response;

    try
    {
        checkJsonRpcTag(message);
    }
    catch(std::domain_error& e)
    {
        initializeJsonRpcErrorResponse(response, -32600, e.what());
        callback(response);

        throw;
    }
    if (!message.isMember(JSON_TAG_METHOD) ||
        !message[JSON_TAG_METHOD].isString() ||
        message[JSON_TAG_METHOD].asString().empty())
    {
        std::string errorMessage = "JSON-RPC 2.0 method is missing";
        initializeJsonRpcErrorResponse(response, -32600, errorMessage);
        callback(response);

        throw std::domain_error(errorMessage);
    }
}

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPC_H_ */

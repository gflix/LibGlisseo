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
template<typename T>
void checkJsonRpcMessageValidity(const Json::Value& message, T callback)
{
    Json::Value response;

    if (!message.isObject())
    {
        std::string errorMessage = "JSON is not an object";
        initializeJsonRpcErrorResponse(response, -32600, errorMessage);
        callback(response);

        throw std::domain_error(errorMessage);
    }
    if (!message.isMember(JSON_TAG_JSONRPC) ||
        !message[JSON_TAG_JSONRPC].isString() ||
        message[JSON_TAG_JSONRPC].asString() != "2.0")
    {
        std::string errorMessage = "not a JSON-RPC 2.0 request object";
        initializeJsonRpcErrorResponse(response, -32600, errorMessage);
        callback(response);

        throw std::domain_error(errorMessage);
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

#include <stdexcept>
#include <glisseo/network/protocol/JsonRpc.h>

namespace Flix {

void initializeJsonRpcMessage(
        Json::Value& message,
        const std::string& method,
        const Json::Value& id)
{
    message = Json::objectValue;

    if (method.empty())
    {
        throw std::invalid_argument("method name must not be empty");
    }

    message[JSON_TAG_JSONRPC] = "2.0";
    message[JSON_TAG_METHOD] = method;
    if (id != Json::nullValue)
    {
        message[JSON_TAG_ID] = id;
    }
}

void initializeJsonRpcErrorResponse(
    Json::Value& response,
    int errorCode,
    const std::string& errorMessage,
    Json::Value id)
{
    Json::Value jsonError = Json::objectValue;

    jsonError[JSON_TAG_CODE] = errorCode;
    jsonError[JSON_TAG_MESSAGE] = errorMessage;

    response = Json::objectValue;
    response[JSON_TAG_JSONRPC] = "2.0";
    response[JSON_TAG_ERROR] = jsonError;
    response[JSON_TAG_ID] = id;
}

} /* namespace Flix */

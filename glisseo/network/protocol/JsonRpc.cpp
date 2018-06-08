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

void checkJsonRpcTag(const Json::Value& message)
{
    if (!message.isObject())
    {
        throw std::domain_error("JSON is not an object");
    }
    if (!message.isMember(JSON_TAG_JSONRPC) ||
        !message[JSON_TAG_JSONRPC].isString() ||
        message[JSON_TAG_JSONRPC].asString() != "2.0")
    {
        throw std::domain_error("not a JSON-RPC 2.0 request object");
    }
}

void checkJsonRpcClientRequestValidity(const Json::Value& message)
{
    checkJsonRpcTag(message);
    if (!message.isMember(JSON_TAG_ID))
    {
        throw std::domain_error("JSON-RPC id is missing");
    }
    if (!message.isMember(JSON_TAG_METHOD) ||
        !message[JSON_TAG_METHOD].isString() ||
        message[JSON_TAG_METHOD].asString().empty())
    {
        throw std::domain_error("JSON-RPC method is missing");
    }
}

void checkJsonRpcClientResponseValidity(const Json::Value& message)
{
    checkJsonRpcTag(message);
    if (!message.isMember(JSON_TAG_ID) &&
        !message.isMember(JSON_TAG_METHOD))
    {
        throw std::domain_error("neither id nor method object is present");
    }
    if (message.isMember(JSON_TAG_METHOD) &&
        (!message[JSON_TAG_METHOD].isString() ||
        message[JSON_TAG_METHOD].asString().empty()))
    {
        throw std::domain_error("JSON-RPC method is given but not valid");
    }
    if (!message.isMember(JSON_TAG_RESULT) &&
        !message.isMember(JSON_TAG_ERROR))
    {
        throw std::domain_error("neither result nor error object is present");
    }
}

} /* namespace Flix */

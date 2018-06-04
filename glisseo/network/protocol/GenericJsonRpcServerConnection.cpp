#include <glisseo/network/protocol/GenericJsonRpcServerConnection.h>
#include <glisseo/network/protocol/JsonRpcInvalidParamsException.h>
#include <glisseo/network/protocol/JsonRpcMethodNotFoundException.h>
#include <glisseo/network/protocol/JsonTags.h>

namespace Flix {

GenericJsonRpcServerConnection::GenericJsonRpcServerConnection(
    const std::string& identifier,
    int descriptor,
    const std::string& peer):
    GenericJsonOverNetstringServerConnection(identifier, descriptor, peer)
{
}

GenericJsonRpcServerConnection::~GenericJsonRpcServerConnection()
{
}

void GenericJsonRpcServerConnection::processMessage(const Json::Value& message)
{
    Json::Value response = Json::objectValue;
    if (!message.isObject())
    {
        std::string errorMessage = "JSON is not an object";
        generateErrorResponse(response, -32600, errorMessage);
        send(response);

        throw std::domain_error(errorMessage);
    }
    if (!message.isMember(JSON_TAG_JSONRPC) ||
        !message[JSON_TAG_JSONRPC].isString() ||
        message[JSON_TAG_JSONRPC].asString() != "2.0")
    {
        std::string errorMessage = "not a JSON-RPC 2.0 request object";
        generateErrorResponse(response, -32600, errorMessage);
        send(response);

        throw std::domain_error(errorMessage);
    }
    if (!message.isMember(JSON_TAG_METHOD) ||
        !message[JSON_TAG_METHOD].isString() ||
        message[JSON_TAG_METHOD].asString().empty())
    {
        std::string errorMessage = "JSON-RPC 2.0 method is missing";
        generateErrorResponse(response, -32600, errorMessage);
        send(response);

        throw std::domain_error(errorMessage);
    }

    Json::Value id = Json::nullValue;
    if (message.isMember(JSON_TAG_ID))
    {
        id = message[JSON_TAG_ID];
    }
    try
    {
        if (id != Json::nullValue)
        {
            processCall(message);
        }
        else
        {
            processNotification(message);
        }
    }
    catch (JsonRpcMethodNotFoundException& e)
    {
        generateErrorResponse(response, -32601, std::string(e.what()), id);
        send(response);
    }
    catch (JsonRpcInvalidParamsException& e)
    {
        generateErrorResponse(response, -32602, std::string(e.what()), id);
        send(response);
    }
    catch (std::exception& e)
    {
        generateErrorResponse(response, -32603, std::string(e.what()), id);
        send(response);
    }
}

void GenericJsonRpcServerConnection::generateErrorResponse(
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

#include <glisseo/network/protocol/GenericJsonRpcServerConnection.h>
#include <glisseo/network/protocol/JsonRpcInvalidParamsException.h>
#include <glisseo/network/protocol/JsonRpcMethodNotFoundException.h>
#include <glisseo/network/protocol/JsonRpc.h>
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
    checkJsonRpcMessageValidity(message, [=](const Json::Value& response) {
        send(response);
    });

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
        initializeJsonRpcErrorResponse(response, -32601, std::string(e.what()), id);
        send(response);
    }
    catch (JsonRpcInvalidParamsException& e)
    {
        initializeJsonRpcErrorResponse(response, -32602, std::string(e.what()), id);
        send(response);
    }
    catch (std::exception& e)
    {
        initializeJsonRpcErrorResponse(response, -32603, std::string(e.what()), id);
        send(response);
    }
}

} /* namespace Flix */

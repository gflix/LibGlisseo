#include <glisseo/network/protocol/GenericJsonRpcClient.h>

namespace Glisseo {

GenericJsonRpcClient::GenericJsonRpcClient()
{
}

GenericJsonRpcClient::~GenericJsonRpcClient()
{
}

void GenericJsonRpcClient::sendJsonRpcMessage(const Json::Value& jsonRpcMessage) const
{
    sendJsonMessage(jsonRpcMessage);
}

void GenericJsonRpcClient::receiveJsonRpcMessages(JsonMessages& jsonRpcMessages)
{
    receiveJsonMessages(jsonRpcMessages);
}

} /* namespace Glisseo */

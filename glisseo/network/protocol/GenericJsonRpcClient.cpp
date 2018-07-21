#include <glisseo/network/protocol/GenericJsonRpcClient.h>

namespace Glisseo {

GenericJsonRpcClient::GenericJsonRpcClient(void)
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

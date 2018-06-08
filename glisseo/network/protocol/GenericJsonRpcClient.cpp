#include <glisseo/network/protocol/GenericJsonRpcClient.h>

namespace Flix {

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

} /* namespace Flix */

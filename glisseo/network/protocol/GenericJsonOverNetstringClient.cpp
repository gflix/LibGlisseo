#include <glisseo/network/protocol/GenericJsonOverNetstringClient.h>

namespace Glisseo {

GenericJsonOverNetstringClient::GenericJsonOverNetstringClient()
{
}

GenericJsonOverNetstringClient::~GenericJsonOverNetstringClient()
{
}

void GenericJsonOverNetstringClient::sendJsonMessage(const Json::Value& jsonMessage) const
{
    sendMessage(jsonMessage.toStyledString());
}

void GenericJsonOverNetstringClient::receiveJsonMessages(JsonMessages& jsonMessages)
{
    Messages messages;
    receiveMessages(messages);

    for (auto& message: messages)
    {
        Json::Reader jsonReader;
        Json::Value jsonMessage;

        if (!jsonReader.parse(message, jsonMessage, false))
        {
            throw std::domain_error("JSON parse error");
        }
        jsonMessages.push_back(jsonMessage);
    }
}

} /* namespace Glisseo */

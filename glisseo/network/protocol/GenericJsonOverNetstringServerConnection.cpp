#include <glisseo/network/protocol/GenericJsonOverNetstringServerConnection.h>

namespace Glisseo {

GenericJsonOverNetstringServerConnection::GenericJsonOverNetstringServerConnection(
    const std::string& identifier,
    int descriptor,
    const std::string& peer):
    GenericNetstringServerConnection(identifier, descriptor, peer)
{
}

void GenericJsonOverNetstringServerConnection::send(const Json::Value& message)
{
    GenericNetstringServerConnection::send(message.toStyledString());
}

void GenericJsonOverNetstringServerConnection::processMessage(const std::string& message)
{
    Json::Reader jsonReader;
    Json::Value json;

    if (!jsonReader.parse(message, json, false))
    {
        throw std::domain_error("JSON parse error");
    }

    processMessage(json);
}

} /* namespace Glisseo */

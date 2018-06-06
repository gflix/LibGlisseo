#include <stdexcept>
#include <glisseo/network/protocol/JsonRpc.h>
#include <glisseo/network/protocol/JsonTags.h>

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

} /* namespace Flix */

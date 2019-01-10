#include <glisseo/network/protocol/JsonRpcNotification.h>
#include <glisseo/network/protocol/JsonTags.h>

namespace Glisseo {

JsonRpcNotification::JsonRpcNotification(void):
    result(Json::nullValue)
{
}

void JsonRpcNotification::serialize(Json::Value& json)
{
    json = Json::objectValue;

    json[JSON_TAG_JSONRPC] = JSONRPC_VERSION_2_0;
    json[JSON_TAG_METHOD] = method;
    json[JSON_TAG_RESULT] = result;
}

void JsonRpcNotification::deserialize(const Json::Value& json)
{
    if (!json.isObject() ||
        !json.isMember(JSON_TAG_JSONRPC) ||
        !json[JSON_TAG_JSONRPC].isString() ||
        !json.isMember(JSON_TAG_METHOD) ||
        !json[JSON_TAG_METHOD].isString() ||
        !json.isMember(JSON_TAG_RESULT))
    {
        throw std::invalid_argument("invalid JSON for a JSON-RPC notification");
    }

    if (json[JSON_TAG_JSONRPC].asString() != JSONRPC_VERSION_2_0)
    {
        throw std::invalid_argument("invalid JSON-RPC version");
    }

    method = json[JSON_TAG_METHOD].asString();
    result = json[JSON_TAG_RESULT];
}

} /* namespace Glisseo */

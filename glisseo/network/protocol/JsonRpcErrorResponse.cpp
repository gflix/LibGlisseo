#include <glisseo/network/protocol/JsonRpcErrorResponse.h>
#include <glisseo/network/protocol/JsonTags.h>

namespace Glisseo {

JsonRpcErrorResponse::JsonRpcErrorResponse(void):
    id(-1),
    error(Json::nullValue)
{
}

void JsonRpcErrorResponse::serialize(Json::Value& json)
{
    json = Json::objectValue;

    json[JSON_TAG_JSONRPC] = JSONRPC_VERSION_2_0;
    json[JSON_TAG_ID] = id;
    json[JSON_TAG_ERROR] = error;
}

void JsonRpcErrorResponse::deserialize(const Json::Value& json)
{
    if (!json.isObject() ||
        !json.isMember(JSON_TAG_JSONRPC) ||
        !json[JSON_TAG_JSONRPC].isString() ||
        !json.isMember(JSON_TAG_ID) ||
        !json[JSON_TAG_ID].isInt() ||
        !json.isMember(JSON_TAG_ERROR))
    {
        throw std::invalid_argument("invalid JSON for a JSON-RPC response");
    }

    if (json[JSON_TAG_JSONRPC].asString() != JSONRPC_VERSION_2_0)
    {
        throw std::invalid_argument("invalid JSON-RPC version");
    }

    id = json[JSON_TAG_ID].asInt();
    error = json[JSON_TAG_ERROR];
}

} /* namespace Glisseo */

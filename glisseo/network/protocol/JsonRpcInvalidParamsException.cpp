#include <glisseo/network/protocol/JsonRpcInvalidParamsException.h>

namespace Glisseo {

JsonRpcInvalidParamsException::JsonRpcInvalidParamsException(const std::string& what):
    std::logic_error(what)
{
}

JsonRpcInvalidParamsException::~JsonRpcInvalidParamsException()
{
}

} /* namespace Glisseo */

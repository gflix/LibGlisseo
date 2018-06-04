#include <glisseo/network/protocol/JsonRpcInvalidParamsException.h>

namespace Flix {

JsonRpcInvalidParamsException::JsonRpcInvalidParamsException(const std::string& what):
    std::logic_error(what)
{
}

JsonRpcInvalidParamsException::~JsonRpcInvalidParamsException()
{
}

} /* namespace Flix */

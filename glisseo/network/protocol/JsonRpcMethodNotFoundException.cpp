#include <glisseo/network/protocol/JsonRpcMethodNotFoundException.h>

namespace Flix {

JsonRpcMethodNotFoundException::JsonRpcMethodNotFoundException(const std::string& what):
    std::logic_error(what)
{
}

JsonRpcMethodNotFoundException::~JsonRpcMethodNotFoundException()
{
}

} /* namespace Flix */

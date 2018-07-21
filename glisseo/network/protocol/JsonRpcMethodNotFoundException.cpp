#include <glisseo/network/protocol/JsonRpcMethodNotFoundException.h>

namespace Glisseo {

JsonRpcMethodNotFoundException::JsonRpcMethodNotFoundException(const std::string& what):
    std::logic_error(what)
{
}

} /* namespace Glisseo */

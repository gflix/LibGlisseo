#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_

#include <stdexcept>

namespace Glisseo {

/// Exception which expresses that a JSON-RPC call contained invalid parameters
class JsonRpcInvalidParamsException: public std::logic_error {
public:
    /// Initializes the exception with an error message
    JsonRpcInvalidParamsException(const std::string& what);
    virtual ~JsonRpcInvalidParamsException() = default;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_ */

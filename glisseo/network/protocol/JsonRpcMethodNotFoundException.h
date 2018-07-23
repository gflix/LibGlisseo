#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_

#include <stdexcept>

namespace Glisseo {

/// Expression which expresses that a called JSON-RPC method was not found
class JsonRpcMethodNotFoundException: public std::logic_error {
public:
    /// Initializes the exception with an error message
    JsonRpcMethodNotFoundException(const std::string& what);
    virtual ~JsonRpcMethodNotFoundException() = default;
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_ */

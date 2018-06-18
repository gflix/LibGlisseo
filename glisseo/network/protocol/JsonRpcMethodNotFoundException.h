#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_

#include <stdexcept>

namespace Glisseo {

class JsonRpcMethodNotFoundException: public std::logic_error {
public:
    JsonRpcMethodNotFoundException(const std::string& what);
    virtual ~JsonRpcMethodNotFoundException();
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_ */

#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_

#include <stdexcept>

namespace Flix {

class JsonRpcMethodNotFoundException: public std::logic_error {
public:
    JsonRpcMethodNotFoundException(const std::string& what);
    virtual ~JsonRpcMethodNotFoundException();
};

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCMETHODNOTFOUNDEXCEPTION_H_ */

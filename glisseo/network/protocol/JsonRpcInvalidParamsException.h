#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_

#include <stdexcept>

namespace Glisseo {

class JsonRpcInvalidParamsException: public std::logic_error {
public:
    JsonRpcInvalidParamsException(const std::string& what);
    virtual ~JsonRpcInvalidParamsException();
};

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_ */

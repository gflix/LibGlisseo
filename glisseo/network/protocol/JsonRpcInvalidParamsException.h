#ifndef GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_
#define GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_

#include <stdexcept>

namespace Flix {

class JsonRpcInvalidParamsException: public std::logic_error {
public:
    JsonRpcInvalidParamsException(const std::string& what);
    virtual ~JsonRpcInvalidParamsException();
};

} /* namespace Flix */

#endif /* GLISSEO_NETWORK_PROTOCOL_JSONRPCINVALIDPARAMSEXCEPTION_H_ */

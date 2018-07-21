#ifndef NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_
#define NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_

#include <string>

namespace Glisseo {

class TelnetServerConnection;

class GenericTelnetService {
public:
    GenericTelnetService(void);
    virtual ~GenericTelnetService() = default;

    virtual void processLine(const std::string& line, TelnetServerConnection& connection);
};

} /* namespace Glisseo */

#endif /* NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_ */

#ifndef NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_
#define NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_

#include <string>

namespace Glisseo {

class TelnetServerConnection;

/// Basic class for a telnet service
class GenericTelnetService {
public:
    GenericTelnetService(void);
    virtual ~GenericTelnetService() = default;

    /// Process a received line from a telnet connection
    virtual void processLine(const std::string& line, TelnetServerConnection& connection);
};

} /* namespace Glisseo */

#endif /* NETWORKING_PROTOCOL_GENERICTELNETSERVICE_H_ */

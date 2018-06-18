#ifndef NETWORKING_SERIAL_BAUDRATE_H_
#define NETWORKING_SERIAL_BAUDRATE_H_

#include <string>

namespace Glisseo {

enum class Baudrate {
    RATE_38400,
};

Baudrate identifierToBaudrate(std::string& identifier);
Baudrate intToBaudrate(int baudrate);
int baudrateToInt(Baudrate baudrate);

} /* namespace Glisseo */

#endif /* NETWORKING_SERIAL_BAUDRATE_H_ */

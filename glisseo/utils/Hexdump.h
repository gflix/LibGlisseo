#ifndef GLISSEO_UTILS_HEXDUMP_H_
#define GLISSEO_UTILS_HEXDUMP_H_

#include <ostream>

namespace Glisseo {

void hexdump(std::ostream& stream, const std::string& data, unsigned int addressOffset = 0);

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_HEXDUMP_H_ */

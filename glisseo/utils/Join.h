#ifndef GLISSEO_UTILS_JOIN_H_
#define GLISSEO_UTILS_JOIN_H_

#include <string>
#include <vector>

namespace Glisseo {

std::string join(std::vector<std::string> strings, const std::string& separator = ",");

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_JOIN_H_ */

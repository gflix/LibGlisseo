#ifndef GLISSEO_UTILS_STRING_H_
#define GLISSEO_UTILS_STRING_H_

#include <string>

namespace Glisseo {

bool beginsWith(const std::string& haystack, const std::string& needle);
bool endsWith(const std::string& haystack, const std::string& needle);

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_STRING_H_ */

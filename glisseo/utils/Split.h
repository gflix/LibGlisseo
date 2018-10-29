#ifndef GLISSEO_UTILS_SPLIT_H_
#define GLISSEO_UTILS_SPLIT_H_

#include <string>
#include <vector>

namespace Glisseo {

std::vector<std::string> split(
    std::string joinedString,
    const std::string& separator,
    bool trim = false,
    bool skipEmpty = true);
void splitHostPort(
    const std::string& peer,
    int defaultPort,
    std::string& host,
    int& port);

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_SPLIT_H_ */

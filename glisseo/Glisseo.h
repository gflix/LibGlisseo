#ifndef GLISSEO_GLISSEO_H_
#define GLISSEO_GLISSEO_H_

#include <string>

namespace Glisseo {

/// Dummy class to retrieve meta information from the library
class Glisseo {
public:
    /// Returns the package version information from the library
    static std::string getPackageInfo(void);
};

} /* namespace Glisseo */

#endif /* GLISSEO_GLISSEO_H_ */

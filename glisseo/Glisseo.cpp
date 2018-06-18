#include <glisseo/Autoconf.h>
#include <glisseo/Glisseo.h>

#ifndef PACKAGE_STRING
#define PACKAGE_STRING "unknown"
#endif

namespace Glisseo {

std::string Glisseo::getPackageInfo(void)
{
    return { PACKAGE_STRING };
}

} /* namespace Glisseo */

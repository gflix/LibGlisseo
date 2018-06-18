#include <sstream>
#include <glisseo/network/protocol/NetstringEncoder.h>

namespace Glisseo {

std::string toNetstring(const std::string& text)
{
    std::stringstream stream;

    stream << text.size() << ":" << text << ",";

    return stream.str();
}

} /* namespace Glisseo */

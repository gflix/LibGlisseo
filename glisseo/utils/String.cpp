#include <glisseo/utils/String.h>

namespace Glisseo {

bool beginsWith(const std::string& haystack, const std::string& needle)
{
    if (haystack.size() < needle.size())
    {
        return false;
    }
    if (haystack.size() == needle.size())
    {
        return
            haystack == needle;
    }
    return
        haystack.substr(0, needle.size()) == needle;
}

bool endsWith(const std::string& haystack, const std::string& needle)
{
    if (haystack.size() < needle.size())
    {
        return false;
    }
    if (haystack.size() == needle.size())
    {
        return
            haystack == needle;
    }
    return
        haystack.substr(haystack.size() - needle.size()) == needle;
}

} /* namespace Glisseo */

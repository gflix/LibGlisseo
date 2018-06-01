#include <stdexcept>
#include <glisseo/utils/Trim.h>
#include <glisseo/utils/Split.h>

namespace Flix {

std::vector<std::string> split(std::string joinedString, const std::string& separator, bool trim, bool skipEmpty)
{
    if (separator.empty())
    {
        throw std::invalid_argument("empty separator");
    }
    if (joinedString.empty())
    {
        return {};
    }

    std::vector<std::string> strings;
    std::string::size_type position;
    while ((position = joinedString.find(separator)) != std::string::npos)
    {
        std::string element = joinedString.substr(0, position);
        joinedString.erase(0, position + separator.size());

        if (trim)
        {
            element = Flix::trim(element);
        }
        if (!element.empty() || !skipEmpty)
        {
            strings.push_back(element);
        }
    }

    if (trim)
    {
        joinedString = Flix::trim(joinedString);
    }
    if (!joinedString.empty() || !skipEmpty)
    {
        strings.push_back(joinedString);
    }

    return strings;
}

} /* namespace Flix */

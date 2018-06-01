#include <glisseo/utils/Join.h>

namespace Flix {

std::string join(std::vector<std::string> strings, const std::string& separator)
{
    std::string joinedStrings;

    bool firstElement = true;
    for (auto& element: strings)
    {
        if (!firstElement)
        {
            joinedStrings += separator;
        }

        joinedStrings += element;
        firstElement = false;
    }

    return joinedStrings;
}

} /* namespace Flix */

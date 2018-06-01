#include <glisseo/utils/Trim.h>

namespace Flix {

std::string trimLeft(const std::string& text)
{
    std::string::size_type position = text.find_first_not_of(" \n\r");
    if (position == std::string::npos)
    {
        return std::string();
    }

    return
        text.substr(position);
}

std::string trimRight(const std::string& text)
{
    std::string::size_type position = text.find_last_not_of(" \n\r");
    if (position == std::string::npos)
    {
        return std::string();
    }

    return
        text.substr(0, position + 1);
}

std::string trim(const std::string& text)
{
    return
        trimLeft(trimRight(text));
}

} /* namespace Flix */

#include <stdexcept>
#include <glisseo/utils/InvocationArgument.h>

namespace Flix {

InvocationArgument::InvocationArgument(
    const std::string& shortArgument,
    const std::string& longArgument,
    const std::string& helpText,
    const std::string& parameter,
    bool parameterIsRequired):
    shortArgument(shortArgument),
    longArgument(longArgument),
    helpText(helpText),
    argumentIsPresent(false),
    parameter(parameter),
    parameterIsRequired(parameterIsRequired)
{
    if (shortArgument.size() > 1)
    {
        throw std::invalid_argument("short argument shall be empty or one character long");
    }
    if (!longArgument.empty())
    {
        throw std::invalid_argument("long arguments are currently not supported");
    }
    if (shortArgument.empty() &&
        longArgument.empty())
    {
        throw std::invalid_argument("neither short nor long argument was given");
    }
    if (parameterIsRequired && parameter.empty())
    {
        throw std::invalid_argument("parameter must be given if required");
    }
}

} /* namespace Flix */

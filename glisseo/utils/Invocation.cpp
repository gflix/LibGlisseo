#include <glisseo/utils/Invocation.h>

namespace Flix {

Invocation::Invocation()
{
}

Invocation::~Invocation()
{
}

void Invocation::addArgument(
    const std::string& shortArgument,
    const std::string& longArgument,
    const std::string& helpText,
    const std::string& parameter,
    bool parameterIsRequired)
{
    InvocationArgument argument {
        shortArgument,
        longArgument,
        helpText,
        parameter,
        parameterIsRequired };

    arguments.push_back(argument);
}

void Invocation::setupRemainingArguments(
    const std::string& parameter,
    const std::string& helpText)
{
    remainingArgumentsParameter = parameter;
    remainingArgumentsHelpText = helpText;
}

void Invocation::printHelp(
    std::ostream& stream,
    const std::string& programName,
    const std::string& versionInformation) const
{
    int argumentWidth = 0;
    bool hasFlags = false;
    bool hasOptionalArguments = false;
    bool hasRequiredArguments = false;
    for (auto& argument: arguments)
    {
        if (argument.parameter.empty())
        {
            hasFlags = true;
            argumentWidth = max(argumentWidth,
                max(argument.shortArgument.size() + 1,
                    argument.longArgument.size() + 2));
        }
        else
        {
            argumentWidth = max(argumentWidth,
                max(argument.shortArgument.size() + 1,
                    argument.longArgument.size() + 2) + 1 +
                    argument.parameter.size());

            if (argument.parameterIsRequired)
            {
                hasRequiredArguments = true;
            }
            else
            {
                hasOptionalArguments = true;
            }
        }
    }

    stream << "USAGE: " << programName;
    if (hasFlags)
    {
        stream << " [FLAGS]";
    }
    if (hasOptionalArguments)
    {
        stream << " [ARGUMENTS]";
    }
    if (hasRequiredArguments)
    {
        stream << " ARGUMENTS";
    }
    if (!remainingArgumentsParameter.empty())
    {
        stream << " " << remainingArgumentsParameter;
    }
    stream << std::endl << std::endl;

    if (hasFlags)
    {
        stream << "Flags:" << std::endl;
        stream << std::endl;
    }
    if (hasOptionalArguments)
    {
        stream << "Optional arguments:" << std::endl;
        stream << std::endl;
    }
    if (hasRequiredArguments)
    {
        stream << "Required arguments:" << std::endl;
        stream << std::endl;
    }
    if (!versionInformation.empty())
    {
        stream << "Version information:" << std::endl;
        stream << "  " << versionInformation << std::endl;
        stream << std::endl;
    }
}

int Invocation::max(int a, int b) const
{
    return
        a > b ? a : b;
}

} /* namespace Flix */

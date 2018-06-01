#include <unistd.h>
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

const InvocationArgument& Invocation::getArgument(const std::string& argument) const
{
    for (auto& element: arguments)
    {
        if (element.shortArgument == argument ||
            element.longArgument == argument)
        {
            return element;
        }
    }

    throw std::invalid_argument("argument \"" + argument + "\" was not found");
}

void Invocation::setupRemainingArguments(
    const std::string& parameter,
    const std::string& helpText)
{
    remainingArgumentsParameter = parameter;
    remainingArgumentsHelpText = helpText;
}

const Arguments& Invocation::getRemainingArguments(void) const
{
    return remainingArguments;
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
        for (auto& argument: arguments)
        {
            if (argument.parameter.empty())
            {
                stream << "  ";
                if (!argument.shortArgument.empty())
                    stream << "-" << argument.shortArgument;
                if (!argument.shortArgument.empty() && !argument.longArgument.empty())
                    stream << ", ";
                if (!argument.longArgument.empty())
                    stream << "--" << argument.longArgument;

                stream << "  " << argument.helpText << std::endl;
            }
        }
        stream << std::endl;
    }
    if (hasOptionalArguments)
    {
        stream << "Optional arguments:" << std::endl;
        for (auto& argument: arguments)
        {
            if (!argument.parameter.empty() && !argument.parameterIsRequired)
            {
                stream << "  ";
                if (!argument.shortArgument.empty())
                    stream << "-" << argument.shortArgument;
                if (!argument.shortArgument.empty() && !argument.longArgument.empty())
                    stream << ", ";
                if (!argument.longArgument.empty())
                    stream << "--" << argument.longArgument;

                stream << " " << argument.parameter << "  " << argument.helpText << std::endl;
            }
        }
        stream << std::endl;
    }
    if (hasRequiredArguments)
    {
        stream << "Required arguments:" << std::endl;
        for (auto& argument: arguments)
        {
            if (!argument.parameter.empty() && argument.parameterIsRequired)
            {
                stream << "  ";
                if (!argument.shortArgument.empty())
                    stream << "-" << argument.shortArgument;
                if (!argument.shortArgument.empty() && !argument.longArgument.empty())
                    stream << ", ";
                if (!argument.longArgument.empty())
                    stream << "--" << argument.longArgument;

                stream << " " << argument.parameter << "  " << argument.helpText << std::endl;
            }
        }
        stream << std::endl;
    }
    if (!remainingArgumentsParameter.empty())
    {
        stream << "Remaining arguments:" << std::endl;
        stream << "  " << remainingArgumentsParameter << "  " << remainingArgumentsHelpText << std::endl;
        stream << std::endl;
    }
    if (!versionInformation.empty())
    {
        stream << "Version information:" << std::endl;
        stream << "  " << versionInformation << std::endl;
        stream << std::endl;
    }
}

std::string Invocation::getGetOptString(void) const
{
    std::string getOptString;

    for (auto& argument: arguments)
    {
        if (!argument.shortArgument.empty())
        {
            getOptString += argument.shortArgument;
            if (!argument.parameter.empty())
            {
                getOptString += ':';
            }
        }
    }

    return getOptString;
}

void Invocation::evaluate(int argc, char* const argv[])
{
    if (argc < 1)
    {
        throw std::invalid_argument("must provide at least one argument");
    }
    for (auto i = 0; i < argc; ++i)
    {
        if (!argv[i])
        {
            throw std::invalid_argument("invalid argument at position " + std::to_string(i));
        }
    }

    optind = 1;

    std::string getOptString = getGetOptString();
    int opt;
    while ((opt = getopt(argc, argv, getOptString.c_str())) != -1)
    {
        std::string optString = std::string(1, opt);

        bool foundArgument = false;
        for (auto& argument: arguments)
        {
            if (optString != argument.shortArgument)
            {
                continue;
            }

            foundArgument = true;
            argument.argumentIsPresent = true;
            if (!argument.parameter.empty())
            {
                argument.parameterValue = optarg;
            }
            break;
        }

        if (!foundArgument)
        {
            throw std::invalid_argument("argument \"-" + optString + "\" is not allowed");
        }
    }

    for (auto& argument: arguments)
    {
        if (argument.parameterIsRequired && argument.parameterValue.empty())
        {
            throw std::invalid_argument("argument \"-" + argument.shortArgument + "\" is required but was not found");
        }
    }

    for (auto i = optind; i < argc; ++i)
    {
        remainingArguments.push_back(argv[i]);
    }
}

int Invocation::max(int a, int b) const
{
    return
        a > b ? a : b;
}

} /* namespace Flix */

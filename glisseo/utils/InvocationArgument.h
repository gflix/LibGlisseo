#ifndef GLISSEO_UTILS_INVOCATIONARGUMENT_H_
#define GLISSEO_UTILS_INVOCATIONARGUMENT_H_

#include <string>
#include <vector>

namespace Glisseo {

/// Structure which keeps the information about one command line argument
struct InvocationArgument {
    /// Initializes the structure with the given arguments
    InvocationArgument(
        const std::string& shortArgument,
        const std::string& longArgument,
        const std::string& helpText,
        const std::string& parameter = std::string(),
        bool parameterIsRequired = false);

    /// Short argument identifier, i.e. '-a'
    std::string shortArgument;
    /// Long argument identifier, i.e. '--alt', currently not supported
    std::string longArgument;
    /// Text which is printed as the help text
    std::string helpText;

    /// True if the argument was present on last evaluate() call
    bool argumentIsPresent;

    /// Argument placeholder if a value is expected (i.e. -a PLACEHOLDER), otherwise the argument is a flag
    std::string parameter;
    /// True if the argument is a required and needs a value
    bool parameterIsRequired;
    /// Value of the argument from last evaluate() call
    std::string parameterValue;
};

typedef std::vector<InvocationArgument> InvocationArguments;

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_INVOCATIONARGUMENT_H_ */

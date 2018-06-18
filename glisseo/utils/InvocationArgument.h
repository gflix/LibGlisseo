#ifndef GLISSEO_UTILS_INVOCATIONARGUMENT_H_
#define GLISSEO_UTILS_INVOCATIONARGUMENT_H_

#include <string>
#include <vector>

namespace Glisseo {

struct InvocationArgument {
    InvocationArgument(
        const std::string& shortArgument,
        const std::string& longArgument,
        const std::string& helpText,
        const std::string& parameter = std::string(),
        bool parameterIsRequired = false);

    std::string shortArgument;
    std::string longArgument;
    std::string helpText;

    bool argumentIsPresent;

    std::string parameter;
    bool parameterIsRequired;
    std::string parameterValue;
};

typedef std::vector<InvocationArgument> InvocationArguments;

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_INVOCATIONARGUMENT_H_ */

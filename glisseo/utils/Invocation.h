#ifndef GLISSEO_UTILS_INVOCATION_H_
#define GLISSEO_UTILS_INVOCATION_H_

#include <ostream>
#include <glisseo/utils/InvocationArgument.h>

namespace Glisseo {

typedef std::vector<std::string> Arguments;

class Invocation {
public:
    Invocation(void);
    virtual ~Invocation() = default;

    void addArgument(
        const std::string& shortArgument,
        const std::string& longArgument,
        const std::string& helpText,
        const std::string& parameter = std::string(),
        bool parameterIsRequired = false);
    const InvocationArgument& getArgument(const std::string& argument) const;

    void setupRemainingArguments(
        const std::string& parameter,
        const std::string& helpText);
    const Arguments& getRemainingArguments(void) const;

    void printHelp(
        std::ostream& stream,
        const std::string& programName,
        const std::string& versionInformation = std::string()) const;

    std::string getGetOptString(void) const;
    void evaluate(int argc, char* const argv[]);

private:
    InvocationArguments arguments;

    Arguments remainingArguments;
    std::string remainingArgumentsParameter;
    std::string remainingArgumentsHelpText;

    int max(int a, int b) const;
};

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_INVOCATION_H_ */

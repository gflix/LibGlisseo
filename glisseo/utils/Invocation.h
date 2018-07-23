#ifndef GLISSEO_UTILS_INVOCATION_H_
#define GLISSEO_UTILS_INVOCATION_H_

#include <ostream>
#include <glisseo/utils/InvocationArgument.h>

namespace Glisseo {

typedef std::vector<std::string> Arguments;

/// Wrapper around getopt()
class Invocation {
public:
    Invocation(void);
    virtual ~Invocation() = default;

    /// Add an command line argument with the given parameters
    void addArgument(
        const std::string& shortArgument,
        const std::string& longArgument,
        const std::string& helpText,
        const std::string& parameter = std::string(),
        bool parameterIsRequired = false);
    /// Retrieves the give argument and its state after calling evaluate()
    const InvocationArgument& getArgument(const std::string& argument) const;

    /// Sets information about the remaining arguments which are not covered by getopt() (i.e. FILES)
    void setupRemainingArguments(
        const std::string& parameter,
        const std::string& helpText);
    /// Retrieves a list of the remaining arguments after calling evaluate()
    const Arguments& getRemainingArguments(void) const;

    /// Prints the auto-generated help text to the given std::ostream
    void printHelp(
        std::ostream& stream,
        const std::string& programName,
        const std::string& versionInformation = std::string()) const;

    /// Retrieves the argument which is used to call getopt()
    std::string getGetOptString(void) const;
    /// Evaluate argc and argv according to the settings and update the invocation and remaining arguments
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

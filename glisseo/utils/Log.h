#ifndef SRC_MODELLBAHN_CONTROLLER_LOG_H_
#define SRC_MODELLBAHN_CONTROLLER_LOG_H_

#include <sstream>
#include <string>
#include <glisseo/utils/LogLevel.h>

namespace Glisseo {

/// Implementation of a logging mechanism which automatically selects whether to print to stdout or to the system log
class Log {
public:
    Log();
    /// Initializes the logging mechanism with a given log level
    explicit Log(LogLevel logLevel);
    virtual ~Log() = default;

    /// Print an error message
    void error(std::string logMessage) const;
    /// Print a warning message
    void warning(std::string logMessage) const;
    /// Print a noticeable message
    void notice(std::string logMessage) const;
    /// Print an informational message
    void info(std::string logMessage) const;
    /// Print a debug message
    void debug(std::string logMessage) const;

    /// Sets the minimum log level for the next log messages
    void setLogLevel(LogLevel logLevel);

    /// Singleton instance of the logging mechanism
    static Log instance;

private:
    bool toTty;
    LogLevel logLevel;

    std::string getTimestamp(void) const;
    void determineOutputMode(void);
};

#define LOG_ERROR(message) { \
    std::stringstream tempLogStream; tempLogStream << message; Glisseo::Log::instance.error(tempLogStream.str()); \
}
#define LOG_WARNING(message) { \
    std::stringstream tempLogStream; tempLogStream << message; Glisseo::Log::instance.warning(tempLogStream.str()); \
}
#define LOG_NOTICE(message) { \
    std::stringstream tempLogStream; tempLogStream << message; Glisseo::Log::instance.notice(tempLogStream.str()); \
}
#define LOG_INFO(message) { \
    std::stringstream tempLogStream; tempLogStream << message; Glisseo::Log::instance.info(tempLogStream.str()); \
}
#define LOG_DEBUG(message) { \
    std::stringstream tempLogStream; tempLogStream << message; Glisseo::Log::instance.debug(tempLogStream.str()); \
}

} /* namespace Glisseo */

#endif /* SRC_MODELLBAHN_CONTROLLER_LOG_H_ */

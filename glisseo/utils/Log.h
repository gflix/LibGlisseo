#ifndef SRC_MODELLBAHN_CONTROLLER_LOG_H_
#define SRC_MODELLBAHN_CONTROLLER_LOG_H_

#include <sstream>
#include <string>
#include <glisseo/utils/LogLevel.h>

namespace Glisseo {

class Log {
public:
    Log();
    Log(LogLevel logLevel);
    virtual ~Log() = default;

    void error(std::string logMessage) const;
    void warning(std::string logMessage) const;
    void notice(std::string logMessage) const;
    void info(std::string logMessage) const;
    void debug(std::string logMessage) const;

    void setLogLevel(LogLevel logLevel);

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

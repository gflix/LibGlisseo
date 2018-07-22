#ifndef GLISSEO_UTILS_TIMER_H_
#define GLISSEO_UTILS_TIMER_H_

#include <ctime>
#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo {

/// Installs a file descriptor based periodic timer which can be used within select()
class Timer: public GenericDescriptor {
public:
    Timer(void);
    /// Initializes a timer with a given time interval
    explicit Timer(const timespec& interval);
    virtual ~Timer();

    /// Starts the timer, optionally only once
    void start(bool once = false);
    /// Stops the timer
    void stop(void);
    /// Sets the timer interval, only possible if the timer is stopped
    void setInterval(const timespec& interval);
    /// True if the timer is currently running
    bool isRunning(void) const;

    /// Retrieves the number of expirations since last access, must be called when select() returns
    uint64_t getExpirationCount(void) const;

private:
    timespec interval;

    void checkInterval(void) const;
};

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_TIMER_H_ */

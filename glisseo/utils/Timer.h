#ifndef GLISSEO_UTILS_TIMER_H_
#define GLISSEO_UTILS_TIMER_H_

#include <ctime>
#include <glisseo/utils/GenericDescriptor.h>

namespace Glisseo {

class Timer: public GenericDescriptor {
public:
    Timer(void);
    explicit Timer(const timespec& interval);
    virtual ~Timer();

    void start(bool once = false);
    void stop(void);
    void setInterval(const timespec& interval);
    bool isRunning(void) const;

    uint64_t getExpirationCount(void) const;

private:
    timespec interval;

    void checkInterval(void) const;
};

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_TIMER_H_ */

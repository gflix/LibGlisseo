#include <unistd.h>
#include <sys/timerfd.h>
#include <cstring>
#include <stdexcept>
#include <glisseo/utils/Timer.h>

namespace Flix {

Timer::Timer():
    GenericDescriptor(),
    interval({0, 0})
{
}

Timer::Timer(const timespec& interval):
    GenericDescriptor(),
    interval(interval)
{
}

Timer::~Timer()
{
    stop();
}

void Timer::start(bool once)
{
    checkInterval();

    itimerspec timerSpec;
    bzero(&timerSpec, sizeof(timerSpec));

    timerSpec.it_value = interval;
    if (!once)
    {
        timerSpec.it_interval = interval;
    }

    descriptor = timerfd_create(CLOCK_MONOTONIC, 0);
    if (descriptor < 0)
    {
        throw std::runtime_error("timerfd_create() failed");
    }

    if (timerfd_settime(descriptor, 0, &timerSpec, nullptr) != 0)
    {
        throw std::runtime_error("timerfd_settime() failed");
    }
}

void Timer::stop(void)
{
    if (!isRunning())
    {
        return;
    }

    itimerspec timerSpec;
    bzero(&timerSpec, sizeof(timerSpec));

    timerfd_settime(descriptor, 0, &timerSpec, nullptr);

    close(descriptor);
    invalidateDescriptor();
}

void Timer::setInterval(const timespec& interval)
{
    if (isRunning())
    {
        throw std::runtime_error("timer was not stopped before setting a new interval");
    }

    this->interval = interval;
}

bool Timer::isRunning(void) const
{
    return
        descriptorIsValid();
}

void Timer::checkInterval(void) const
{
    if (interval.tv_sec <= 0 ||
        interval.tv_nsec <= 0)
    {
        throw std::out_of_range("invalid timer interval");
    }
}

} /* namespace Flix */

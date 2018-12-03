#include <stdexcept>
#include <glisseo/datetime/LocalTime.h>

namespace Glisseo {

LocalTime::LocalTime(int hour, int minutes, int seconds):
    hour(hour),
    minutes(minutes),
    seconds(seconds)
{
    checkValidity();
}

void LocalTime::checkValidity(void) const
{
    if (hour < LOCAL_TIME_HOUR_MIN ||
        hour > LOCAL_TIME_HOUR_MAX)
    {
        throw std::out_of_range("invalid hour " + std::to_string(hour) +
                                ", expecting " + std::to_string(LOCAL_TIME_HOUR_MIN) +
                                "-" + std::to_string(LOCAL_TIME_HOUR_MAX));
    }

    if (minutes < LOCAL_TIME_MINUTES_MIN ||
        minutes > LOCAL_TIME_MINUTES_MAX)
    {
        throw std::out_of_range("invalid minutes " + std::to_string(minutes) +
                                ", expecting " + std::to_string(LOCAL_TIME_MINUTES_MIN) +
                                "-" + std::to_string(LOCAL_TIME_MINUTES_MAX));
    }

    if (seconds < LOCAL_TIME_SECONDS_MIN ||
        seconds > LOCAL_TIME_SECONDS_MAX)
    {
        throw std::out_of_range("invalid seconds " + std::to_string(seconds) +
                                ", expecting " + std::to_string(LOCAL_TIME_SECONDS_MIN) +
                                "-" + std::to_string(LOCAL_TIME_SECONDS_MAX));
    }
}

} /* namespace Glisseo */

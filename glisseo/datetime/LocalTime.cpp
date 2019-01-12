#include <cstring>
#include <ctime>
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

LocalTime::LocalTime(const std::string& time)
{
    tm brokenDownTimestamp;
    bzero(&brokenDownTimestamp, sizeof(brokenDownTimestamp));

    if (time.empty())
    {
        throw std::invalid_argument("unable to parse empty local time");
    }

    char* lastProcessedCharacter = strptime(time.c_str(), "%T", &brokenDownTimestamp);
    if (lastProcessedCharacter &&
        *lastProcessedCharacter == '\0')
    {
        hour = brokenDownTimestamp.tm_hour;
        minutes = brokenDownTimestamp.tm_min;
        seconds = brokenDownTimestamp.tm_sec;
    }
    else
    {
        lastProcessedCharacter = strptime(time.c_str(), "%H:%M", &brokenDownTimestamp);
        if (!lastProcessedCharacter ||
            *lastProcessedCharacter != '\0')
        {
            throw std::invalid_argument("unable to parse local time \"" + time + "\"");
        }

        hour = brokenDownTimestamp.tm_hour;
        minutes = brokenDownTimestamp.tm_min;
        seconds = 0;
    }

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

std::string LocalTime::toString(bool withSeconds) const
{
    checkValidity();

    char buffer[64];
    bzero(buffer, sizeof(buffer));

    if (withSeconds)
    {
        snprintf(buffer, sizeof(buffer) - 1, "%02d:%02d:%02d", hour, minutes, seconds);
    }
    else
    {
        snprintf(buffer, sizeof(buffer) - 1, "%02d:%02d", hour, minutes);
    }

    return buffer;

}

} /* namespace Glisseo */

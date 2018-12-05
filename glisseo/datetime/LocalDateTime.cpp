#include <cstring>
#include <ctime>
#include <stdexcept>
#include <glisseo/datetime/LocalDateTime.h>

namespace Glisseo {

LocalDateTime::LocalDateTime(int year, int month, int day, int hour, int minutes, int seconds):
    date(year, month, day),
    time(hour, minutes, seconds)
{
}

LocalDateTime::LocalDateTime(const std::string& iso8601)
{
    std::string::size_type tPosition = iso8601.find_first_of('T');

    if (tPosition == std::string::npos)
    {
        throw std::invalid_argument("expect ISO 8601 date/time format YYYY-MM-DDTHH:MM[:SS]");
    }

    date = LocalDate(iso8601.substr(0, tPosition));
    time = LocalTime(iso8601.substr(tPosition + 1));
}

LocalDateTime::LocalDateTime(const timespec& timestamp):
    LocalDateTime(timestamp.tv_sec)
{
}

LocalDateTime::LocalDateTime(time_t timestamp)
{
    tm brokenDownTimestamp;
    bzero(&brokenDownTimestamp, sizeof(brokenDownTimestamp));

    if (!localtime_r(&timestamp, &brokenDownTimestamp))
    {
        throw std::invalid_argument("invalid timestamp");
    }

    date = LocalDate(brokenDownTimestamp.tm_year + 1900,
                     brokenDownTimestamp.tm_mon + 1,
                     brokenDownTimestamp.tm_mday);
    time = LocalTime(brokenDownTimestamp.tm_hour,
                     brokenDownTimestamp.tm_min,
                     brokenDownTimestamp.tm_sec);
}

void LocalDateTime::checkValidity(void) const
{
    date.checkValidity();
    time.checkValidity();
}

std::string LocalDateTime::toString(void) const
{
    checkValidity();

    return date.toString() + "T" + time.toString();
}

timespec LocalDateTime::toTimestamp(void) const
{
    checkValidity();

    timespec timestamp;
    bzero(&timestamp, sizeof(timestamp));

    tm brokenDownTimestamp;
    bzero(&brokenDownTimestamp, sizeof(brokenDownTimestamp));

    brokenDownTimestamp.tm_year = date.year - 1900;
    brokenDownTimestamp.tm_mon = date.month - 1;
    brokenDownTimestamp.tm_mday = date.day;
    brokenDownTimestamp.tm_hour = time.hour;
    brokenDownTimestamp.tm_min = time.minutes;
    brokenDownTimestamp.tm_sec = time.seconds;
    // force usage of the local timezone
    brokenDownTimestamp.tm_isdst = -1;

    timestamp.tv_sec = mktime(&brokenDownTimestamp);

    if (timestamp.tv_sec < 0)
    {
        throw std::out_of_range("unable to calculate timestamp for the given date/time combination");
    }

    return timestamp;
}

} /* namespace Glisseo */

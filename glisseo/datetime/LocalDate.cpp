#include <cstring>
#include <ctime>
#include <stdexcept>
#include <glisseo/datetime/LocalDate.h>

namespace Glisseo {

LocalDate::LocalDate(int year, int month, int day):
    year(year),
    month(month),
    day(day)
{
    checkValidity();
}

LocalDate::LocalDate(const std::string& date)
{
    tm brokenDownTimestamp;
    bzero(&brokenDownTimestamp, sizeof(brokenDownTimestamp));

    char* lastProcessedCharacter = strptime(date.c_str(), "%F", &brokenDownTimestamp);
    if (date.empty() ||
        !lastProcessedCharacter ||
        *lastProcessedCharacter != '\0')
    {
        throw std::invalid_argument("unable to parse local date \"" + date + "\"");
    }

    year = brokenDownTimestamp.tm_year + 1900;
    month = brokenDownTimestamp.tm_mon + 1;
    day = brokenDownTimestamp.tm_mday;

    checkValidity();
}

void LocalDate::checkValidity(void) const
{
    if (year < LOCAL_DATE_YEAR_MIN ||
        year > LOCAL_DATE_YEAR_MAX)
    {
        throw std::out_of_range("invalid year " + std::to_string(year) +
                                ", expecting " + std::to_string(LOCAL_DATE_YEAR_MIN) +
                                "-" + std::to_string(LOCAL_DATE_YEAR_MAX));
    }

    if (month < LOCAL_DATE_MONTH_MIN ||
        month > LOCAL_DATE_MONTH_MAX)
    {
        throw std::out_of_range("invalid month " + std::to_string(month) +
                                ", expecting " + std::to_string(LOCAL_DATE_MONTH_MIN) +
                                "-" + std::to_string(LOCAL_DATE_MONTH_MAX));
    }

    int expected_max_days = LOCAL_DATE_DAY_MAX_LONG;
    if (month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11)
    {
        expected_max_days = LOCAL_DATE_DAY_MAX_SHORT;
    }
    else if (month == 2)
    {
        if (isLeapYear())
        {
            expected_max_days = LOCAL_DATE_DAY_MAX_FEB_LEAP_YEAR;
        }
        else
        {
            expected_max_days = LOCAL_DATE_DAY_MAX_FEB;
        }
    }

    if (day < LOCAL_DATE_DAY_MIN ||
        day > expected_max_days)
    {
        throw std::out_of_range("invalid day " + std::to_string(day) +
                                " for " + std::to_string(year) + "/" + std::to_string(month) +
                                ", expecting " + std::to_string(LOCAL_DATE_DAY_MIN) +
                                "-" + std::to_string(expected_max_days));
    }
}

bool LocalDate::isLeapYear(void) const
{
    if (year % 400 == 0)
    {
        return true;
    }
    if (year % 100 == 0)
    {
        return false;
    }
    if (year % 4 == 0)
    {
        return true;
    }
    return false;
}

std::string LocalDate::toString(void) const
{
    checkValidity();

    char buffer[64];
    bzero(buffer, sizeof(buffer));

    snprintf(buffer, sizeof(buffer) - 1, "%04d-%02d-%02d", year, month, day);

    return buffer;
}

Weekday LocalDate::weekday(void) const
{
    checkValidity();

    tm brokenDownTimestamp;
    bzero(&brokenDownTimestamp, sizeof(brokenDownTimestamp));

    brokenDownTimestamp.tm_year = year - 1900;
    brokenDownTimestamp.tm_mon = month - 1;
    brokenDownTimestamp.tm_mday = day;

    if (mktime(&brokenDownTimestamp) < 0)
    {
        throw std::out_of_range("unable to calculate weekday for the given date/time combination");
    }

    return static_cast<Weekday>(brokenDownTimestamp.tm_wday);
}

} /* namespace Glisseo */

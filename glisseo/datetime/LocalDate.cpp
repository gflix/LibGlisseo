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

} /* namespace Glisseo */

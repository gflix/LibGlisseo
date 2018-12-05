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

} /* namespace Glisseo */

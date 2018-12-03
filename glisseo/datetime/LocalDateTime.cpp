#include <glisseo/datetime/LocalDateTime.h>

namespace Glisseo {

LocalDateTime::LocalDateTime(int year, int month, int day, int hour, int minutes, int seconds):
    date(year, month, day),
    time(hour, minutes, seconds)
{
}

void LocalDateTime::checkValidity(void) const
{
    date.checkValidity();
    time.checkValidity();
}

} /* namespace Glisseo */

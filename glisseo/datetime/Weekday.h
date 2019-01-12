#ifndef GLISSEO_DATETIME_WEEKDAY_H_
#define GLISSEO_DATETIME_WEEKDAY_H_

#include <set>
#include <string>

namespace Glisseo {

enum class Weekday {
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
};

typedef std::set<Weekday> Weekdays;

Weekday identifierToWeekday(const std::string& identifier);
std::string weekdayToIdentifier(Weekday weekday);
std::string weekdayToIdentifierThreeLetters(Weekday weekday);
std::string weekdayToIdentifierTwoLetters(Weekday weekday);
Weekdays identifiersToWeekdays(const std::string& identifiers);

} /* namespace Glisseo */

#endif /* GLISSEO_DATETIME_WEEKDAY_H_ */

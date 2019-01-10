#include <glisseo/utils/EnumMapper.h>
#include <glisseo/utils/Split.h>
#include <glisseo/datetime/Weekday.h>

namespace Glisseo {

std::map<std::string, Weekday> weekdays = {
    { "Sunday", Weekday::SUNDAY },
    { "Monday", Weekday::MONDAY },
    { "Tuesday", Weekday::TUESDAY },
    { "Wednesday", Weekday::WEDNESDAY },
    { "Thursday", Weekday::THURSDAY },
    { "Friday", Weekday::FRIDAY },
    { "Saturday", Weekday::SATURDAY },
};

std::map<std::string, Weekday> weekdaysThreeLetters = {
    { "Sun", Weekday::SUNDAY },
    { "Mon", Weekday::MONDAY },
    { "Tue", Weekday::TUESDAY },
    { "Wed", Weekday::WEDNESDAY },
    { "Thu", Weekday::THURSDAY },
    { "Fri", Weekday::FRIDAY },
    { "Sat", Weekday::SATURDAY },
};

std::map<std::string, Weekday> weekdaysTwoLetters = {
    { "Su", Weekday::SUNDAY },
    { "Mo", Weekday::MONDAY },
    { "Tu", Weekday::TUESDAY },
    { "We", Weekday::WEDNESDAY },
    { "Th", Weekday::THURSDAY },
    { "Fr", Weekday::FRIDAY },
    { "Sa", Weekday::SATURDAY },
};

Weekday identifierToWeekday(const std::string& identifier)
{
    try
    {
        return identifierToEnum(weekdays, identifier);
    }
    catch (std::out_of_range&)
    {
        try
        {
            return identifierToEnum(weekdaysThreeLetters, identifier);
        }
        catch (std::out_of_range&)
        {
            return identifierToEnum(weekdaysTwoLetters, identifier);
        }
    }
}

std::string weekdayToIdentifier(Weekday weekday)
{
    return enumToIdentifier(weekdays, weekday);
}

std::string weekdayToIdentifierThreeLetters(Weekday weekday)
{
    return enumToIdentifier(weekdaysThreeLetters, weekday);
}

std::string weekdayToIdentifierTwoLetters(Weekday weekday)
{
    return enumToIdentifier(weekdaysTwoLetters, weekday);
}

Weekdays identifiersToWeekdays(const std::string& identifiers)
{
    Weekdays weekdays;

    for (const auto& identifier: split(identifiers, ",", true, true))
    {
        weekdays.insert(identifierToWeekday(identifier));
    }

    return weekdays;
}

} /* namespace Glisseo */

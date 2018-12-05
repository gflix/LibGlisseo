#ifndef GLISSEO_DATETIME_LOCALDATETIME_H_
#define GLISSEO_DATETIME_LOCALDATETIME_H_

#include <glisseo/datetime/LocalDate.h>
#include <glisseo/datetime/LocalTime.h>

namespace Glisseo {

struct LocalDateTime {
    LocalDateTime(int year = LOCAL_DATE_YEAR_DEFAULT,
                  int month = LOCAL_DATE_MONTH_DEFAULT,
                  int day = LOCAL_DATE_DAY_DEFAULT,
                  int hour = LOCAL_TIME_HOUR_DEFAULT,
                  int minutes = LOCAL_TIME_MINUTES_DEFAULT,
                  int seconds = LOCAL_TIME_SECONDS_DEFAULT);
    LocalDateTime(const std::string& iso8601);
    virtual ~LocalDateTime() = default;

    void checkValidity(void) const;

    LocalDate date;
    LocalTime time;
};

} /* namespace Glisseo */

#endif /* GLISSEO_DATETIME_LOCALDATETIME_H_ */

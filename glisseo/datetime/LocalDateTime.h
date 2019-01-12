#ifndef GLISSEO_DATETIME_LOCALDATETIME_H_
#define GLISSEO_DATETIME_LOCALDATETIME_H_

#include <ctime>
#include <glisseo/datetime/LocalDate.h>
#include <glisseo/datetime/LocalTime.h>

namespace Glisseo {

struct LocalDateTime {
    LocalDateTime(int year,
                  int month,
                  int day,
                  int hour = LOCAL_TIME_HOUR_DEFAULT,
                  int minutes = LOCAL_TIME_MINUTES_DEFAULT,
                  int seconds = LOCAL_TIME_SECONDS_DEFAULT);
    LocalDateTime(const std::string& iso8601);
    LocalDateTime(const timespec& timestamp);
    LocalDateTime(time_t timestamp);
    virtual ~LocalDateTime() = default;

    void checkValidity(void) const;

    std::string toString(void) const;
    timespec toTimestamp(void) const;

    LocalDate date;
    LocalTime time;
};

} /* namespace Glisseo */

#endif /* GLISSEO_DATETIME_LOCALDATETIME_H_ */

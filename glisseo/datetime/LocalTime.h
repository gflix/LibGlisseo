#ifndef GLISSEO_DATETIME_LOCALTIME_H_
#define GLISSEO_DATETIME_LOCALTIME_H_

#define LOCAL_TIME_HOUR_DEFAULT (0)
#define LOCAL_TIME_HOUR_MIN (0)
#define LOCAL_TIME_HOUR_MAX (23)
#define LOCAL_TIME_MINUTES_DEFAULT (0)
#define LOCAL_TIME_MINUTES_MIN (0)
#define LOCAL_TIME_MINUTES_MAX (59)
#define LOCAL_TIME_SECONDS_DEFAULT (0)
#define LOCAL_TIME_SECONDS_MIN (0)
#define LOCAL_TIME_SECONDS_MAX (59)

namespace Glisseo {

struct LocalTime {
    LocalTime(int hour = LOCAL_TIME_HOUR_DEFAULT,
              int minutes = LOCAL_TIME_MINUTES_DEFAULT,
              int seconds = LOCAL_TIME_SECONDS_DEFAULT);
    virtual ~LocalTime() = default;

    void checkValidity(void) const;

    int hour;
    int minutes;
    int seconds;
};

} /* namespace Glisseo */

#endif /* GLISSEO_DATETIME_LOCALTIME_H_ */

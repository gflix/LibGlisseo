#ifndef GLISSEO_DATETIME_LOCALDATE_H_
#define GLISSEO_DATETIME_LOCALDATE_H_

#define LOCAL_DATE_YEAR_DEFAULT (1970)
#define LOCAL_DATE_YEAR_MIN (1970)
#define LOCAL_DATE_YEAR_MAX (2037)
#define LOCAL_DATE_MONTH_DEFAULT (1)
#define LOCAL_DATE_MONTH_MIN (1)
#define LOCAL_DATE_MONTH_MAX (12)
#define LOCAL_DATE_DAY_DEFAULT (1)
#define LOCAL_DATE_DAY_MIN (1)
#define LOCAL_DATE_DAY_MAX_FEB (28)
#define LOCAL_DATE_DAY_MAX_FEB_LEAP_YEAR (29)
#define LOCAL_DATE_DAY_MAX_SHORT (30)
#define LOCAL_DATE_DAY_MAX_LONG (31)

namespace Glisseo {

struct LocalDate {
    LocalDate(int year = LOCAL_DATE_YEAR_DEFAULT,
              int month = LOCAL_DATE_MONTH_DEFAULT,
              int day = LOCAL_DATE_DAY_DEFAULT);
    virtual ~LocalDate() = default;

    void checkValidity(void) const;
    bool isLeapYear(void) const;

    int year;
    int month;
    int day;
};

} /* namespace Glisseo */

#endif /* GLISSEO_DATETIME_LOCALDATE_H_ */

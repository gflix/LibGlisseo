#include <gtest/gtest.h>
#include <glisseo/datetime/LocalDate.h>
#include <glisseo/datetime/LocalDateTime.h>
#include <glisseo/datetime/LocalTime.h>

TEST(LocalDate, validDates)
{
    Glisseo::LocalDate dateA;
    Glisseo::LocalDate dateB(1970, 12);
    Glisseo::LocalDate dateC(2037, 1);
    Glisseo::LocalDate dateD(1970, 1, 1);
    Glisseo::LocalDate dateE(2037, 12, 31);
}

TEST(LocalDate, invalidYears)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1969), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(2038), std::out_of_range);
}

TEST(LocalDate, invalidMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 0), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 13), std::out_of_range);
}

TEST(LocalDate, invalidDays)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 4, 0), std::out_of_range);
}

TEST(LocalDate, validDaysShortMonths)
{
    Glisseo::LocalDate dateA(1984, 4, 30);
    Glisseo::LocalDate dateB(1984, 6, 30);
    Glisseo::LocalDate dateC(1984, 9, 30);
    Glisseo::LocalDate dateD(1984, 11, 30);
}

TEST(LocalDate, invalidDaysShortMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 4, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 6, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateC(1984, 9, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateD(1984, 11, 31), std::out_of_range);
}

TEST(LocalDate, validDaysLongMonths)
{
    Glisseo::LocalDate dateA(1984, 1, 31);
    Glisseo::LocalDate dateB(1984, 3, 31);
    Glisseo::LocalDate dateC(1984, 5, 31);
    Glisseo::LocalDate dateD(1984, 7, 31);
    Glisseo::LocalDate dateE(1984, 8, 31);
    Glisseo::LocalDate dateF(1984, 10, 31);
    Glisseo::LocalDate dateG(1984, 12, 31);
}

TEST(LocalDate, invalidDaysLongMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 1, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 3, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateC(1984, 5, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateD(1984, 7, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateE(1984, 8, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateF(1984, 10, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateG(1984, 12, 32), std::out_of_range);
}

TEST(LocalDate, invalidDaysFebruaryNoLeapYear)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1999, 2, 29), std::out_of_range);
}

TEST(LocalDate, validDaysFebruaryLeapYear)
{
    Glisseo::LocalDate dateA(2000, 2, 29);
}

TEST(LocalDate, leapYears)
{
    Glisseo::LocalDate date;

    date.year = 2000;
    EXPECT_TRUE(date.isLeapYear());
    date.year = 2004;
    EXPECT_TRUE(date.isLeapYear());
}

TEST(LocalDate, noLeapYears)
{
    Glisseo::LocalDate date;

    date.year = 1999;
    EXPECT_FALSE(date.isLeapYear());
    date.year = 2100;
    EXPECT_FALSE(date.isLeapYear());
}

TEST(LocalDate, validFromString)
{
    Glisseo::LocalDate dateA("1990-10-3");
    Glisseo::LocalDate dateB("1990-7-1");

    EXPECT_EQ(dateA.year, 1990);
    EXPECT_EQ(dateA.month, 10);
    EXPECT_EQ(dateA.day, 3);
    EXPECT_EQ(dateB.year, 1990);
    EXPECT_EQ(dateB.month, 7);
    EXPECT_EQ(dateB.day, 1);
}

TEST(LocalDate, invalidFromString)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(""), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalDate dateB("1969-12-31"), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateC("1969-12-xx"), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalDate dateD("no valid date"), std::invalid_argument);
}

TEST(LocalDate, toString)
{
    std::string dateString("1984-02-29");
    Glisseo::LocalDate date(dateString);

    EXPECT_EQ(date.toString(), dateString);
}

TEST(LocalDate, weekday)
{
    Glisseo::LocalDate dateA("1990-10-03");
    Glisseo::LocalDate dateB("1989-11-09");

    EXPECT_EQ(dateA.weekday(), Glisseo::Weekday::WEDNESDAY);
    EXPECT_EQ(dateB.weekday(), Glisseo::Weekday::THURSDAY);
}

TEST(LocalTime, validTimes)
{
    Glisseo::LocalTime timeA;
    Glisseo::LocalTime timeB(0);
    Glisseo::LocalTime timeC(23, 0);
    Glisseo::LocalTime timeD(0, 0, 0);
    Glisseo::LocalTime timeE(23, 59, 59);
}

TEST(LocalTime, invalidTimes)
{
    EXPECT_THROW(Glisseo::LocalTime timeA(-1), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeB(24), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeC(0, -1), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeD(0, 60), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeE(0, 0, -1), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeF(0, 0, 60), std::out_of_range);
}

TEST(LocalTime, validFromString)
{
    Glisseo::LocalTime timeA("0:1:2");
    Glisseo::LocalTime timeB("23:59");

    EXPECT_EQ(timeA.hour, 0);
    EXPECT_EQ(timeA.minutes, 1);
    EXPECT_EQ(timeA.seconds, 2);
    EXPECT_EQ(timeB.hour, 23);
    EXPECT_EQ(timeB.minutes, 59);
    EXPECT_EQ(timeB.seconds, 0);
}

TEST(LocalTime, invalidFromString)
{
    EXPECT_THROW(Glisseo::LocalTime timeA(""), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalTime timeB("24:00:00"), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalTime timeB("23:00:60"), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalTime timeC("23:xx"), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalTime timeD("no valid date"), std::invalid_argument);
}

TEST(LocalTime, toStringWithSeconds)
{
    std::string timeString("15:23:17");
    Glisseo::LocalTime time(timeString);

    EXPECT_EQ(time.toString(), timeString);
    EXPECT_EQ(time.toString(true), timeString);
}

TEST(LocalTime, toStringWithoutSeconds)
{
    std::string timeString("09:30:59");
    Glisseo::LocalTime time(timeString);

    std::string timeStringExpected("09:30");

    EXPECT_EQ(time.toString(false), timeStringExpected);
}

TEST(LocalDateTime, validDateTimes)
{
    Glisseo::LocalDateTime dateTimeA(1989, 11, 9);
    Glisseo::LocalDateTime dateTimeB(1989, 11, 9, 19, 30, 0);
}

TEST(LocalDateTime, invalidDateTimes)
{
    EXPECT_THROW(Glisseo::LocalDateTime dateTimeA(1953, 6, 17), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDateTime dateTimeB(1990, 10, 3, 24, 0, 0), std::out_of_range);
}

TEST(LocalDateTime, validFromString)
{
    Glisseo::LocalDateTime dateTime("1989-11-09T18:30:45");

    EXPECT_EQ(dateTime.date.year, 1989);
    EXPECT_EQ(dateTime.date.month, 11);
    EXPECT_EQ(dateTime.date.day, 9);
    EXPECT_EQ(dateTime.time.hour, 18);
    EXPECT_EQ(dateTime.time.minutes, 30);
    EXPECT_EQ(dateTime.time.seconds, 45);
}

TEST(LocalDateTime, invalidFromString)
{
    EXPECT_THROW(Glisseo::LocalDateTime timeA(""), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalDateTime timeB("1989-11-09P18:30:45"), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalDateTime timeC("1989-11-09T"), std::invalid_argument);
    EXPECT_THROW(Glisseo::LocalDateTime timeD("T18:30:45"), std::invalid_argument);
}

TEST(LocalDateTime, convertTimestamps)
{
    time_t timestampA = 0;
    timespec timestampB { 1500000000, 1234 };

    // Perform both conversions at the same time as for local dates the result depends on the local timezone
    EXPECT_EQ(Glisseo::LocalDateTime(timestampA).toTimestamp().tv_sec, timestampA);
    timespec timestampResultB = Glisseo::LocalDateTime(timestampB).toTimestamp();
    EXPECT_EQ(timestampResultB.tv_sec, timestampB.tv_sec);
    EXPECT_EQ(timestampResultB.tv_nsec, 0);
}

TEST(LocalDateTime, toString)
{
    std::string iso8601String("1990-03-10T12:00:25");
    Glisseo::LocalDateTime dateTime(iso8601String);

    EXPECT_EQ(dateTime.toString(), iso8601String);
}

TEST(Weekday, validFromIdentifier)
{
    EXPECT_EQ(Glisseo::identifierToWeekday("Sunday"), Glisseo::Weekday::SUNDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Sun"), Glisseo::Weekday::SUNDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Su"), Glisseo::Weekday::SUNDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Monday"), Glisseo::Weekday::MONDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Mon"), Glisseo::Weekday::MONDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Mo"), Glisseo::Weekday::MONDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Tuesday"), Glisseo::Weekday::TUESDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Tue"), Glisseo::Weekday::TUESDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Tu"), Glisseo::Weekday::TUESDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Wednesday"), Glisseo::Weekday::WEDNESDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Wed"), Glisseo::Weekday::WEDNESDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("We"), Glisseo::Weekday::WEDNESDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Thursday"), Glisseo::Weekday::THURSDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Thu"), Glisseo::Weekday::THURSDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Th"), Glisseo::Weekday::THURSDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Friday"), Glisseo::Weekday::FRIDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Fri"), Glisseo::Weekday::FRIDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Fr"), Glisseo::Weekday::FRIDAY);

    EXPECT_EQ(Glisseo::identifierToWeekday("Saturday"), Glisseo::Weekday::SATURDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Sat"), Glisseo::Weekday::SATURDAY);
    EXPECT_EQ(Glisseo::identifierToWeekday("Sa"), Glisseo::Weekday::SATURDAY);
}

TEST(Weekday, invalidFromIdentifier)
{
    EXPECT_THROW(Glisseo::identifierToWeekday("Holiday"), std::out_of_range);
}

TEST(Weekday, toIdentifier)
{
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::SUNDAY), "Sunday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::MONDAY), "Monday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::TUESDAY), "Tuesday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::WEDNESDAY), "Wednesday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::THURSDAY), "Thursday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::FRIDAY), "Friday");
    EXPECT_EQ(Glisseo::weekdayToIdentifier(Glisseo::Weekday::SATURDAY), "Saturday");
}

TEST(Weekday, toIdentifierThreeLetters)
{
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::SUNDAY), "Sun");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::MONDAY), "Mon");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::TUESDAY), "Tue");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::WEDNESDAY), "Wed");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::THURSDAY), "Thu");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::FRIDAY), "Fri");
    EXPECT_EQ(Glisseo::weekdayToIdentifierThreeLetters(Glisseo::Weekday::SATURDAY), "Sat");
}

TEST(Weekday, toIdentifierTwoLetters)
{
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::SUNDAY), "Su");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::MONDAY), "Mo");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::TUESDAY), "Tu");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::WEDNESDAY), "We");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::THURSDAY), "Th");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::FRIDAY), "Fr");
    EXPECT_EQ(Glisseo::weekdayToIdentifierTwoLetters(Glisseo::Weekday::SATURDAY), "Sa");
}

TEST(Weekdays, validFromIdentifiers)
{
    std::string inputA("Monday,We,Thu,Saturday");
    Glisseo::Weekdays weekdaysExpectedA = {
        Glisseo::Weekday::MONDAY,
        Glisseo::Weekday::WEDNESDAY,
        Glisseo::Weekday::THURSDAY,
        Glisseo::Weekday::SATURDAY,
    };

    std::string inputB("Su,Sa,We,Th");
    Glisseo::Weekdays weekdaysExpectedB = {
        Glisseo::Weekday::WEDNESDAY,
        Glisseo::Weekday::THURSDAY,
        Glisseo::Weekday::SATURDAY,
        Glisseo::Weekday::SUNDAY,
    };

    EXPECT_EQ(Glisseo::identifiersToWeekdays(inputA), weekdaysExpectedA);
    EXPECT_EQ(Glisseo::identifiersToWeekdays(inputB), weekdaysExpectedB);
}

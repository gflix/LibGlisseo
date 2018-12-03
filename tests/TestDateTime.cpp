#include <gtest/gtest.h>
#include <glisseo/datetime/LocalDate.h>

TEST(DateTime, validDates)
{
    Glisseo::LocalDate dateA;
    Glisseo::LocalDate dateB { 1970, 1, 1 };
    Glisseo::LocalDate dateC { 2037, 12, 31 };
}

TEST(DateTime, invalidYears)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1969), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(2038), std::out_of_range);
}

TEST(DateTime, invalidMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 0), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 13), std::out_of_range);
}

TEST(DateTime, invalidDays)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 4, 0), std::out_of_range);
}

TEST(DateTime, validDaysShortMonths)
{
    Glisseo::LocalDate dateA(1984, 4, 30);
    Glisseo::LocalDate dateB(1984, 6, 30);
    Glisseo::LocalDate dateC(1984, 9, 30);
    Glisseo::LocalDate dateD(1984, 11, 30);
}

TEST(DateTime, invalidDaysShortMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 4, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 6, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateC(1984, 9, 31), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateD(1984, 11, 31), std::out_of_range);
}

TEST(DateTime, validDaysLongMonths)
{
    Glisseo::LocalDate dateA(1984, 1, 31);
    Glisseo::LocalDate dateB(1984, 3, 31);
    Glisseo::LocalDate dateC(1984, 5, 31);
    Glisseo::LocalDate dateD(1984, 7, 31);
    Glisseo::LocalDate dateE(1984, 8, 31);
    Glisseo::LocalDate dateF(1984, 10, 31);
    Glisseo::LocalDate dateG(1984, 12, 31);
}

TEST(DateTime, invalidDaysLongMonths)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1984, 1, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateB(1984, 3, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateC(1984, 5, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateD(1984, 7, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateE(1984, 8, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateF(1984, 10, 32), std::out_of_range);
    EXPECT_THROW(Glisseo::LocalDate dateG(1984, 12, 32), std::out_of_range);
}

TEST(DateTime, invalidDaysFebruaryNoLeapYear)
{
    EXPECT_THROW(Glisseo::LocalDate dateA(1999, 2, 29), std::out_of_range);
}

TEST(DateTime, validDaysFebruaryLeapYear)
{
    Glisseo::LocalDate dateA(2000, 2, 29);
}

TEST(DateTime, leapYears)
{
    Glisseo::LocalDate date;

    date.year = 2000;
    EXPECT_TRUE(date.isLeapYear());
    date.year = 2004;
    EXPECT_TRUE(date.isLeapYear());
}

TEST(DateTime, noLeapYears)
{
    Glisseo::LocalDate date;

    date.year = 1999;
    EXPECT_FALSE(date.isLeapYear());
    date.year = 2100;
    EXPECT_FALSE(date.isLeapYear());
}

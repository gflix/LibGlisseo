#include <gtest/gtest.h>
#include <glisseo/utils/Range.h>

TEST(Range, WithinRange)
{
    EXPECT_TRUE(Glisseo::withinRange(0, 0, 100));
    EXPECT_TRUE(Glisseo::withinRange(50, 0, 100));
    EXPECT_TRUE(Glisseo::withinRange(100, 0, 100));

    EXPECT_FALSE(Glisseo::withinRange(-1, 0, 100));
    EXPECT_FALSE(Glisseo::withinRange(101, 0, 100));
}

TEST(Range, RestrictToRange)
{
    EXPECT_EQ(Glisseo::restrictToRange(0, 0,100), 0);
    EXPECT_EQ(Glisseo::restrictToRange(1, 0,100), 1);
    EXPECT_EQ(Glisseo::restrictToRange(99, 0,100), 99);
    EXPECT_EQ(Glisseo::restrictToRange(100, 0,100), 100);

    EXPECT_EQ(Glisseo::restrictToRange(-1, 0,100), 0);
    EXPECT_EQ(Glisseo::restrictToRange(101, 0,100), 100);
}

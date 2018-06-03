#include <gtest/gtest.h>
#include <glisseo/utils/Range.h>

TEST(Range, WithinRange)
{
    EXPECT_TRUE(Flix::withinRange(0, 0, 100));
    EXPECT_TRUE(Flix::withinRange(50, 0, 100));
    EXPECT_TRUE(Flix::withinRange(100, 0, 100));

    EXPECT_FALSE(Flix::withinRange(-1, 0, 100));
    EXPECT_FALSE(Flix::withinRange(101, 0, 100));
}

TEST(Range, RestrictToRange)
{
    EXPECT_EQ(Flix::restrictToRange(0, 0,100), 0);
    EXPECT_EQ(Flix::restrictToRange(1, 0,100), 1);
    EXPECT_EQ(Flix::restrictToRange(99, 0,100), 99);
    EXPECT_EQ(Flix::restrictToRange(100, 0,100), 100);

    EXPECT_EQ(Flix::restrictToRange(-1, 0,100), 0);
    EXPECT_EQ(Flix::restrictToRange(101, 0,100), 100);
}

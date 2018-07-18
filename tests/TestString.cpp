#include <gtest/gtest.h>
#include <glisseo/utils/String.h>

TEST(String, BeginsWithTrue)
{
    std::string haystack { "ABC" };
    std::string needleA { "" };
    std::string needleB { "A" };
    std::string needleC { "AB" };
    std::string needleD { "ABC" };

    EXPECT_TRUE(Glisseo::beginsWith(haystack, needleA));
    EXPECT_TRUE(Glisseo::beginsWith(haystack, needleB));
    EXPECT_TRUE(Glisseo::beginsWith(haystack, needleC));
    EXPECT_TRUE(Glisseo::beginsWith(haystack, needleD));
}

TEST(String, BeginsWithFalse)
{
    std::string haystack { "ABC" };
    std::string needleA { "B" };
    std::string needleB { "C" };
    std::string needleC { "ABCD" };

    EXPECT_FALSE(Glisseo::beginsWith(haystack, needleA));
    EXPECT_FALSE(Glisseo::beginsWith(haystack, needleB));
    EXPECT_FALSE(Glisseo::beginsWith(haystack, needleC));
}

TEST(String, EndsWithTrue)
{
    std::string haystack { "ABC" };
    std::string needleA { "" };
    std::string needleB { "C" };
    std::string needleC { "BC" };
    std::string needleD { "ABC" };

    EXPECT_TRUE(Glisseo::endsWith(haystack, needleA));
    EXPECT_TRUE(Glisseo::endsWith(haystack, needleB));
    EXPECT_TRUE(Glisseo::endsWith(haystack, needleC));
    EXPECT_TRUE(Glisseo::endsWith(haystack, needleD));
}

TEST(String, EndsWithFalse)
{
    std::string haystack { "ABC" };
    std::string needleA { "A" };
    std::string needleB { "B" };
    std::string needleC { "ABCD" };

    EXPECT_FALSE(Glisseo::endsWith(haystack, needleA));
    EXPECT_FALSE(Glisseo::endsWith(haystack, needleB));
    EXPECT_FALSE(Glisseo::endsWith(haystack, needleC));
}

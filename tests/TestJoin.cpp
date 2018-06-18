#include <gtest/gtest.h>
#include <glisseo/utils/Join.h>

TEST(Join, JoinDefaultSeparator)
{
    std::vector<std::string> input;
    std::string expectedA;
    std::string expectedB { "A" };
    std::string expectedC { "A,B" };
    std::string expectedD { "A,B,C" };

    EXPECT_EQ(Glisseo::join(input), expectedA);
    input.push_back("A");
    EXPECT_EQ(Glisseo::join(input), expectedB);
    input.push_back("B");
    EXPECT_EQ(Glisseo::join(input), expectedC);
    input.push_back("C");
    EXPECT_EQ(Glisseo::join(input), expectedD);
}

TEST(Join, JoinCustomSeparators)
{
    std::vector<std::string> input;
    std::string expectedA { "A:B:C" };
    std::string expectedB { "A / B / C" };
    std::string expectedC { "A, B, C" };

    input.push_back("A");
    input.push_back("B");
    input.push_back("C");

    EXPECT_EQ(Glisseo::join(input, ":"), expectedA);
    EXPECT_EQ(Glisseo::join(input, " / "), expectedB);
    EXPECT_EQ(Glisseo::join(input, ", "), expectedC);
}

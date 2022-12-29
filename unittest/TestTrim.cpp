#include <gtest/gtest.h>
#include <glisseo/utils/Trim.h>

TEST(Trim, TrimLeft)
{
    std::string inputA { "ABC" };
    std::string inputB { "ABC \r\n" };
    std::string inputC { "\n\r ABC \r\n" };
    std::string expectedC { "ABC \r\n" };
    std::string inputD { "\n\r A\nB\rC D \r\n" };
    std::string expectedD { "A\nB\rC D \r\n" };

    EXPECT_EQ(Glisseo::trimLeft(inputA), inputA);
    EXPECT_EQ(Glisseo::trimLeft(inputB), inputB);
    EXPECT_EQ(Glisseo::trimLeft(inputC), expectedC);
    EXPECT_EQ(Glisseo::trimLeft(inputD), expectedD);
}

TEST(Trim, TrimRight)
{
    std::string inputA { "ABC" };
    std::string inputB { " \r\nABC" };
    std::string inputC { "\n\r ABC \r\n" };
    std::string expectedC { "\n\r ABC" };
    std::string inputD { "\n\r A\nB\rC D \r\n" };
    std::string expectedD { "\n\r A\nB\rC D" };

    EXPECT_EQ(Glisseo::trimRight(inputA), inputA);
    EXPECT_EQ(Glisseo::trimRight(inputB), inputB);
    EXPECT_EQ(Glisseo::trimRight(inputC), expectedC);
    EXPECT_EQ(Glisseo::trimRight(inputD), expectedD);
}

TEST(Trim, Trim)
{
    std::string inputA { "ABC" };
    std::string inputB { "\n\r A\nB\rC D \r\n" };
    std::string expectedB { "A\nB\rC D" };

    EXPECT_EQ(Glisseo::trim(inputA), inputA);
    EXPECT_EQ(Glisseo::trim(inputB), expectedB);
}

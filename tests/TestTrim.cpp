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

    EXPECT_EQ(Flix::trimLeft(inputA), inputA);
    EXPECT_EQ(Flix::trimLeft(inputB), inputB);
    EXPECT_EQ(Flix::trimLeft(inputC), expectedC);
    EXPECT_EQ(Flix::trimLeft(inputD), expectedD);
}

TEST(Trim, TrimRight)
{
    std::string inputA { "ABC" };
    std::string inputB { " \r\nABC" };
    std::string inputC { "\n\r ABC \r\n" };
    std::string expectedC { "\n\r ABC" };
    std::string inputD { "\n\r A\nB\rC D \r\n" };
    std::string expectedD { "\n\r A\nB\rC D" };

    EXPECT_EQ(Flix::trimRight(inputA), inputA);
    EXPECT_EQ(Flix::trimRight(inputB), inputB);
    EXPECT_EQ(Flix::trimRight(inputC), expectedC);
    EXPECT_EQ(Flix::trimRight(inputD), expectedD);
}

TEST(Trim, Trim)
{
    std::string inputA { "ABC" };
    std::string inputB { "\n\r A\nB\rC D \r\n" };
    std::string expectedB { "A\nB\rC D" };

    EXPECT_EQ(Flix::trim(inputA), inputA);
    EXPECT_EQ(Flix::trim(inputB), expectedB);
}

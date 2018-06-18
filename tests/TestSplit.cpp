#include <gtest/gtest.h>
#include <glisseo/utils/Split.h>

TEST(Split, SplitThrow)
{
    EXPECT_ANY_THROW(Glisseo::split(std::string(), std::string()));
}

TEST(Split, Split)
{
    std::string inputA;
    std::vector<std::string> expectedA;

    std::string inputB { "A" };
    std::vector<std::string> expectedB;
    expectedB.push_back("A");

    std::string inputC { "A,B" };
    std::vector<std::string> expectedC;
    expectedC.push_back("A");
    expectedC.push_back("B");

    std::string inputD { " AAA, BBB ,CCC " };
    std::vector<std::string> expectedD;
    expectedD.push_back(" AAA");
    expectedD.push_back(" BBB ");
    expectedD.push_back("CCC ");

    EXPECT_EQ(Glisseo::split(inputA, ","), expectedA);
    EXPECT_EQ(Glisseo::split(inputB, ","), expectedB);
    EXPECT_EQ(Glisseo::split(inputC, ","), expectedC);
    EXPECT_EQ(Glisseo::split(inputD, ","), expectedD);
}

TEST(Split, SplitWithTrim)
{
    std::string inputA { " AAA, BBB ,CCC " };
    std::vector<std::string> expectedA;
    expectedA.push_back("AAA");
    expectedA.push_back("BBB");
    expectedA.push_back("CCC");

    EXPECT_EQ(Glisseo::split(inputA, ",", true), expectedA);
}

TEST(Split, SplitWithEmptyElements)
{
    std::string inputA { " AAA, BBB ,,CCC " };
    std::vector<std::string> expectedA;
    expectedA.push_back(" AAA");
    expectedA.push_back(" BBB ");
    expectedA.push_back(std::string());
    expectedA.push_back("CCC ");

    std::string inputB { ",, AAA, ,BBB ,,CCC ,," };
    std::vector<std::string> expectedB;
    expectedB.push_back(std::string());
    expectedB.push_back(std::string());
    expectedB.push_back(" AAA");
    expectedB.push_back(" ");
    expectedB.push_back("BBB ");
    expectedB.push_back(std::string());
    expectedB.push_back("CCC ");
    expectedB.push_back(std::string());
    expectedB.push_back(std::string());

    EXPECT_EQ(Glisseo::split(inputB, ",", false, false), expectedB);
}

TEST(Split, SplitDifferentSeparators)
{
    std::string inputA { "AAA, BBB, CCC" };
    std::vector<std::string> expectedA;
    expectedA.push_back("AAA");
    expectedA.push_back("BBB");
    expectedA.push_back("CCC");

    std::string inputB { "AAA / BBB / CCC" };
    std::string inputC { "AAA:BBB:CCC" };

    EXPECT_EQ(Glisseo::split(inputA, ", "), expectedA);
    EXPECT_EQ(Glisseo::split(inputB, ", "), std::vector<std::string>({ inputB }));
    EXPECT_EQ(Glisseo::split(inputB, " / "), expectedA);
    EXPECT_EQ(Glisseo::split(inputC, ":"), expectedA);
}

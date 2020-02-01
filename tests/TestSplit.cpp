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

TEST(Split, SplitPeerWithoutPort)
{
    std::string inputPeerA { "localhost" };
    int inputDefaultPortA = 4711;

    std::string expectedHostA { "localhost" };
    std::string hostA;
    int expectedPortA = 4711;
    int portA = 0;

    Glisseo::splitHostPort(inputPeerA, inputDefaultPortA, hostA, portA);

    EXPECT_EQ(hostA, expectedHostA);
    EXPECT_EQ(portA, expectedPortA);
}

TEST(Split, SplitPeerWithPort)
{
    std::string inputPeerA { "localhost:815" };
    int inputDefaultPortA = 4711;

    std::string expectedHostA { "localhost" };
    std::string hostA;
    int expectedPortA = 815;
    int portA = 0;

    Glisseo::splitHostPort(inputPeerA, inputDefaultPortA, hostA, portA);

    EXPECT_EQ(hostA, expectedHostA);
    EXPECT_EQ(portA, expectedPortA);
}

TEST(Split, SplitEmptyPeer)
{
    std::string inputPeerA;
    int inputDefaultPortA = 4711;

    std::string hostA;
    int portA = 0;

    EXPECT_THROW(Glisseo::splitHostPort(inputPeerA, inputDefaultPortA, hostA, portA), std::invalid_argument);
}

TEST(Split, SplitDefaultPortOutOfRange)
{
    std::string inputPeer { "localhost" };
    int inputDefaultPortA = 0;
    int inputDefaultPortB = 65536;

    std::string host;
    int port = 0;

    EXPECT_THROW(Glisseo::splitHostPort(inputPeer, inputDefaultPortA, host, port), std::out_of_range);
    EXPECT_THROW(Glisseo::splitHostPort(inputPeer, inputDefaultPortB, host, port), std::out_of_range);
}

TEST(Split, SplitEmptyHost)
{
    std::string inputPeerA { ":815" };
    int inputDefaultPortA = 4711;

    std::string hostA;
    int portA = 0;

    EXPECT_THROW(Glisseo::splitHostPort(inputPeerA, inputDefaultPortA, hostA, portA), std::invalid_argument);
}

TEST(Split, SplitPortOutOfRange)
{
    std::string inputPeerA { "localhost:0" };
    std::string inputPeerB { "localhost:65536" };
    int inputDefaultPort = 4711;

    std::string host;
    int port = 0;

    EXPECT_THROW(Glisseo::splitHostPort(inputPeerA, inputDefaultPort, host, port), std::out_of_range);
    EXPECT_THROW(Glisseo::splitHostPort(inputPeerB, inputDefaultPort, host, port), std::out_of_range);
}

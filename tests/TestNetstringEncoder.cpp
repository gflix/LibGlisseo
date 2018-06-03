#include <gtest/gtest.h>
#include <glisseo/network/protocol/NetstringEncoder.h>

TEST(NetstringEncoder, Encode)
{
    std::string inputA;
    std::string expectedA { "0:," };
    std::string inputB { "ABC" };
    std::string expectedB { "3:ABC," };

    EXPECT_EQ(Flix::toNetstring(inputA), expectedA);
    EXPECT_EQ(Flix::toNetstring(inputB), expectedB);
}

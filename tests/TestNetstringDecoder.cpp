#include <gtest/gtest.h>
#include <glisseo/network/protocol/NetstringDecoder.h>

TEST(NetstringDecoder, BufferHandling)
{
    Flix::NetstringDecoder decoder;

    EXPECT_EQ(decoder.getBuffer(), std::string());
    decoder.appendText("ABC");
    EXPECT_EQ(decoder.getBuffer(), "ABC");
    decoder.appendText("DEF");
    EXPECT_EQ(decoder.getBuffer(), "ABCDEF");
    decoder.resetBuffer();
    EXPECT_EQ(decoder.getBuffer(), std::string());
}

TEST(NetstringDecoder, CheckBuffer)
{
    Flix::NetstringDecoder decoder;

    EXPECT_NO_THROW(decoder.checkBuffer());
    decoder.appendText("ABC");
    EXPECT_NO_THROW(decoder.checkBuffer());
    decoder.appendText("DEF");
    EXPECT_ANY_THROW(decoder.checkBuffer());

    decoder.resetBuffer();
    decoder.appendText(":");
    EXPECT_ANY_THROW(decoder.checkBuffer());

    decoder.resetBuffer();
    decoder.appendText("ABC:");
    EXPECT_ANY_THROW(decoder.checkBuffer());

    decoder.resetBuffer();
    decoder.appendText("0:,");
    EXPECT_NO_THROW(decoder.checkBuffer());

    decoder.resetBuffer();
    decoder.appendText("2:ABC");
    EXPECT_ANY_THROW(decoder.checkBuffer());
}

TEST(NetstringDecoder, HasMessage)
{
    Flix::NetstringDecoder decoder;

    EXPECT_FALSE(decoder.hasMessage());

    decoder.appendText("0");
    EXPECT_FALSE(decoder.hasMessage());
    decoder.appendText(":");
    EXPECT_FALSE(decoder.hasMessage());
    decoder.appendText(",");
    EXPECT_TRUE(decoder.hasMessage());
    decoder.appendText("A");
    EXPECT_TRUE(decoder.hasMessage());
}

TEST(NetstringDecoder, GetMessage)
{
    Flix::NetstringDecoder decoder;

    EXPECT_ANY_THROW(decoder.getMessage());

    std::string inputA { "0:," };
    std::string expectedA;
    std::string inputB { "3:ABC," };
    std::string expectedB { "ABC" };
    std::string inputC { "3:ABC,4:DEFG," };
    std::string expectedC1 { "ABC" };
    std::string expectedC2 { "DEFG" };
    std::string inputD { "3:ABC,4:DEFG" };
    std::string expectedD1 { "ABC" };
    std::string expectedD2 { "4:DEFG" };

    decoder.appendText(inputA);
    EXPECT_EQ(decoder.getMessage(), expectedA);
    EXPECT_EQ(decoder.getBuffer(), std::string());

    decoder.appendText(inputB);
    EXPECT_EQ(decoder.getMessage(), expectedB);
    EXPECT_EQ(decoder.getBuffer(), std::string());

    decoder.appendText(inputC);
    EXPECT_EQ(decoder.getMessage(), expectedC1);
    EXPECT_EQ(decoder.getMessage(), expectedC2);
    EXPECT_EQ(decoder.getBuffer(), std::string());

    decoder.appendText(inputD);
    EXPECT_EQ(decoder.getMessage(), expectedD1);
    EXPECT_FALSE(decoder.hasMessage());
    EXPECT_EQ(decoder.getBuffer(), expectedD2);
}

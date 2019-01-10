#include <sstream>
#include <gtest/gtest.h>
#include <glisseo/utils/Hexdump.h>

TEST(Hexdump, invalidAddressOffset)
{
    std::string input;
    std::stringstream stream;

    EXPECT_THROW(Glisseo::hexdump(stream, input, 1), std::invalid_argument);
}

TEST(Hexdump, emptyInput)
{
    std::string input;
    std::stringstream stream;

    std::string expected { " 0000 0000                                                    " };

    Glisseo::hexdump(stream, input);

    EXPECT_EQ(stream.str(), expected);
}

TEST(Hexdump, fewInput)
{
    std::stringstream stream;

    std::string inputA { "0" };
    std::string expectedA { " 0000 0000  30                                                0" };

    std::string inputB { "01" };
    std::string expectedB { " 0000 0000  30 31                                             01" };

    std::string inputC { "0123" };
    std::string expectedC { " 0000 0000  30 31 32 33                                       0123" };

    std::string inputD { "01234567" };
    std::string expectedD { " 0000 0000  30 31 32 33 34 35 36 37                           01234567" };

    std::string inputE { "0123456789ab" };
    std::string expectedE { " 0000 0000  30 31 32 33 34 35 36 37  38 39 61 62              0123456789ab" };

    std::string inputF { "0123456789abcdef" };
    std::string expectedF { " 0000 0000  30 31 32 33 34 35 36 37  38 39 61 62 63 64 65 66  0123456789abcdef" };

    Glisseo::hexdump(stream, inputA);
    EXPECT_EQ(stream.str(), expectedA);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputB);
    EXPECT_EQ(stream.str(), expectedB);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputC);
    EXPECT_EQ(stream.str(), expectedC);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputD);
    EXPECT_EQ(stream.str(), expectedD);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputE);
    EXPECT_EQ(stream.str(), expectedE);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputF);
    EXPECT_EQ(stream.str(), expectedF);
}

TEST(Hexdump, largeInput)
{
    std::stringstream stream;

    std::string inputA { "0123456789abcdefX" };
    std::string expectedA { " 0000 0000  30 31 32 33 34 35 36 37  38 39 61 62 63 64 65 66  0123456789abcdef\n"
                            " 0000 0010  58                                                X" };

    std::string inputB { "LibGlisseo//LibGlisseo//LibGlisseo" };
    std::string expectedB { " 0000 0000  4c 69 62 47 6c 69 73 73  65 6f 2f 2f 4c 69 62 47  LibGlisseo//LibG\n"
                            " 0000 0010  6c 69 73 73 65 6f 2f 2f  4c 69 62 47 6c 69 73 73  lisseo//LibGliss\n"
                            " 0000 0020  65 6f                                             eo" };

    Glisseo::hexdump(stream, inputA);
    EXPECT_EQ(stream.str(), expectedA);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputB);
    EXPECT_EQ(stream.str(), expectedB);
}

TEST(Hexdump, nonPrintableCharacters)
{
    std::stringstream stream;

    std::string inputA { "\x1f ~\x7f\xff" };
    std::string expectedA { " 0000 0000  1f 20 7e 7f ff                                    . ~.." };

    Glisseo::hexdump(stream, inputA);
    EXPECT_EQ(stream.str(), expectedA);
}

TEST(Hexdump, withAddressOffset)
{
    std::stringstream stream;
    unsigned int addressOffset = 0x12345670;

    std::string inputA { "" };
    std::string expectedA { " 1234 5670                                                    " };

    std::string inputB { "0" };
    std::string expectedB { " 1234 5670  30                                                0" };

    std::string inputC { "LibGlisseo//LibGlisseo//LibGlisseo" };
    std::string expectedC { " 1234 5670  4c 69 62 47 6c 69 73 73  65 6f 2f 2f 4c 69 62 47  LibGlisseo//LibG\n"
                            " 1234 5680  6c 69 73 73 65 6f 2f 2f  4c 69 62 47 6c 69 73 73  lisseo//LibGliss\n"
                            " 1234 5690  65 6f                                             eo" };

    Glisseo::hexdump(stream, inputA, addressOffset);
    EXPECT_EQ(stream.str(), expectedA);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputB, addressOffset);
    EXPECT_EQ(stream.str(), expectedB);

    stream.str(std::string());
    Glisseo::hexdump(stream, inputC, addressOffset);
    EXPECT_EQ(stream.str(), expectedC);
}

#include <gtest/gtest.h>
#include <glisseo/utils/EnumMapper.h>

enum class TestEnum
{
    A,
    B,
    C,
    UNKNOWN
};

std::map<std::string, TestEnum> testEnumMapping = {
    { "A", TestEnum::A },
    { "B", TestEnum::B }
};

TEST(EnumMapper, IdentifierToEnum)
{
    std::string identifierA { "A" };
    std::string identifierB { "B" };
    TestEnum expectedA = TestEnum::A;
    TestEnum expectedB = TestEnum::B;

    EXPECT_EQ(Glisseo::identifierToEnum(testEnumMapping, identifierA), expectedA);
    EXPECT_EQ(Glisseo::identifierToEnum(testEnumMapping, identifierB), expectedB);
}

TEST(EnumMapper, IdentifierToEnumUnknown)
{
    std::string identifier { "foo" };
    TestEnum expected = TestEnum::UNKNOWN;

    EXPECT_THROW(Glisseo::identifierToEnum(testEnumMapping, identifier), std::out_of_range);
    EXPECT_EQ(Glisseo::identifierToEnumWithDefault(testEnumMapping, identifier, TestEnum::UNKNOWN), expected);
}

TEST(EnumMapper, EnumToIdentifier)
{
    TestEnum identifierA = TestEnum::A;
    TestEnum identifierB = TestEnum::B;
    std::string expectedA { "A" };
    std::string expectedB { "B" };

    EXPECT_EQ(Glisseo::enumToIdentifier(testEnumMapping, identifierA), expectedA);
    EXPECT_EQ(Glisseo::enumToIdentifier(testEnumMapping, identifierB), expectedB);
}

TEST(EnumMapper, EnumToIdentifierUnknown)
{
    TestEnum enumValue = TestEnum::C;
    std::string expected { "unknown" };

    EXPECT_THROW(Glisseo::enumToIdentifier(testEnumMapping, enumValue), std::out_of_range);
    EXPECT_EQ(Glisseo::enumToIdentifierWithDefault(testEnumMapping, enumValue, expected), expected);
}

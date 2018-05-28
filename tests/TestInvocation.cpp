#include <sstream>
#include <gtest/gtest.h>
#include <glisseo/utils/Invocation.h>

TEST(Invocation, ArgumentsNoThrow)
{
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "", "", "", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("", "foo", "", "", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "foo", "", "", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "foo", "", "BAR", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "foo", "", "BAR", true));
}

TEST(Invocation, ArgumentsThrow)
{
    EXPECT_ANY_THROW(Flix::InvocationArgument("", "", "", "", false));
    EXPECT_ANY_THROW(Flix::InvocationArgument("fo", "", "", "", false));
    EXPECT_ANY_THROW(Flix::InvocationArgument("f", "foo", "", "", true));
}

TEST(Invocation, PrintHelpShort)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    expectedA << "USAGE: programName" << std::endl << std::endl;
    invocation.printHelp(stream, "programName");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpShortWithVersionInformation)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    expectedA << "USAGE: programName" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpOneFlag)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "", false);
    stream.str(std::string());
    expectedA << "USAGE: programName [FLAGS]" << std::endl << std::endl;
    expectedA << "Flags:" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpTwoFlags)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "", false);
    invocation.addArgument("b", "", "Bar", "", false);
    stream.str(std::string());
    expectedA << "USAGE: programName [FLAGS]" << std::endl << std::endl;
    expectedA << "Flags:" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

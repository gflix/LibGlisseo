#include <sstream>
#include <gtest/gtest.h>
#include <glisseo/utils/Invocation.h>

TEST(Invocation, ArgumentsNoThrow)
{
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "", "", "", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "", "", "BAR", false));
    EXPECT_NO_THROW(Flix::InvocationArgument("f", "", "", "BAR", true));
}

TEST(Invocation, ArgumentsThrow)
{
    EXPECT_ANY_THROW(Flix::InvocationArgument("", "", "", "", false));
    EXPECT_ANY_THROW(Flix::InvocationArgument("", "foo", "", "", false));
    EXPECT_ANY_THROW(Flix::InvocationArgument("fo", "", "", "", false));
    EXPECT_ANY_THROW(Flix::InvocationArgument("f", "", "", "", true));
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
    expectedA << "Flags:" << std::endl;
    expectedA << "  -f  Foo" << std::endl << std::endl;
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
    expectedA << "Flags:" << std::endl;
    expectedA << "  -f  Foo" << std::endl;
    expectedA << "  -b  Bar" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpOneOptionalArgument)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "FOO", false);
    stream.str(std::string());
    expectedA << "USAGE: programName [ARGUMENTS]" << std::endl << std::endl;
    expectedA << "Optional arguments:" << std::endl;
    expectedA << "  -f FOO  Foo" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpTwoOptionalArguments)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "FOO", false);
    invocation.addArgument("b", "", "Bar", "BAR", false);
    stream.str(std::string());
    expectedA << "USAGE: programName [ARGUMENTS]" << std::endl << std::endl;
    expectedA << "Optional arguments:" << std::endl;
    expectedA << "  -f FOO  Foo" << std::endl;
    expectedA << "  -b BAR  Bar" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpOneArgument)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "FOO", true);
    stream.str(std::string());
    expectedA << "USAGE: programName ARGUMENTS" << std::endl << std::endl;
    expectedA << "Required arguments:" << std::endl;
    expectedA << "  -f FOO  Foo" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpTwoArguments)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("f", "", "Foo", "FOO", true);
    invocation.addArgument("b", "", "Bar", "BAR", true);
    stream.str(std::string());
    expectedA << "USAGE: programName ARGUMENTS" << std::endl << std::endl;
    expectedA << "Required arguments:" << std::endl;
    expectedA << "  -f FOO  Foo" << std::endl;
    expectedA << "  -b BAR  Bar" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpRemainingArguments)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.setupRemainingArguments("REMAINING", "Remaining arguments");
    stream.str(std::string());
    expectedA << "USAGE: programName REMAINING" << std::endl << std::endl;
    expectedA << "Remaining arguments:" << std::endl;
    expectedA << "  REMAINING  Remaining arguments" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpAnyArgument)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Flix::Invocation invocation;

    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");
    invocation.addArgument("c", "", "Ccc", "CCC");
    invocation.addArgument("d", "", "Ddd", "DDD");
    invocation.addArgument("e", "", "Eee", "EEE", true);
    invocation.addArgument("f", "", "Fff", "FFF", true);
    invocation.setupRemainingArguments("GGG", "Ggg");
    stream.str(std::string());
    expectedA << "USAGE: programName [FLAGS] [ARGUMENTS] ARGUMENTS GGG" << std::endl << std::endl;
    expectedA << "Flags:" << std::endl;
    expectedA << "  -a  Aaa" << std::endl;
    expectedA << "  -b  Bbb" << std::endl << std::endl;
    expectedA << "Optional arguments:" << std::endl;
    expectedA << "  -c CCC  Ccc" << std::endl;
    expectedA << "  -d DDD  Ddd" << std::endl << std::endl;
    expectedA << "Required arguments:" << std::endl;
    expectedA << "  -e EEE  Eee" << std::endl;
    expectedA << "  -f FFF  Fff" << std::endl << std::endl;
    expectedA << "Remaining arguments:" << std::endl;
    expectedA << "  GGG  Ggg" << std::endl << std::endl;
    expectedA << "Version information:" << std::endl;
    expectedA << "  versionInformation" << std::endl << std::endl;
    invocation.printHelp(stream, "programName", "versionInformation");
    EXPECT_EQ(stream.str(), expectedA.str());
}

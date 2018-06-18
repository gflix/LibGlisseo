#include <sstream>
#include <gtest/gtest.h>
#include <glisseo/utils/Invocation.h>

TEST(Invocation, ArgumentsNoThrow)
{
    EXPECT_NO_THROW(Glisseo::InvocationArgument("f", "", "", "", false));
    EXPECT_NO_THROW(Glisseo::InvocationArgument("f", "", "", "BAR", false));
    EXPECT_NO_THROW(Glisseo::InvocationArgument("f", "", "", "BAR", true));
}

TEST(Invocation, ArgumentsThrow)
{
    EXPECT_ANY_THROW(Glisseo::InvocationArgument("", "", "", "", false));
    EXPECT_ANY_THROW(Glisseo::InvocationArgument("", "foo", "", "", false));
    EXPECT_ANY_THROW(Glisseo::InvocationArgument("fo", "", "", "", false));
    EXPECT_ANY_THROW(Glisseo::InvocationArgument("f", "", "", "", true));
}

TEST(Invocation, PrintHelpShort)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Glisseo::Invocation invocation;

    expectedA << "USAGE: programName" << std::endl << std::endl;
    invocation.printHelp(stream, "programName");
    EXPECT_EQ(stream.str(), expectedA.str());
}

TEST(Invocation, PrintHelpShortWithVersionInformation)
{
    std::stringstream stream;
    std::stringstream expectedA;

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

    Glisseo::Invocation invocation;

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

TEST(Invocation, GetOptString)
{
    std::string expectedA;

    Glisseo::Invocation invocation;

    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");
    invocation.addArgument("c", "", "Ccc", "CCC", false);
    invocation.addArgument("d", "", "Ddd", "DDD", false);
    invocation.addArgument("e", "", "Eee", "EEE", true);
    invocation.addArgument("f", "", "Fff", "FFF", true);

    expectedA = "abc:d:e:f:";

    EXPECT_EQ(invocation.getGetOptString(), expectedA);
}

TEST(Invocation, GetArgumentThrow)
{
    Glisseo::Invocation invocation;

    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");

    EXPECT_ANY_THROW(invocation.getArgument("c"));
    EXPECT_ANY_THROW(invocation.getArgument("ccc"));
}

TEST(Invocation, GetArgumentNoThrow)
{
    Glisseo::Invocation invocation;

    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");

    EXPECT_NO_THROW(invocation.getArgument("a"));
    EXPECT_NO_THROW(invocation.getArgument("b"));

    EXPECT_EQ(invocation.getArgument("a").shortArgument, "a");
}

TEST(Invocation, EvaluateThrow)
{
    int argcA = 0;
    char* const argvA[] = { "programName" };
    int argcB = 1;
    char* argvB[] = { nullptr };
    int argcC = 2;
    char* argvC[] = { "programName", "-a" };

    Glisseo::Invocation invocation;

    EXPECT_ANY_THROW(invocation.evaluate(argcA, argvA));
    EXPECT_ANY_THROW(invocation.evaluate(argcB, argvB));

    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb", "BBB", true);
    EXPECT_ANY_THROW(invocation.evaluate(argcC, argvC));
}

TEST(Invocation, EvaluateNoThrow)
{
    int argcA = 1;
    char* const argvA[] = { "programName" };
    int argcB = 2;
    char* const argvB[] = { "programName", "-a" };

    Glisseo::Invocation invocation;
    invocation.addArgument("a", "", "Aaa");

    /*EXPECT_NO_THROW(*/invocation.evaluate(argcA, argvA)/*)*/;
    EXPECT_NO_THROW(invocation.evaluate(argcB, argvB));
}

TEST(Invocation, EvaluateFlags)
{
    int argcA = 3;
    char* const argvA[] = { "programName", "-b", "-c" };

    Glisseo::Invocation invocation;
    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");
    invocation.addArgument("c", "", "Ccc");
    invocation.addArgument("d", "", "Ddd");

    EXPECT_NO_THROW(invocation.evaluate(argcA, argvA));
    EXPECT_FALSE(invocation.getArgument("a").argumentIsPresent);
    EXPECT_TRUE(invocation.getArgument("b").argumentIsPresent);
    EXPECT_TRUE(invocation.getArgument("c").argumentIsPresent);
    EXPECT_FALSE(invocation.getArgument("d").argumentIsPresent);
}

TEST(Invocation, EvaluateOptionalArguments)
{
    int argcA = 4;
    char* const argvA[] = { "programName", "-bBBB", "-c", "CCC" };

    Glisseo::Invocation invocation;
    invocation.addArgument("a", "", "Aaa", "AAA");
    invocation.addArgument("b", "", "Bbb", "BBB");
    invocation.addArgument("c", "", "Ccc", "CCC");
    invocation.addArgument("d", "", "Ddd", "DDD");

    EXPECT_NO_THROW(invocation.evaluate(argcA, argvA));
    EXPECT_FALSE(invocation.getArgument("a").argumentIsPresent);
    EXPECT_TRUE(invocation.getArgument("b").argumentIsPresent);
    EXPECT_EQ(invocation.getArgument("b").parameterValue, "BBB");
    EXPECT_TRUE(invocation.getArgument("c").argumentIsPresent);
    EXPECT_EQ(invocation.getArgument("c").parameterValue, "CCC");
    EXPECT_FALSE(invocation.getArgument("d").argumentIsPresent);
}

TEST(Invocation, EvaluateRequiredArguments)
{
    int argcA = 4;
    char* const argvA[] = { "programName", "-bBBB", "-c", "CCC" };

    Glisseo::Invocation invocation;
    invocation.addArgument("a", "", "Aaa", "AAA");
    invocation.addArgument("b", "", "Bbb", "BBB", true);
    invocation.addArgument("c", "", "Ccc", "CCC", true);

    EXPECT_NO_THROW(invocation.evaluate(argcA, argvA));

    invocation.addArgument("d", "", "Ddd", "DDD");
    EXPECT_NO_THROW(invocation.evaluate(argcA, argvA));

    invocation.addArgument("e", "", "Eee", "EEE", true);
    EXPECT_ANY_THROW(invocation.evaluate(argcA, argvA));
}

TEST(Invocation, EvaluateRemainingArguments)
{
    int argcA = 5;
    char* const argvA[] = { "programName", "-b", "-c", "FOO", "BAR" };

    Glisseo::Invocation invocation;
    invocation.addArgument("a", "", "Aaa");
    invocation.addArgument("b", "", "Bbb");
    invocation.addArgument("c", "", "Ccc");
    invocation.addArgument("d", "", "Ddd");

    EXPECT_NO_THROW(invocation.evaluate(argcA, argvA));
    Glisseo::Arguments remainingArguments = invocation.getRemainingArguments();
    EXPECT_EQ(remainingArguments.size(), 2);
    EXPECT_EQ(remainingArguments[0], "FOO");
    EXPECT_EQ(remainingArguments[1], "BAR");
}

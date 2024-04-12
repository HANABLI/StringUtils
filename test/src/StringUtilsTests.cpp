/**
 * @file StringUtils.cpp
 * 
 * This module contains unit Tests of the StringUtils functions 
 * 
 * © 2024 by Hatem Nabli
*/

#include <gtest\gtest.h>
#include <StringUtils\StringUtils.hpp>

std::string vsprintfHelper(char const* format, ...) {
    va_list args;
    va_start(args, format);
    const auto result = StringUtils::vsprintf("%s, %s!", args);
    va_end(args);
    return result;
}

TEST(StringUtilsTests, vsprintf__Test) {
    ASSERT_EQ("Hello, World!", vsprintfHelper("%s, %s!", "Hello", "World"));
}

TEST(StringUtilsTests, sprintfStandardCLibrarysVersionBehaves__Test) {
    ASSERT_EQ("Hello, World!", StringUtils::sprintf("%s, %s!", "Hello", "World"));
}

TEST(StringUtilsTests, sprintfReturnsStringComparabletoCppString) {
    const std::string expectedOutput = "The answer is 47.";
    ASSERT_EQ(expectedOutput, StringUtils::sprintf("The answer is %d.", 47));
}

TEST(StringUtilsTests, wcstombs_Test) {
    ASSERT_EQ("Hello, World!", StringUtils::wcstombs(L"Hello, World!"));

}

TEST(StringUtilsTests, Trim_Test) {
    ASSERT_EQ("Hello, World!", StringUtils::Trim("  \t  \t\t  Hello, World! \r  \n \r\n \t \t\t  "));
}

TEST(StringUtilsTests, Indent_Test) {
    ASSERT_EQ(
        "Hello, World!\r\n"
        "  This is line 2\r\n"
        "  This is line 3\r\n", 
        StringUtils::Indent( 
            "Hello, World!\r\n"
            "This is line 2\r\n"
            "This is line 3\r\n",
            2
        )
    );

    ASSERT_EQ(
    (
        "Struct {\r\n"
        "  field 1\r\n"
        "  field 2\r\n"
        "}"
    ),
    "Struct {"
    + StringUtils::Indent(
        "\r\nfield 1"
        "\r\nfield 2",
        2
    )
    + "\r\n}"
    );
}

TEST(StringUtilsTests, ParseComponent_Test) {
    const std::string line = "Value = {abc {c} = def} NextValue = 42";
    ASSERT_EQ("abc {c} = def}", StringUtils::ParseComponent(line, 9, line.length()));
}

TEST(StringUtilsTests, Escape_Test) {
    const std::string line = "Hello, W^orld!";
    ASSERT_EQ("Hello,^ W^^orld^!", StringUtils::Escape(line, '^', {' ', '!', '^'}));
}

TEST(StringUtilsTests, Unescape_Test) {
    const std::string line = "Hello,^ W^^orld^!";
    ASSERT_EQ("Hello, W^orld!", StringUtils::Unescape(line, '^'));
}

TEST(StringUtilsTests, SplitWithCharDelimiter_Test) {
    const std::string line = "Hello, World!";
    ASSERT_EQ(
        (std::vector< std::string >{"Hello,", "World!"}),
        StringUtils::Split(line, ' ')
    );
}

TEST(StringUtilsTests, SplitWhithMultiCharDelimiter_Test) {
    const std::string line = "Hello::World!::My:Darling";
    ASSERT_EQ(
        (std::vector< std::string >{"Hello", "World!", "My:Darling"}),
        StringUtils::Split(line, "::")
    );
}

TEST(StringUtilsTests, JoinSingleCharacterDelimiter_Test) {
    const std::vector< std::string >elements{"Hello", "World!"};
    ASSERT_EQ(
        "Hello-World!", 
        StringUtils::Join(elements, '-')
    );
}


TEST(StringUtilsTests, JoinMultiCharacterDelimiter_Test) {
    const std::vector< std::string >elements{"Hello", "World!"};
    ASSERT_EQ(
        "Hello, World!", 
        StringUtils::Join(elements, ", ")
    );
}

TEST(StringUtilsTests, Tolowers_Test) {
    EXPECT_EQ("hello", StringUtils::Tolower("Hello"));
    EXPECT_EQ("hello", StringUtils::Tolower("hello"));
    EXPECT_EQ("hello", StringUtils::Tolower("heLLo"));
    EXPECT_EQ("example", StringUtils::Tolower("eXAmplE"));
    EXPECT_EQ("example", StringUtils::Tolower("example"));
    EXPECT_EQ("example", StringUtils::Tolower("EXAMPLE"));
    EXPECT_EQ("foo1bar", StringUtils::Tolower("foo1BAR"));
    EXPECT_EQ("foo1bar", StringUtils::Tolower("fOo1bAr"));
    EXPECT_EQ("foo1bar", StringUtils::Tolower("foo1bar"));
    EXPECT_EQ("foo1bar", StringUtils::Tolower("FOO1BAR"));
}

}
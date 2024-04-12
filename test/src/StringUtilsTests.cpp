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
}
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
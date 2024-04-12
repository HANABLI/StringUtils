/**
 * @file StringUtils.cpp
 * 
 * This module containe the implementation of the StringUtils functions.
 * 
 * © 2024 by Hatem Nabli
*/

#include <StringUtils\StringUtils.hpp>

namespace StringUtils
{

    
    std::string sprintf(const char* format, ...) {
        va_list args;
        va_start(args, format);
        return vsprintf(format, args);
    }

    
} // namespace StringUtils

#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP
/**
 * @file StringUtils.hpp
 * 
 * This module contains the declaration of the StringUtils functions.
 * 
 * © 2024 by Hatem Nabli
*/
#include <stdarg.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <memory>
#include <string>
#include <limits>


namespace StringUtils {

    
    /**
     * This fucntion is equivalent to the sprintf function in the standard C
     * library, except tha it constructs the string dynamically and
     * returns it as a std::string value
    */
    std::string sprintf(const char* format, ...);

    /**
     * This fucntion is equivalent to the vsprintf function in the standard C
     * library, except tha it constructs the string dynamically and
     * returns it as a std::string value
    */
    std::string vsprintf(const char* format, va_list args);

    
}



#endif /*STRING_UTILS_HPP*/
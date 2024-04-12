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

    /**
     * This method convert a given string from wide (UNICODE) to 
     * narrow (multibyte) format, using the currently set locale.
     * 
     * This method has the same semantics as the C function "wcstombc".
     * 
     * @param[in] src
     *      This is the string to convert.
     * 
     * @return
     *      returns a converted string.
    */
    std::string wcstombs(const std::wstring& src);

    /**
     * This method makes a copy of a string and removes any whitespace
     * from the front and back of the copy.
     * 
     * @param[in] s
     *      This is the string to trim.
     * 
     * @return
     *      The trimed string is returned.
    */
    std::string Trim(const std::string& s);
}



#endif /*STRING_UTILS_HPP*/
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

    /**
     * This function breaks up the given string into lines,
     * according to any CR-LF end-of-line character sequences found
     * in the string, indents all lines except the first,
     * and then concatenates the lines back together, returning
     * them as a single string.
     * 
     * @param[in] linesIn
     *      This is the string containing the lines to indent.
     * 
     * @param[in] spaces
     *      This is the number of spaces to indent each line but the first.
     * 
     * @return
     *      returns the indented text as a single string.
    */
    std::string Indent(std::string linesIn, size_t spaces);

    /**
     * This fucntion returns a substring of the given string that contains
     * the delimited component, such as string, "array", object, etc.., pairs:
     * " "
     * [ ]
     * { }
     * < >
     * ( )
     * 
     * Escaped delimiter characters (i.e. "\{") are not considered as delimiters.
     * 
     * Any comma (',') or "outer-most" delimiter encountered while scanning 
     * the string is considered to terminate the component.
     * 
     * @param[in] s
     *      This is the string from which to extract the next delimited component.
     * 
     * @param[in] begin
     *      This is the starting posistion from which to scan the next component.
     * 
     * @param[in] end
     *      This is the limit to which the string will be scanned to determine
     *      the next component.
    */
    std::string ParseComponent(const std::string& s, size_t begin, size_t end);
}



#endif /*STRING_UTILS_HPP*/
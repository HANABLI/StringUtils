#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP
/**
 * @file StringUtils.hpp
 * 
 * This module contains the declaration of the StringUtils functions.
 * 
 * © 2024 by Hatem Nabli
*/

#include <memory>



namespace StringUtils {



    /**
     * This function is equivalent to the sprintf function in the standard C
     * library, except that it constructs the string dynamically and
     * returns it as a std::string value
    */
    std::string sprintf(const char* format, ...);

    
}



#endif /*STRING_UTILS_HPP*/
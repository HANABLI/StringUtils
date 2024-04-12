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
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <limits>


namespace StringUtils {

            /**
     * These are the different results that can be indicated
     * when a string is parsed as an integer.
     */
    enum class ToIntegerResult {
        /**
         * This indicates the size was parsed successfully.
         */
        Success,

        /**
         * This indicates the size had one or more characters
         * that were not digits.
         */
        NotANumber,

        /**
         * This indicates the size exceeded the maximum representable
         * size integer.
         */
        Overflow
    };

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

    /**
     * This function return a copie of the given input string, modifird
     * so that every character in the given "charactersToEscape" that is
     * found in the input string is prefixed by the given "escapeCharacter".
     *
     * @param[in] s
     *     This is the input string.
     *
     * @param[in] escapeCharacter
     *     This is the character to put in front of every character
     *     in the input string that is a member of the
     *     "charactersToEscape" set.
     *
     * @param[in] charactersToEscape
     *     These are the characters that should be escaped in the input.
     *
     * @return
     *     A copy of the input string is returned, where every character
     *     in the given "charactersToEscape" that is found in the input
     *     string is prefixed by the given "escapeCharacter".
     */
    std::string Escape(const std::string& s, char escapeCharacter, const std::set< char >& charactersToEscape);

    /**
     * This function removes the given escapeCharacter from the given input
     * string.
     * 
     * @param[in] s
     *      This is the string from which to remove all escape characters.
     * 
     * @param[in] escapCharacter
     *      This is the character to remove from the given input string.
     * @return
     *      returns the given input string after removong all instances of 
     *      the given escapeCharacter.
    */
   std::string Unescape(const std::string& s, char escapeCharacter);

   /**
    * This function break the given string at each instance of the 
    * given delimiter, returning the pieces as a collection of 
    * substrings. Tha delimiter charachters are removed.
    * 
    * @param[in] s
    *       This is the string to split.
    * @param[in] d
    *       This is the delimiter character at which to split the string.
    * @return
    *       returns the collection of substrings that result from breaking 
    *       the given string at each delimiter character. 
   */
  std::vector< std::string > Split(const std::string& s, char d);

    /**
    * This function break the given string at each instance of the 
    * given delimiter, returning the pieces as a collection of 
    * substrings. Tha delimiter charachters are removed.
    * 
    * @param[in] s
    *       This is the string to split.
    * @param[in] d
    *       This is the delimiter string at which to split the string.
    * @return
    *       returns the collection of substrings that result from breaking 
    *       the given string at each delimiter string. 
   */
  std::vector< std::string > Split(const std::string& s, const std::string& d);

  /**
   * This function take the given sequence of substrings to 
   * concatenate them together into a formel string, each piece separated by 
   * the given delimiter character.
   * 
   * @param[in] v
   *        This is the sequence of substrings to join together.
   * 
   * @param[in] d
   *        This is the delimiter character used as glue between
   *        substrings.
   * @return
   *        returns a string formed formed from the concatenation 
   *        of the sequece of substrings separeted by the given 
   *        delimiter character.
  */
 std::string Join(const std::vector< std::string >& v, const char d );

   /**
   * This function take the given sequence of substrings to 
   * concatenate them together into a formel string, each piece separated by 
   * the given delimiter character.
   * 
   * @param[in] v
   *        This is the sequence of substrings to join together.
   * 
   * @param[in] d
   *        This is the delimiter character used as glue between
   *        substrings.
   * @return
   *        returns a string formed formed from the concatenation 
   *        of the sequece of substrings separeted by the given 
   *        delimiter character.
  */
 std::string Join(const std::vector< std::string >& v, const std::string& d );

    /**
     * This function check each character of the given string
     * to convert them to lower-case.
     * 
     * @param[in] s
     *      This is the string to check and to convert to lower-case.
     * @return
     *      Returns the given string in lower-case style
    */
   std::string Tolower(const std::string& s);


   /**
    * This function parses the given string as an
    * integer, detecting invalid characters, overflow, etc.
    *
    * @param[in] numberString
    *     This is the string containing the number to parse.
    *
    * @param[out] number
    *     This is where to store the number parsed.
    *
    * @return
    *     An indication of whether or not the number was parsed
    *     successfully is returned. 
   */
  ToIntegerResult ToInteger(const std::string& numberString, intmax_t& number);

    /**
    * Take the given template and produce a string which is a copy of
    * the template, but with substitution markers replaced by the values
    * of corresponding entries in the given collection of variables.
    *
    * @param[in] templateText
    *     This is the template to instantiate.
    *
    * @param[in] variables
    *     This holds the values of variables which may be substituted
    *     in the template.
    *
    * @return
    *     The instantiated template is returned.
    */
    std::string InstantiateTemplate(
        const std::string& templateText,
        const std::map< std::string, std::string >& variables
    );
}



#endif /*STRING_UTILS_HPP*/
# StringUtils

This library contains some C++ string-oriented utilities, which ought to be in the standard library, but aren't.

## Usage

$\color{Blue}{StringExtensions::sprintf}$ function is the C++ equivalent of the sprintf function from the standard C library.

$\color{Blue}{StringExtensions::wcstombs}$ function is the C++ equivalent of the wcstombs function from the standard C library.

$\color{Blue}{StringExtensions::Trim}$ function makes a copy of a string and removes any whitespace from the front and back of the copy.

$\color{Blue}{StringExtensions::Indent}$ function breaks input text into lines and indents them.

$\color{Blue}{StringExtensions::ParseComponent}$ function is used to break apart a composite string into pieces, according to commonly-used delimiters, and respecting escaped characters.

$\color{Blue}{StringExtensions::Escape}$ and $\color{Blue}{StringExtensions::Unescape}$ functions are useful for dealing with string that contain characters that need to be "escaped" to avoid parsing issues when used within structures or compositions.

$\color{Blue}{StringExtensions::Split}$ and $\color{Blue}{StringExtensions::Join}$ functions are useful for dealing with strings which compose lists of smaller strings.

$\color{Blue}{StringExtensions::ToLower}$ function is used to convert all upper-case characters in a string to lower-case.

$\color{Blue}{StringExtensions::ToInteger}$ function is used to parse integers represented in strings.

## Supported plaforms / recommended toolchains  

* Windows -- [Visual Studio](https://www.visualstudio.com/) (Microsoft Visual C++)
* Linux -- clang or gcc
* MacOS -- Xcode (clang)

## Building

There are two distinct steps in the build  process:

1. Generation of the build system, using CMake
2. Compiling, linking, etc., using CMake-compatible toolchain

### Prerequisites
* [CMake](https://cmake.org/) version 3.8 or newer
* C++11 toolchain compatible with CMake for the develoment platform (e.g. [Visual Studio](https://www.visualstudio.com/) on Windows)

### Build system generation

Generate the build system using [CMake](https://cmake.org/) from the solution root .  
Example:
```bash
mkdir build
cd build
cmake -G "Visual Studio 15 2017" -A "x64" ..
```

### Compilling, linking, etc ..

Either use [CMake](https://cmake.org/) or your toolchain's IDE for build.

For [CMake](https://cmake.org/) build :

```bash
cd build
cmake --build .
```

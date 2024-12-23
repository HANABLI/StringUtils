# CMackeLists.txt for StringUtils 
#
# © 2024 by Hatem Nabli


cmake_minimum_required(VERSION 3.8)
set(this StringUtils )

set(Headers 
    include/StringUtils/StringUtils.hpp
)

set(Sources 
    src/StringUtils.cpp
)

add_library(${this} STATIC ${Sources} ${Headers})
set_target_properties(${this} PROPERTIES 
    FOLDER Libraries
)

target_include_directories(${this} PUBLIC include)

add_subdirectory(test)
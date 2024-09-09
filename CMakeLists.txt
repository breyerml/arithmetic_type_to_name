cmake_minimum_required(VERSION 3.30)
project(arithmetic_type_to_name
        VERSION 1.0.1
        DESCRIPTION "Implements a function to convert any cv-qualified arithmetic type to its name."
        LANGUAGES CXX)

add_executable(arithmetic_type_to_name examples.cpp arithmetic_type_to_name.hpp)

option(CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR "Use const char * as return value to support C++ standards earlier than C++17." OFF)
if (CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR)
    # use const char * -> also support C++11 and C++14
    target_compile_definitions(arithmetic_type_to_name PRIVATE CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR)
    set(CPP_UTIL_UNSUPPORTED_CXX_STANDARDS 98)
else ()
    # use std::string_view -> needs C++17
    set(CPP_UTIL_UNSUPPORTED_CXX_STANDARDS 98 11 14)
endif ()

# set the latest CXX standard
list(FIND CPP_UTIL_UNSUPPORTED_CXX_STANDARDS ${CMAKE_CXX_STANDARD_LATEST} CPP_UTIL_UNSUPPORTED_CXX_STANDARDS_INDEX)
if(CPP_UTIL_UNSUPPORTED_CXX_STANDARDS_INDEX EQUAL -1)
    message(STATUS "Setting C++ standard to ${CMAKE_CXX_STANDARD_LATEST}.")
    set_property(TARGET arithmetic_type_to_name PROPERTY CXX_STANDARD ${CMAKE_CXX_STANDARD_LATEST})
else()
    if (CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR)
        message(FATAL_ERROR "At least C++11 must be supported by the used compiler, but the latest supported standard is ${CMAKE_CXX_STANDARD_LATEST}!")
    else ()
        message(FATAL_ERROR "At least C++17 must be supported by the used compiler, but the latest supported standard is ${CMAKE_CXX_STANDARD_LATEST}!")
    endif ()
endif()

# enable testing
option(CPP_UTIL_ENABLE_TESTS "Enable testing using Catch2" OFF)
if (CPP_UTIL_ENABLE_TESTS)
    message(STATUS "Enabled testing using Catch2.")
    enable_testing()
    add_subdirectory(tests)
endif ()
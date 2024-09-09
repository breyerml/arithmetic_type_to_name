/**
 * Copyright (C) 2021 - Marcel Breyer - All Rights Reserved
 * Licensed under the MIT License. See LICENSE.md file in the project root for full license information.
 *
 * Implements tests for the cpp_util::arithmetic_type_to_name function.
 */

#include "arithmetic_type_to_name.hpp"

#include "catch/catch.hpp"

#include <cstring>  // std::strcmp

template<typename T>
bool check_names(const T name, const char *correct_name) = delete;

#if !defined(CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR)

#include <string_view>  // std::string_view

template<>
bool check_names(const std::string_view name, const char *correct_name) {
    return name == std::string_view{ correct_name };
}

#endif

template<>
bool check_names(const char *name, const char *correct_name) {
    return std::strcmp(name, correct_name) == 0;
}

TEST_CASE("arithmetic type to name", "[arithmetic]") {
    SECTION("boolean types") {
        // bool
        CHECK(check_names(cpp_util::arithmetic_type_to_name<bool>(), "bool"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const bool>(), "const bool"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile bool>(), "volatile bool"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile bool>(), "const volatile bool"));
    }

    SECTION("character types") {
        // char
        CHECK(check_names(cpp_util::arithmetic_type_to_name<char>(), "char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const char>(), "const char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile char>(), "volatile char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile char>(), "const volatile char"));

        // signed char
        CHECK(check_names(cpp_util::arithmetic_type_to_name<signed char>(), "signed char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const signed char>(), "const signed char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile signed char>(), "volatile signed char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile signed char>(), "const volatile signed char"));

        // unsigned char
        CHECK(check_names(cpp_util::arithmetic_type_to_name<unsigned char>(), "unsigned char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const unsigned char>(), "const unsigned char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile unsigned char>(), "volatile unsigned char"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile unsigned char>(), "const volatile unsigned char"));

#if defined(__cpp_char8_t)
        // char8_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<char8_t>(), "char8_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const char8_t>(), "const char8_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile char8_t>(), "volatile char8_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile char8_t>(), "const volatile char8_t"));
#endif

        // char16_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<char16_t>(), "char16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const char16_t>(), "const char16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile char16_t>(), "volatile char16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile char16_t>(), "const volatile char16_t"));

        // char32_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<char32_t>(), "char32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const char32_t>(), "const char32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile char32_t>(), "volatile char32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile char32_t>(), "const volatile char32_t"));

        // wchar_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<wchar_t>(), "wchar_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const wchar_t>(), "const wchar_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile wchar_t>(), "volatile wchar_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile wchar_t>(), "const volatile wchar_t"));
    }

    SECTION("integer types") {
        // short
        CHECK(check_names(cpp_util::arithmetic_type_to_name<short>(), "short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const short>(), "const short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile short>(), "volatile short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile short>(), "const volatile short"));

        // unsigned short
        CHECK(check_names(cpp_util::arithmetic_type_to_name<unsigned short>(), "unsigned short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const unsigned short>(), "const unsigned short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile unsigned short>(), "volatile unsigned short"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile unsigned short>(), "const volatile unsigned short"));

        // int
        CHECK(check_names(cpp_util::arithmetic_type_to_name<int>(), "int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const int>(), "const int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile int>(), "volatile int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile int>(), "const volatile int"));

        // unsigned int
        CHECK(check_names(cpp_util::arithmetic_type_to_name<unsigned int>(), "unsigned int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const unsigned int>(), "const unsigned int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile unsigned int>(), "volatile unsigned int"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile unsigned int>(), "const volatile unsigned int"));

        // long
        CHECK(check_names(cpp_util::arithmetic_type_to_name<long>(), "long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const long>(), "const long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile long>(), "volatile long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile long>(), "const volatile long"));

        // unsigned long
        CHECK(check_names(cpp_util::arithmetic_type_to_name<unsigned long>(), "unsigned long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const unsigned long>(), "const unsigned long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile unsigned long>(), "volatile unsigned long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile unsigned long>(), "const volatile unsigned long"));

        // long long
        CHECK(check_names(cpp_util::arithmetic_type_to_name<long long>(), "long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const long long>(), "const long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile long long>(), "volatile long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile long long>(), "const volatile long long"));

        // unsigned long long
        CHECK(check_names(cpp_util::arithmetic_type_to_name<unsigned long long>(), "unsigned long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const unsigned long long>(), "const unsigned long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile unsigned long long>(), "volatile unsigned long long"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile unsigned long long>(), "const volatile unsigned long long"));
    }

    SECTION("floating-point types") {
        // float
        CHECK(check_names(cpp_util::arithmetic_type_to_name<float>(), "float"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const float>(), "const float"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile float>(), "volatile float"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile float>(), "const volatile float"));

        // double
        CHECK(check_names(cpp_util::arithmetic_type_to_name<double>(), "double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const double>(), "const double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile double>(), "volatile double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile double>(), "const volatile double"));

        // long double
        CHECK(check_names(cpp_util::arithmetic_type_to_name<long double>(), "long double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const long double>(), "const long double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile long double>(), "volatile long double"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile long double>(), "const volatile long double"));
    }

    SECTION("fixed width floating-point types") {
#if defined(__STDCPP_FLOAT16_T__)
        // std::float16_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<std::float16_t>(), "std::float16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const std::float16_t>(), "const std::float16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile std::float16_t>(), "volatile std::float16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile std::float16_t>(), "const volatile std::float16_t"));
#endif

#if defined(__STDCPP_FLOAT32_T__)
        // std::float32_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<std::float32_t>(), "std::float32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const std::float32_t>(), "const std::float32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile std::float32_t>(), "volatile std::float32_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile std::float32_t>(), "const volatile std::float32_t"));
#endif

#if defined(__STDCPP_FLOAT64_T__)
        // std::float64_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<std::float64_t>(), "std::float64_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const std::float64_t>(), "const std::float64_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile std::float64_t>(), "volatile std::float64_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile std::float64_t>(), "const volatile std::float64_t"));
#endif

#if defined(__STDCPP_FLOAT128_T__)
        // std::float128_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<std::float128_t>(), "std::float128_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const std::float128_t>(), "const std::float128_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile std::float128_t>(), "volatile std::float128_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile std::float128_t>(), "const volatile std::float128_t"));
#endif

#if defined(__STDCPP_BFLOAT16_T__)
        // std::bfloat16_t
        CHECK(check_names(cpp_util::arithmetic_type_to_name<std::bfloat16_t>(), "std::bfloat16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const std::bfloat16_t>(), "const std::bfloat16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<volatile std::bfloat16_t>(), "volatile std::bfloat16_t"));
        CHECK(check_names(cpp_util::arithmetic_type_to_name<const volatile std::bfloat16_t>(), "const volatile std::bfloat16_t"));
#endif
    }
}

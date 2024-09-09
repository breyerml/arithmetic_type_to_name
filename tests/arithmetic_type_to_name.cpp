/**
 * Copyright (C) 2021 - Marcel Breyer - All Rights Reserved
 * Licensed under the MIT License. See LICENSE.md file in the project root for full license information.
 *
 * Implements tests for the cpp_util::arithmetic_type_to_name function.
 */

#include "arithmetic_type_to_name.hpp"

#include "catch/catch.hpp"

#include <string_view>  // std::string_view

TEST_CASE("arithmetic type to name", "[arithmetic]") {
    SECTION("boolean types") {
        // bool
        CHECK(cpp_util::arithmetic_type_to_name<bool>() == std::string_view{ "bool" });
        CHECK(cpp_util::arithmetic_type_to_name<const bool>() == std::string_view{ "const bool" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile bool>() == std::string_view{ "volatile bool" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile bool>() == std::string_view{ "const volatile bool" });
    }

    SECTION("character types") {
        // char
        CHECK(cpp_util::arithmetic_type_to_name<char>() == std::string_view{ "char" });
        CHECK(cpp_util::arithmetic_type_to_name<const char>() == std::string_view{ "const char" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile char>() == std::string_view{ "volatile char" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile char>() == std::string_view{ "const volatile char" });

        // signed char
        CHECK(cpp_util::arithmetic_type_to_name<signed char>() == std::string_view{ "signed char" });
        CHECK(cpp_util::arithmetic_type_to_name<const signed char>() == std::string_view{ "const signed char" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile signed char>() == std::string_view{ "volatile signed char" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile signed char>() ==
              std::string_view{ "const volatile signed char" });

        // unsigned char
        CHECK(cpp_util::arithmetic_type_to_name<unsigned char>() == std::string_view{ "unsigned char" });
        CHECK(cpp_util::arithmetic_type_to_name<const unsigned char>() == std::string_view{ "const unsigned char" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile unsigned char>() ==
              std::string_view{ "volatile unsigned char" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile unsigned char>() ==
              std::string_view{ "const volatile unsigned char" });

#if defined(__cpp_char8_t)
        // char8_t
        CHECK(cpp_util::arithmetic_type_to_name<char8_t>() == std::string_view{ "char8_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const char8_t>() == std::string_view{ "const char8_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile char8_t>() == std::string_view{ "volatile char8_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile char8_t>() == std::string_view{ "const volatile char8_t" });
#endif

        // char16_t
        CHECK(cpp_util::arithmetic_type_to_name<char16_t>() == std::string_view{ "char16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const char16_t>() == std::string_view{ "const char16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile char16_t>() == std::string_view{ "volatile char16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile char16_t>() ==
              std::string_view{ "const volatile char16_t" });

        // char32_t
        CHECK(cpp_util::arithmetic_type_to_name<char32_t>() == std::string_view{ "char32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const char32_t>() == std::string_view{ "const char32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile char32_t>() == std::string_view{ "volatile char32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile char32_t>() ==
              std::string_view{ "const volatile char32_t" });

        // wchar_t
        CHECK(cpp_util::arithmetic_type_to_name<wchar_t>() == std::string_view{ "wchar_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const wchar_t>() == std::string_view{ "const wchar_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile wchar_t>() == std::string_view{ "volatile wchar_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile wchar_t>() ==
              std::string_view{ "const volatile wchar_t" });
    }

    SECTION("integer types") {
        // short
        CHECK(cpp_util::arithmetic_type_to_name<short>() == std::string_view{ "short" });
        CHECK(cpp_util::arithmetic_type_to_name<const short>() == std::string_view{ "const short" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile short>() == std::string_view{ "volatile short" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile short>() == std::string_view{ "const volatile short" });

        // unsigned short
        CHECK(cpp_util::arithmetic_type_to_name<unsigned short>() == std::string_view{ "unsigned short" });
        CHECK(cpp_util::arithmetic_type_to_name<const unsigned short>() == std::string_view{ "const unsigned short" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile unsigned short>() ==
              std::string_view{ "volatile unsigned short" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile unsigned short>() ==
              std::string_view{ "const volatile unsigned short" });

        // int
        CHECK(cpp_util::arithmetic_type_to_name<int>() == std::string_view{ "int" });
        CHECK(cpp_util::arithmetic_type_to_name<const int>() == std::string_view{ "const int" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile int>() == std::string_view{ "volatile int" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile int>() == std::string_view{ "const volatile int" });

        // unsigned int
        CHECK(cpp_util::arithmetic_type_to_name<unsigned int>() == std::string_view{ "unsigned int" });
        CHECK(cpp_util::arithmetic_type_to_name<const unsigned int>() == std::string_view{ "const unsigned int" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile unsigned int>() ==
              std::string_view{ "volatile unsigned int" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile unsigned int>() ==
              std::string_view{ "const volatile unsigned int" });

        // long
        CHECK(cpp_util::arithmetic_type_to_name<long>() == std::string_view{ "long" });
        CHECK(cpp_util::arithmetic_type_to_name<const long>() == std::string_view{ "const long" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile long>() == std::string_view{ "volatile long" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile long>() == std::string_view{ "const volatile long" });

        // unsigned long
        CHECK(cpp_util::arithmetic_type_to_name<unsigned long>() == std::string_view{ "unsigned long" });
        CHECK(cpp_util::arithmetic_type_to_name<const unsigned long>() == std::string_view{ "const unsigned long" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile unsigned long>() ==
              std::string_view{ "volatile unsigned long" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile unsigned long>() ==
              std::string_view{ "const volatile unsigned long" });

        // long long
        CHECK(cpp_util::arithmetic_type_to_name<long long>() == std::string_view{ "long long" });
        CHECK(cpp_util::arithmetic_type_to_name<const long long>() == std::string_view{ "const long long" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile long long>() == std::string_view{ "volatile long long" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile long long>() ==
              std::string_view{ "const volatile long long" });

        // unsigned long long
        CHECK(cpp_util::arithmetic_type_to_name<unsigned long long>() == std::string_view{ "unsigned long long" });
        CHECK(cpp_util::arithmetic_type_to_name<const unsigned long long>() ==
              std::string_view{ "const unsigned long long" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile unsigned long long>() ==
              std::string_view{ "volatile unsigned long long" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile unsigned long long>() ==
              std::string_view{ "const volatile unsigned long long" });
    }

    SECTION("floating-point types") {
        // float
        CHECK(cpp_util::arithmetic_type_to_name<float>() == std::string_view{ "float" });
        CHECK(cpp_util::arithmetic_type_to_name<const float>() == std::string_view{ "const float" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile float>() == std::string_view{ "volatile float" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile float>() == std::string_view{ "const volatile float" });

        // double
        CHECK(cpp_util::arithmetic_type_to_name<double>() == std::string_view{ "double" });
        CHECK(cpp_util::arithmetic_type_to_name<const double>() == std::string_view{ "const double" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile double>() == std::string_view{ "volatile double" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile double>() ==
              std::string_view{ "const volatile double" });

        // long double
        CHECK(cpp_util::arithmetic_type_to_name<long double>() == std::string_view{ "long double" });
        CHECK(cpp_util::arithmetic_type_to_name<const long double>() == std::string_view{ "const long double" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile long double>() == std::string_view{ "volatile long double" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile long double>() ==
              std::string_view{ "const volatile long double" });
    }

    SECTION("fixed width floating-point types") {
#if defined(__STDCPP_FLOAT16_T__)
        // std::float16_t
        CHECK(cpp_util::arithmetic_type_to_name<std::float16_t>() == std::string_view{ "std::float16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const std::float16_t>() == std::string_view{ "const std::float16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile std::float16_t>() == std::string_view{ "volatile std::float16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile std::float16_t>() == std::string_view{ "const volatile std::float16_t" });
#endif

#if defined(__STDCPP_FLOAT32_T__)
        // std::float32_t
        CHECK(cpp_util::arithmetic_type_to_name<std::float32_t>() == std::string_view{ "std::float32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const std::float32_t>() == std::string_view{ "const std::float32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile std::float32_t>() == std::string_view{ "volatile std::float32_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile std::float32_t>() == std::string_view{ "const volatile std::float32_t" });
#endif

#if defined(__STDCPP_FLOAT64_T__)
        // std::float64_t
        CHECK(cpp_util::arithmetic_type_to_name<std::float64_t>() == std::string_view{ "std::float64_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const std::float64_t>() == std::string_view{ "const std::float64_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile std::float64_t>() == std::string_view{ "volatile std::float64_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile std::float64_t>() == std::string_view{ "const volatile std::float64_t" });
#endif

#if defined(__STDCPP_FLOAT128_T__)
        // std::float128_t
        CHECK(cpp_util::arithmetic_type_to_name<std::float128_t>() == std::string_view{ "std::float128_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const std::float128_t>() == std::string_view{ "const std::float128_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile std::float128_t>() == std::string_view{ "volatile std::float128_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile std::float128_t>() == std::string_view{ "const volatile std::float128_t" });
#endif

#if defined(__STDCPP_BFLOAT16_T__)
        // std::bfloat16_t
        CHECK(cpp_util::arithmetic_type_to_name<std::bfloat16_t>() == std::string_view{ "std::bfloat16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const std::bfloat16_t>() == std::string_view{ "const std::bfloat16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<volatile std::bfloat16_t>() == std::string_view{ "volatile std::bfloat16_t" });
        CHECK(cpp_util::arithmetic_type_to_name<const volatile std::bfloat16_t>() == std::string_view{ "const volatile std::bfloat16_t" });
#endif
    }
}

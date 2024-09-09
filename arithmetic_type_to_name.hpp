/**
 * Copyright (C) 2024 - Marcel Breyer - All Rights Reserved
 * Licensed under the MIT License. See LICENSE.md file in the project root for full license information.
 *
 * Implements a function to convert any cv-qualified arithmetic type to its name.
 */

#ifndef CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_HPP
#define CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_HPP

#if __has_include(<stdfloat>)
#include <stdfloat>  // std::float16_t, std::float32_t, std::float64_t, std::float128_t, std::bfloat16_t
#endif

#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard) && __cplusplus > 201700
#define ARITHMETIC_TYPE_TO_NAME_NODISCARD [[nodiscard]]
#else
#define ARITHMETIC_TYPE_TO_NAME_NODISCARD
#endif

#if defined(__cpp_constexpr)
#define ARITHMETIC_TYPE_TO_NAME_CONSTEXPR constexpr
#else
#define ARITHMETIC_TYPE_TO_NAME_CONSTEXPR
#endif

#if defined(CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_USE_CONST_CHAR_PTR)
#define ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE const char *
#else
#include <string_view>  // std::string_view

#define ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE std::string_view
#endif

namespace cpp_util {

#define CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(type)                                                                                                                                      \
  template <>                                                                                                                                                                           \
  ARITHMETIC_TYPE_TO_NAME_NODISCARD ARITHMETIC_TYPE_TO_NAME_CONSTEXPR inline ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE arithmetic_type_to_name<type>() { return #type; }                      \
  template <>                                                                                                                                                                           \
  ARITHMETIC_TYPE_TO_NAME_NODISCARD ARITHMETIC_TYPE_TO_NAME_CONSTEXPR inline ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE arithmetic_type_to_name<const type>() { return "const " #type; }       \
  template <>                                                                                                                                                                           \
  ARITHMETIC_TYPE_TO_NAME_NODISCARD ARITHMETIC_TYPE_TO_NAME_CONSTEXPR inline ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE arithmetic_type_to_name<volatile type>() { return "volatile " #type; } \
  template <>                                                                                                                                                                           \
  ARITHMETIC_TYPE_TO_NAME_NODISCARD ARITHMETIC_TYPE_TO_NAME_CONSTEXPR inline ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE arithmetic_type_to_name<const volatile type>() { return "const volatile " #type; }


/*******************************************************************************************************************/
/**                                            base template (deleted)                                            **/
/*******************************************************************************************************************/
template<typename T>
ARITHMETIC_TYPE_TO_NAME_NODISCARD ARITHMETIC_TYPE_TO_NAME_CONSTEXPR inline ARITHMETIC_TYPE_TO_NAME_RETURN_TYPE arithmetic_type_to_name() = delete;

/*******************************************************************************************************************/
/**                                                 boolean types                                                 **/
/*******************************************************************************************************************/
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(bool)

/*******************************************************************************************************************/
/**                                                character types                                                **/
/*******************************************************************************************************************/
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(char)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(signed char)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(unsigned char)
#if defined(__cpp_char8_t)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(char8_t)
#endif
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(char16_t)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(char32_t)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(wchar_t)

/*******************************************************************************************************************/
/**                                                 integer types                                                 **/
/*******************************************************************************************************************/
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(short)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(unsigned short)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(int)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(unsigned int)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(long)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(unsigned long)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(long long)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(unsigned long long)

/*******************************************************************************************************************/
/**                                             floating point types                                              **/
/*******************************************************************************************************************/
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(float)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(double)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(long double)

/*******************************************************************************************************************/
/**                                       fixed-width floating point types                                        **/
/*******************************************************************************************************************/
#if defined(__STDCPP_FLOAT16_T__)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(std::float16_t)
#endif
#if defined(__STDCPP_FLOAT32_T__)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(std::float32_t)
#endif
#if defined(__STDCPP_FLOAT64_T__)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(std::float64_t)
#endif
#if defined(__STDCPP_FLOAT128_T__)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(std::float128_t)
#endif
#if defined(__STDCPP_BFLOAT16_T__)
CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME(std::bfloat16_t)
#endif

#undef CPP_UTIL_CREATE_ARITHMETIC_TYPE_NAME

}

#endif  // CPP_UTIL_ARITHMETIC_TYPE_TO_NAME_HPP

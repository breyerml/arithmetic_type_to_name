#include "arithmetic_type_to_name.hpp"

#include <iostream>  // std::cout

#if __has_include(<stdfloat>)
#include <stdfloat>  // std::float16_t, std::float32_t, std::float64_t, std::float128_t, std::bfloat16_t
#endif

int main() {

    std::cout << cpp_util::arithmetic_type_to_name<bool>() << "\n\n";

    std::cout << cpp_util::arithmetic_type_to_name<const char>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<volatile signed char>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const volatile unsigned char>() << '\n';
#if defined(__cpp_char8_t)
    std::cout << cpp_util::arithmetic_type_to_name<char8_t>() << '\n';
#endif
    std::cout << cpp_util::arithmetic_type_to_name<const char16_t>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<volatile char32_t>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const volatile wchar_t>() << "\n\n";

    std::cout << cpp_util::arithmetic_type_to_name<short>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const unsigned short>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<volatile int>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const volatile unsigned int>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<long>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const unsigned long>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<volatile long long>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const volatile unsigned long long>() << "\n\n";

    std::cout << cpp_util::arithmetic_type_to_name<float>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<const double>() << '\n';
    std::cout << cpp_util::arithmetic_type_to_name<volatile long double>() << "\n\n";

#if defined(__STDCPP_FLOAT16_T__)
    std::cout << cpp_util::arithmetic_type_to_name<const volatile std::float16_t>() << '\n';
#endif
#if defined(__STDCPP_FLOAT32_T__)
    std::cout << cpp_util::arithmetic_type_to_name<std::float32_t>() << '\n';
#endif
#if defined(__STDCPP_FLOAT64_T__)
    std::cout << cpp_util::arithmetic_type_to_name<const std::float64_t>() << '\n';
#endif
#if defined(__STDCPP_FLOAT128_T__)
    std::cout << cpp_util::arithmetic_type_to_name<volatile std::float128_t>() << '\n';
#endif
#if defined(__STDCPP_BFLOAT16_T__)
    std::cout << cpp_util::arithmetic_type_to_name<const volatile std::bfloat16_t>() << '\n';
#endif

    return 0;
}

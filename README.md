# cpp_util::arithmetic_type_to_name

[![Test with GCC, Clang and MSVC](https://github.com/breyerml/arithmetic_type_to_name/actions/workflows/compiler_test.yml/badge.svg)](https://github.com/breyerml/arithmetic_type_to_name/actions/workflows/compiler_test.yml)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Implementation of a function to convert any cv-qualified arithmetic type to its name. 
The arithmetic type names are defined by [`std::is_arithmetic`](https://en.cppreference.com/w/cpp/types/is_arithmetic).

## Prerequisites

Any compiler supporting `C++17` should be sufficient (for more information see [Compiler Support](#compiler-support)).
Additionally, at least [CMake](https://cmake.org/) `3.30` is required.

The tests are implemented using [Catch2](https://github.com/catchorg/Catch2/tree/v2.x), which gets shipped as single header file with this repository.

## Building and Running the Examples

Building with GCC, Clang, or MSVC can be done using CMake presets.

```bash
git clone git@github.com:breyerml/arithmetic_type_to_name.git
cd arithmetic_type_to_name
cmake --preset [preset] .
cmake --build --preset [preset]
./build/arithmetic_type_to_name
```

Where `[preset]` is one of `gcc`, `clang`, or `msvc`.

## Building and Running the Tests

To additionally build the tests and run them use:

```bash
cmake --preset [preset] -DCPP_UTIL_ENABLE_TESTS .
cmake --build --preset [preset]
ctest --preset [preset]
```

Tests for all supported `C++` standards starting with `C++17` for the currently used compiler are generated.

## Compiler Support

The `cpp_util::arithmetic_type_to_name` has been tested with the following compilers, all installed using the respective package
manager and GitHub actions (other compilers or compiler versions may also be supported):

| Compiler | Versions                               |
|----------|----------------------------------------|
| GCC      | 9.5.0, 10.5.0, 11.4.0, 12.3.0          |
| Clang    | 11.1.0, 12.0.1, 13.0.1, 14.0.0, 15.0.7 |
| MSVC     | 19.29.30154.0                          |

All tests were run using the following compiler flags:

- GCC: `-Wall -Wextra -Wpedantic -Werror`

- Clang: `-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Werror`
  - `-Wno-c++98-compat -Wno-c++98-compat-pedantic`: since `C++98` is not supported

- MSVC:  `/W4 /EHsc /WX`

## Compiler Standard Version

- `C++17`:
  - the minimum required standard version

- `C++20`:
  - add support for `char8_t`

- `C++23`:
  - add support for fixed width floating-point types (`std::float16_t`, `std::float32_t`, `std::float64_t`, `std::float128_t`, and `std::bfloat16_t`)

The actual features are enabled using the specific features test macros and not the `__cplusplus` macro.

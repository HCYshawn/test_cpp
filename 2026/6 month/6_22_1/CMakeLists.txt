cmake_minimum_required(VERSION 3.18)

project(StrUtils
    VERSION 0.1.0
    DESCRIPTION "A header-only string utility library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(STRUTILS_BUILD_TESTS "Build unit tests" ON)
option(STRUTILS_BUILD_EXAMPLES "Build example program" ON)

add_library(strutils INTERFACE)

target_include_directories(strutils INTERFACE
    $<BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE: include>
)

target_compile_options(strutils INTERFACE
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-O0>
)

if(STRUTILS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(STRUTILS_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()


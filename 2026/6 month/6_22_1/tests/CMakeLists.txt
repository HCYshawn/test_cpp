add_executable(test_strutils)

target_sources(test_strutils PRIVATE test_strutils.cpp)

target_link_libraries(test_strutils PRIVATE strutils)

include(CTest)
add_test(NAME strutils_test COMMAND test_strutils)
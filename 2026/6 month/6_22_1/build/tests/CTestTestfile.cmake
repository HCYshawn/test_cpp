# CMake generated Testfile for 
# Source directory: D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests
# Build directory: D:/Code collection/Daily code/2026 year/6 month/6_22_1/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(strutils_test "D:/Code collection/Daily code/2026 year/6 month/6_22_1/build/tests/Debug/test_strutils.exe")
  set_tests_properties(strutils_test PROPERTIES  _BACKTRACE_TRIPLES "D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;8;add_test;D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(strutils_test "D:/Code collection/Daily code/2026 year/6 month/6_22_1/build/tests/Release/test_strutils.exe")
  set_tests_properties(strutils_test PROPERTIES  _BACKTRACE_TRIPLES "D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;8;add_test;D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(strutils_test "D:/Code collection/Daily code/2026 year/6 month/6_22_1/build/tests/MinSizeRel/test_strutils.exe")
  set_tests_properties(strutils_test PROPERTIES  _BACKTRACE_TRIPLES "D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;8;add_test;D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(strutils_test "D:/Code collection/Daily code/2026 year/6 month/6_22_1/build/tests/RelWithDebInfo/test_strutils.exe")
  set_tests_properties(strutils_test PROPERTIES  _BACKTRACE_TRIPLES "D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;8;add_test;D:/Code collection/Daily code/2026 year/6 month/6_22_1/tests/CMakeLists.txt;0;")
else()
  add_test(strutils_test NOT_AVAILABLE)
endif()

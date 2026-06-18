add_executable(calc main.cpp)

target_link_libraries(calc PRIVATE MyMath)

set_target_properties(calc PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
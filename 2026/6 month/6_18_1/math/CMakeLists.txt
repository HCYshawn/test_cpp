file(GLOB SRCS src/*.cpp)

add_library(MyMath STATIC ${SRCS})

target_include_directories(MyMath PUBLIC include)

set_target_properties(MyMath PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

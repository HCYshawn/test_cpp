file(GLOB MATH_SOURCES src/*.cpp)

add_library(MyMath STATIC ${MATH_SOURCES})

target_include_directories(MyMath PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


cmake_minimum_required(VERSION 3.18)

project(ShapeConsumer
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shape_user main.cpp)

find_package(Shape REQUIRED)

target_link_libraries(shape_user PRIVATE Shape::Shape)
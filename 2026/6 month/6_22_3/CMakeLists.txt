cmake_minimum_required(VERSION 3.18)

project(ShapeConsumer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 从安装目录找到 Shape 库
find_package(Shape REQUIRED)

add_executable(shape_consumer)
target_sources(shape_consumer PRIVATE main.cpp)
target_link_libraries(shape_consumer PRIVATE Shape::Shape)

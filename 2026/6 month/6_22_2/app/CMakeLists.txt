add_executable(shape_app)

target_sources(shape_app PRIVATE main.cpp)

target_link_libraries(shape_app PRIVATE Shape)
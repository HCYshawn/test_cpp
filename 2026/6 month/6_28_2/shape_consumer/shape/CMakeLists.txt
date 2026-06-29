file(GLOB SHAPE_SOURCES src/*.cpp)

add_library(Shape SHARED ${SHAPE_SOURCES})

target_include_directories(Shape PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(Shape PRIVATE SHAPE_BUILDING_LIBRARY)

set_target_properties(Shape PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    OUTPUT_NAME shape
)

install(TARGETS Shape
    EXPORT ShapeTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/shape
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT ShapeTargets
    FILE ShapeTargets.cmake
    NAMESPACE Shape::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Shape
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/ShapeConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ShapeConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Shape
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ShapeConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ShapeConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ShapeConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Shape
)
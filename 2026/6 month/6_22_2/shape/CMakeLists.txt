file(GLOB SHAPE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(Shape SHARED ${SHAPE_SOURCES})

target_include_directories(Shape PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_definitions(Shape PRIVATE SHAPE_EXPORTS)

set_target_properties(Shape PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
    OUTPUT_NAME shape
)

include(GNUInstallDirs)

install(TARGETS Shape
    EXPORT      ShapeTargets
    LIBRARY     DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE     DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME     DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/
    TYPE INCLUDE
)

install(EXPORT ShapeTargets
    NAMESPACE   Shape::
    FILE ShapeTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Shape
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ShapeConfig.cmake.in
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
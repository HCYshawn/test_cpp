#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Shape::Shape" for configuration "Release"
set_property(TARGET Shape::Shape APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Shape::Shape PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/shape.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/shape.dll"
  )

list(APPEND _cmake_import_check_targets Shape::Shape )
list(APPEND _cmake_import_check_files_for_Shape::Shape "${_IMPORT_PREFIX}/lib/shape.lib" "${_IMPORT_PREFIX}/bin/shape.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

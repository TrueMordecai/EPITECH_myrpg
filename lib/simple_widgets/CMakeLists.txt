cmake_minimum_required(VERSION 3.0.0)

# include the Simple Widgets Library specific macros
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros.cmake)

# determine whether to create a debug or release build
sw_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

# setup version numbers
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(SimpleWidgets
    VERSION ${VERSION}
    LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# include the config file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake)

# add an option for choosing the build type (shared or static)
sw_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build Simple Widgets as a shared library, FALSE to build it as a static library")

# add an option for building the API documentation
sw_set_option(SW_BUILD_DOC FALSE BOOL "TRUE to generate the API documentation, FALSE to ignore it")

# enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# add ./cmake/modules to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# find dependencies
find_package(CSFML 2.1 COMPONENTS system window graphics REQUIRED)
if (NOT DEFINED LIBMY_LIBRARIES OR NOT DEFINED LIBMY_INCLUDE_DIR)
    find_package(LibMy 0.3.0 COMPONENTS my-memory my-collections REQUIRED)
endif()

message("libmy include dir: ${LIBMY_INCLUDE_DIR}")

# add the sources
add_subdirectory(src)

# build documentation
if (SW_BUILD_DOC)
    add_subdirectory(doc)
endif()

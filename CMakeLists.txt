cmake_minimum_required(VERSION 3.9.0)

project(MyRPG C)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

# Add ./cmake/modules to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# Unit Testing
if (BUILD_TEST_SUITE)
    # Check for Criterion
    find_package(Criterion REQUIRED)
    set(LIBMY_BUILD_TEST_SUITE TRUE)
    if (USE_GCOV)
        set(LIBMY_USE_CCOV TRUE)
    endif()
    enable_testing()
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    # Compile Options
    add_compile_options(
       "-Wall" "-Wextra" "-Wshadow"
       "$<$<CONFIG:RELEASE>:-O3;-fno-builtin>"
       "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
    )

    # Enable test coverage
    if (USE_GCOV)
        add_link_options("-lgcov" "--coverage")
        add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    endif()
endif()

set(BUILD_SHARED_LIBS FALSE)
set(LIBMY_LIBRARIES $<TARGET_FILE:my-memory> $<TARGET_FILE:my-collections>)
set(LIBMY_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/my/include")

# LibMy dependency
set(LIBMY_MODULES
    ascii
    collections
    hash
    io
    memory
    parsing
    printf
)
set(LIBMY_ALLOWED_FUNCTIONS
    malloc_free
    open
    read
    write
    close
)
add_subdirectory(lib/my)

# MyPhysics dependency
add_subdirectory(lib/my_physics)

# SimpleWidgets dependency
add_subdirectory(lib/simple_widgets)

# External dependencies
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
find_package(CSFML 2.1 COMPONENTS system window graphics audio REQUIRED)

# Main Target
add_subdirectory(src)

if (BUILD_TEST_SUITE)
    add_subdirectory(tests)
endif()

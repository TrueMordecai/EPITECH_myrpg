cmake_minimum_required(VERSION 3.9.0)

project(MyRPG C)

# LibMy dependency
set(BUILD_SHARED_LIBS FALSE)
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
set(BUILD_SHARED_LIBS FALSE)
set(LIBMY_LIBRARIES $<TARGET_FILE:my-memory> $<TARGET_FILE:my-collections>)
set(LIBMY_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/my/include")
add_subdirectory(lib/my_physics)

# Unit Testing
if (BUILD_TEST_SUITE)
    set(LIBMY_BUILD_TEST_SUITE TRUE)
    enable_testing()
endif()

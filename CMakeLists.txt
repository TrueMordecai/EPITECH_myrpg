cmake_minimum_required(VERSION 3.9.0)

project(MyRPG C)

# Unix Testing
if (BUILD_TEST_SUITE)
    set(LIBMY_BUILD_TEST_SUITE TRUE)
    enable_testing()
endif()

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

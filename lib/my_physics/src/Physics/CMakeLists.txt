set(INCROOT ${PROJECT_SOURCE_DIR}/include/Physics)

# top-level source
set(SRC
    ${INCROOT}/physics.h
)

# subdirectories
add_subdirectory(Body)
add_subdirectory(Collisions)
add_subdirectory(Constants)
add_subdirectory(DynamicTree)
add_subdirectory(Filter)
add_subdirectory(Fixture)
add_subdirectory(JumpTable)
add_subdirectory(MassData)
add_subdirectory(Raycast)
add_subdirectory(Shapes)
add_subdirectory(Utils)
add_subdirectory(World)

# IDE source group
source_group("" FILES ${SRC})

# create the library target
if (BUILD_SHARED_LIBS)
    add_library(physics ${SRC})
else()
    add_library(physics STATIC ${SRC})

    # copy static library to project root after build
    add_custom_command(TARGET matchstick 
    	POST_BUILD
    	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:matchstick> ${PROJECT_SOURCE_DIR})
endif()

# setup dependencies
target_link_libraries(physics PRIVATE ${LIBMY_LIBRARIES})
include_directories(${LIBMY_INCLUDE_DIR})

# set include directory
target_include_directories(physics PUBLIC "${PROJECT_SOURCE_DIR}/include")

# adjust output suffix depending on output type
if (BUILD_SHARED_LIBS)
    set_target_properties(physics PROPERTIES DEBUG_POSTFIX -debug)
else()
    set_target_properties(physics PROPERTIES DEBUG_POSTFIX -static-debug)
    set_target_properties(physics PROPERTIES RELEASE_POSTFIX -static)
    set_target_properties(physics PROPERTIES MINSIZEREL_POSTFIX -static)
    set_target_properties(physics PROPERTIES RELWITHDEBINFO_POSTFIX -static)
endif()

# set version and soverstion of the library target
set_target_properties(physics PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})
set_target_properties(physics PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# set the target's folder (for IDEs)
set_target_properties(physics PROPERTIES FOLDER "MyPhysics")

# if using gcc >= 4.0 or clang >= 3.0 on a non-Windows platform, we must hide public symbols by default
# (exported ones are explicitly marked)
if ((SW_COMPILER_GCC AND NOT SW_GCC_VERSION VERSION_LESS "4") OR (SW_COMPILER_CLANG AND NOT SW_CLANG_VERSION VERSION_LESS "3"))
    set_target_properties(physics PROPERTIES COMPILE_FLAGS -fvisibility=hidden)
endif()

# enable Warnings
if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(physics PRIVATE -O1 -Wall -Wextra -Wshadow)
endif()

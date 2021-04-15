set(INCROOT ${PROJECT_SOURCE_DIR}/include/sw)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

# top-level source
set(SRC
    ${INCROOT}/config.h
    ${INCROOT}/layout.h
    ${INCROOT}/state.h
    ${INCROOT}/types.h
    ${INCROOT}/widget.h
    ${SRCROOT}/layout.c
    ${SRCROOT}/layout2.c
    ${SRCROOT}/state.c
    ${SRCROOT}/widget.c
    ${SRCROOT}/widget2.c
    ${SRCROOT}/widget3.c
    ${SRCROOT}/widget4.c
    ${SRCROOT}/widget5.c
)

# subdirectories
add_subdirectory(layouts)
add_subdirectory(widgets)

# IDE source group
source_group("" FILES ${SRC})

# create the library target
if (BUILD_SHARED_LIBS)
    add_library(simple-widgets ${SRC})
else()
    add_library(simple-widgets STATIC ${SRC})
endif()

# setup dependencies
target_link_libraries(simple-widgets PRIVATE ${CSFML_LIBRARIES} ${LIBMY_LIBRARIES})
include_directories(${CSFML_INCLUDE_DIR} ${LIBMY_INCLUDE_DIR})

# set include directory
target_include_directories(simple-widgets PUBLIC "${PROJECT_SOURCE_DIR}/include")

# adjust output suffix depending on output type
if (BUILD_SHARED_LIBS)
    set_target_properties(simple-widgets PROPERTIES DEBUG_POSTFIX -debug)
else()
    set_target_properties(simple-widgets PROPERTIES DEBUG_POSTFIX -static-debug)
    set_target_properties(simple-widgets PROPERTIES RELEASE_POSTFIX -static)
    set_target_properties(simple-widgets PROPERTIES MINSIZEREL_POSTFIX -static)
    set_target_properties(simple-widgets PROPERTIES RELWITHDEBINFO_POSTFIX -static)
endif()

# set version and soverstion of the library target
set_target_properties(simple-widgets PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})
set_target_properties(simple-widgets PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# set the target's folder (for IDEs)
set_target_properties(simple-widgets PROPERTIES FOLDER "SimpleWidgets")

# if using gcc >= 4.0 or clang >= 3.0 on a non-Windows platform, we must hide public symbols by default
# (exported ones are explicitly marked)
if ((SW_COMPILER_GCC AND NOT SW_GCC_VERSION VERSION_LESS "4") OR (SW_COMPILER_CLANG AND NOT SW_CLANG_VERSION VERSION_LESS "3"))
    set_target_properties(simple-widgets PROPERTIES COMPILE_FLAGS -fvisibility=hidden)
endif()

# enable Warnings
if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(simple-widgets PRIVATE -O1 -Wall -Wextra -Wshadow)
endif()

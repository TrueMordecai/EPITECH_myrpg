set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SW_INCROOT ${PROJECT_SOURCE_DIR}/lib/simple_widgets/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC
    ${SRCROOT}/main.c
)

add_subdirectory(Drawables)
add_subdirectory(Functions)
add_subdirectory(GameEngine)
add_subdirectory(Rpg)
add_subdirectory(Settings)
add_subdirectory(States)

source_group("" FILES ${SRC})

add_executable(my_rpg ${SRC})
add_custom_command(TARGET my_rpg 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:my_rpg> ${PROJECT_SOURCE_DIR})

if (CMAKE_COMPILER_IS_GNUCC)
    if (LIBMY_USE_GCOV)
        set(GCOV_LINK_FLAGS "-lgcov --coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCOV_LINK_FLAGS}")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    endif()
    target_compile_options(my_rpg PRIVATE -O1 -Wall -Wextra -Wshadow)
endif()

target_link_libraries(my_rpg PRIVATE physics simple-widgets ${CSFML_LIBRARIES} my-ascii my-collections my-io my-memory my-parsing my-printf m)
include_directories(${CSFML_INCLUDE_DIR})
target_include_directories(my_rpg PRIVATE ${INCROOT} ${SW_INCROOT})

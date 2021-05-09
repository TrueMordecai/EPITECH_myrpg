set(SRCROOT "${PROJECT_SOURCE_DIR}/tests")

add_subdirectory(Functions)
add_subdirectory(GameEngine)

add_executable(test_my_rpg ${SRC})

source_group("" FILES ${SRC})
set_target_properties(test_my_rpg PROPERTIES FOLDER "tests")

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(test_my_rpg PRIVATE -Wall -Wextra)
endif()

target_link_libraries(test_my_rpg PRIVATE my_rpg_lib ${CRITERION_LIBRARIES})

# Link to gcov if build type is set to 'static'
if (CMAKE_COMPILER_IS_GNUCC AND USE_GCOV)
    target_link_libraries(test_my_rpg PRIVATE gcov)
endif()

add_test(test_my_rpg test_my_rpg)

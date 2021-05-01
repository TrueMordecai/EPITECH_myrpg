set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SW_INCROOT ${PROJECT_SOURCE_DIR}/lib/simple_widgets/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC)

add_subdirectory(Drawables)
add_subdirectory(Functions)
add_subdirectory(GameEngine)
add_subdirectory(Rpg)
add_subdirectory(Settings)
add_subdirectory(States)

source_group("" FILES ${SRC})

add_library(my_rpg_lib ${SRC})
add_executable(my_rpg ${SRCROOT}/main.c)

target_link_libraries(my_rpg_lib PUBLIC physics simple-widgets ${CSFML_LIBRARIES} my-ascii my-collections my-io my-memory my-parsing my-printf m)
target_link_libraries(my_rpg PRIVATE my_rpg_lib)

target_include_directories(my_rpg_lib PUBLIC ${INCROOT} ${CSFML_INCLUDE_DIR})

add_custom_command(TARGET my_rpg 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:my_rpg> ${PROJECT_SOURCE_DIR})

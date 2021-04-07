set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine)

add_subdirectory(asset_manager)
add_subdirectory(audio_manager)
add_subdirectory(settings)

set(SRC
    ${SRC}
    ${INCROOT}/game.h
    ${INCROOT}/game_head.h
    ${INCROOT}/state.h
    ${INCROOT}/types.h
    ${SRCROOT}/game.c
    ${SRCROOT}/state.c
    PARENT_SCOPE
)


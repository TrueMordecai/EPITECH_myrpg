set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/game)

set(SRC
    ${SRC}
    ${INCROOT}/game.h
    ${SRCROOT}/game.c
    ${SRCROOT}/game_state_stack.c
    PARENT_SCOPE
)

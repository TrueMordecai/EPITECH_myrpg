set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/state)

set(SRC
    ${SRC}
    ${INCROOT}/state.h
    ${SRCROOT}/state_destroy.c
    ${SRCROOT}/state_init.c
    ${SRCROOT}/state.c
    PARENT_SCOPE
)

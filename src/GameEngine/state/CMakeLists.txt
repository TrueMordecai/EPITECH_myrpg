set(INCROOT ${PROJECT_SOURCE_DIR}/include/GameEngine)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/GameEngine/state)

set(SRC
    ${SRC}
    ${INCROOT}/state.h
    ${SRCROOT}/state_destroy.c
    ${SRCROOT}/state_draw.c
    ${SRCROOT}/state_handle_events.c
    ${SRCROOT}/state_pause.c
    ${SRCROOT}/state_resume.c
    ${SRCROOT}/state_init.c
    ${SRCROOT}/state_update.c
    PARENT_SCOPE
)

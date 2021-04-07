set(INCROOT ${PROJECT_SOURCE_DIR}/include/States/Game)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/States/Game)

set(SRC
    ${SRC}
    ${INCROOT}/game_cst.h
    ${INCROOT}/game_state.h
    ${SRCROOT}/game_create.c
    ${SRCROOT}/game_cst.c
    ${SRCROOT}/game_destroy.c
    ${SRCROOT}/game_draw.c
    ${SRCROOT}/game_handle_input.c
    ${SRCROOT}/game_pause.c
    ${SRCROOT}/game_resume.c
    ${SRCROOT}/game_update.c
    PARENT_SCOPE
)

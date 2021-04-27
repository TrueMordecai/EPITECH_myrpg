set(INCROOT ${PROJECT_SOURCE_DIR}/include/States/GamePause)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/States/GamePause)

set(SRC
    ${SRC}
    ${INCROOT}/pause_cst.h
    ${INCROOT}/pause_state.h
    ${SRCROOT}/pause_create.c
    ${SRCROOT}/pause_cst.c
    ${SRCROOT}/pause_destroy.c
    ${SRCROOT}/pause_draw.c
    ${SRCROOT}/pause_handle_events.c
    ${SRCROOT}/pause_pause.c
    ${SRCROOT}/pause_resume.c
    ${SRCROOT}/pause_update.c
    PARENT_SCOPE
)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/States/Menu)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/States/Menu)

set(SRC
    ${SRC}
    ${INCROOT}/menu_cst.h
    ${INCROOT}/menu_state.h
    ${SRCROOT}/menu_btn_callbacks.c
    ${SRCROOT}/menu_create.c
    ${SRCROOT}/menu_cst.c
    ${SRCROOT}/menu_destroy.c
    ${SRCROOT}/menu_draw.c
    ${SRCROOT}/menu_handle_events.c
    ${SRCROOT}/menu_init_gui.c
    ${SRCROOT}/menu_pause.c
    ${SRCROOT}/menu_resume.c
    ${SRCROOT}/menu_update.c
    PARENT_SCOPE
)

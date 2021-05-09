set(INCROOT ${PROJECT_SOURCE_DIR}/include/States/Settings)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/States/Settings)

set(SRC
    ${SRC}
    ${INCROOT}/settings_state.h
    ${SRCROOT}/settings_adjust_button.c
    ${SRCROOT}/settings_body.c
    ${SRCROOT}/settings_create.c
    ${SRCROOT}/settings_destroy.c
    ${SRCROOT}/settings_display_button.c
    ${SRCROOT}/settings_draw.c
    ${SRCROOT}/settings_handle_events.c
    ${SRCROOT}/settings_init_gui.c
    ${SRCROOT}/settings_pause.c
    ${SRCROOT}/settings_resume.c
    ${SRCROOT}/settings_title.c
    ${SRCROOT}/settings_update.c
    PARENT_SCOPE
)

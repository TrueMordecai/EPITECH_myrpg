set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/Timeline/Frame)

set(SRC
    ${SRC}
    ${INCROOT}/timeline.h
    ${SRCROOT}/frame_destroy.c
    ${SRCROOT}/frame_draw.c
    ${SRCROOT}/frame_init.c
    ${SRCROOT}/frame_update.c
    PARENT_SCOPE
)
set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/Timeline)

add_subdirectory(Frame)
add_subdirectory(PlayingBubble)

set(SRC
    ${SRC}
    ${INCROOT}/timeline.h
    ${SRCROOT}/timeline_destroy.c
    ${SRCROOT}/timeline_draw.c
    ${SRCROOT}/timeline_init.c
    ${SRCROOT}/timeline_new_turn.c
    ${SRCROOT}/timeline_remove_frame.c
    ${SRCROOT}/timeline_update.c
    PARENT_SCOPE
)
set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/Timeline/PlayingBubble)

set(SRC
    ${SRC}
    ${INCROOT}/timeline.h
    ${SRCROOT}/playing_bubble_destroy.c
    ${SRCROOT}/playing_bubble_draw.c
    ${SRCROOT}/playing_bubble_init.c
    ${SRCROOT}/playing_bubble_update.c
    PARENT_SCOPE
)
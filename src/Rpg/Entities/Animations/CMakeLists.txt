set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Animations)

set(SRC
    ${SRC}
    ${INCROOT}/animations.h
    ${SRCROOT}/animations_destroy.c
    ${SRCROOT}/animations_init.c
    ${SRCROOT}/animations_set_animation.c
    ${SRCROOT}/animations_update.c
    PARENT_SCOPE
)

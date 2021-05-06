set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Player)

set(SRC
    ${SRC}
    ${INCROOT}/player.h
    ${SRCROOT}/player_create.c
    ${SRCROOT}/player_destroy.c
    ${SRCROOT}/player_draw.c
    ${SRCROOT}/player_init_physic.c
    ${SRCROOT}/player_update_equipement.c
    ${SRCROOT}/player_update.c
    PARENT_SCOPE
)

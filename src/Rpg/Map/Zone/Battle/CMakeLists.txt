set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Map)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Map/Zone/Battle)

set(SRC
    ${SRC}
    ${INCROOT}/map.h
    ${SRCROOT}/battle_compute_layer.c
    ${SRCROOT}/battle_draw.c
    ${SRCROOT}/battle_end.c
    ${SRCROOT}/battle_init.c
    ${SRCROOT}/battle_set_tactical.c
    ${SRCROOT}/battle_start.c
    PARENT_SCOPE
)

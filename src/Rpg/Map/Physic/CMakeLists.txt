set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Map)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Map/Physic)

set(SRC
    ${SRC}
    ${INCROOT}/physic.h
    ${SRCROOT}/physic_add_tile.c
    ${SRCROOT}/physic_add_zone_border.c
    PARENT_SCOPE
)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Map)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Map)

add_subdirectory(Physic)
add_subdirectory(Zone)

set(SRC
    ${SRC}
    ${INCROOT}/map.h
    ${SRCROOT}/map_create.c
    ${SRCROOT}/map_destroy.c
    ${SRCROOT}/map_draw.c
    ${SRCROOT}/map_load_zone.c
    ${SRCROOT}/map_move.c
    ${SRCROOT}/map_update.c
    ${SRCROOT}/map_zoom.c
    PARENT_SCOPE
)

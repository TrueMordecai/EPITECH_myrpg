set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Map)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Map/Zone)

add_subdirectory(Battle)
add_subdirectory(Layer)

set(SRC
    ${SRC}
    ${INCROOT}/zone.h
    ${SRCROOT}/zone_add_special.c
    ${SRCROOT}/zone_create.c
    ${SRCROOT}/zone_cst.c
    ${SRCROOT}/zone_destroy.c
    ${SRCROOT}/zone_draw.c
    ${SRCROOT}/zone_init.c
    ${SRCROOT}/zone_interract_move.c
    ${SRCROOT}/zone_interract.c
    ${SRCROOT}/zone_open_file.c
    ${SRCROOT}/zone_sort_layer.c
    PARENT_SCOPE
)

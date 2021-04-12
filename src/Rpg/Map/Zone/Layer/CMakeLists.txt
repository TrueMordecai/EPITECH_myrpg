set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Map)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Map/Zone/Layer)

set(SRC
    ${SRC}
    ${INCROOT}/layer.h
    ${SRCROOT}/layer_create.c
    ${SRCROOT}/layer_cst.c
    ${SRCROOT}/layer_destroy.c
    ${SRCROOT}/layer_draw.c
    ${SRCROOT}/layer_init.c
    ${SRCROOT}/layer_place_tile.c
    PARENT_SCOPE
)

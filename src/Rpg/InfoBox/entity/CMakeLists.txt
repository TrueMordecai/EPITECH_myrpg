set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/entity)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_entity.h
    ${SRCROOT}/infobox_entity_cst.c
    ${SRCROOT}/infobox_entity_destroy.c
    ${SRCROOT}/infobox_entity_draw.c
    ${SRCROOT}/infobox_entity_init.c
    ${SRCROOT}/infobox_entity_update.c
    PARENT_SCOPE
)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox)

add_subdirectory(entity)
add_subdirectory(spells)

set(SRC
    ${SRC}
    ${INCROOT}/infobox.h
    ${SRCROOT}/infobox_create.c
    ${SRCROOT}/infobox_destroy.c
    ${SRCROOT}/infobox_draw.c
    ${SRCROOT}/infobox_init.c
    ${SRCROOT}/infobox_resize.c
    ${SRCROOT}/infobox_text.c
    ${SRCROOT}/infobox_update.c
    PARENT_SCOPE
)

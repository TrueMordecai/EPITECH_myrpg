set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/SpellsBar)

set(SRC
    ${SRC}
    ${INCROOT}/spells_bar.h
    ${SRCROOT}/spells_bar_destroy.c
    ${SRCROOT}/spells_bar_draw.c
    ${SRCROOT}/spells_bar_handle_events.c
    ${SRCROOT}/spells_bar_init.c
    ${SRCROOT}/spells_bar_update_spells.c
    ${SRCROOT}/spells_bar_update.c
    PARENT_SCOPE
)
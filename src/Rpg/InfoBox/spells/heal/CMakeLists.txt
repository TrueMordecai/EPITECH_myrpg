set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/spells/heal)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_spell.h
    ${SRCROOT}/infobox_spell_heal_destroy.c
    ${SRCROOT}/infobox_spell_heal_draw.c
    ${SRCROOT}/infobox_spell_heal_init.c
    ${SRCROOT}/infobox_spell_heal_update.c
    PARENT_SCOPE
)

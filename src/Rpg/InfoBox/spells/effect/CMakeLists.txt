set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/spells/effect)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_spell.h
    ${SRCROOT}/infobox_spell_effect_destroy.c
    ${SRCROOT}/infobox_spell_effect_draw.c
    ${SRCROOT}/infobox_spell_effect_init.c
    ${SRCROOT}/infobox_spell_effect_update.c
    PARENT_SCOPE
)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/spells/debuff)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_spell.h
    ${SRCROOT}/infobox_spell_debuff_destroy.c
    ${SRCROOT}/infobox_spell_debuff_draw.c
    ${SRCROOT}/infobox_spell_debuff_init.c
    ${SRCROOT}/infobox_spell_debuff_update.c
    PARENT_SCOPE
)

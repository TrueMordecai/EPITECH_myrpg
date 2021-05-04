set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/spells/attack)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_spell.h
    ${SRCROOT}/infobox_spell_attack_destroy.c
    ${SRCROOT}/infobox_spell_attack_draw.c
    ${SRCROOT}/infobox_spell_attack_init.c
    ${SRCROOT}/infobox_spell_attack_update.c
    PARENT_SCOPE
)

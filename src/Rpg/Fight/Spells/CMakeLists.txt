set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/Spells)

set(SRC
    ${SRC}
    ${INCROOT}/spell.h
    ${SRCROOT}/spell_attack_parse.c
    ${SRCROOT}/spell_base_parse.c
    ${SRCROOT}/spell_create_from_file.c
    ${SRCROOT}/spell_debuff_parse.c
    ${SRCROOT}/spell_destroy.c
    ${SRCROOT}/spell_effect_parse.c
    ${SRCROOT}/spell_heal_parse.c
    ${SRCROOT}/spells_init.c
    PARENT_SCOPE
)
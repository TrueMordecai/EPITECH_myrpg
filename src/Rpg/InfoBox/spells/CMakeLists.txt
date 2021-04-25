set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/InfoBox)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/InfoBox/spells)

add_subdirectory(attack)
add_subdirectory(heal)
add_subdirectory(debuff)

set(SRC
    ${SRC}
    ${INCROOT}/infobox_spell.h
    ${SRCROOT}/infobox_spell_destroy.c
    ${SRCROOT}/infobox_spell_draw.c
    ${SRCROOT}/infobox_spell_init.c
    ${SRCROOT}/infobox_spell_update.c
    PARENT_SCOPE
)

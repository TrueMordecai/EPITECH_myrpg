set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight/Spells)

set(SRC
    ${SRC}
    ${INCROOT}/spell.h
    ${SRCROOT}/spell_create_from_file.c
    ${SRCROOT}/spell_base_parse.c
    PARENT_SCOPE
)
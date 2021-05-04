set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Quests)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Quests)

set(SRC
    ${SRC}
    ${INCROOT}/quests.h
    ${SRCROOT}/quests_engine.c
    ${SRCROOT}/quests_setup.c
    ${SRCROOT}/quests_parse_quests_info.c
    ${SRCROOT}/quests_get_file_info.c
    PARENT_SCOPE
)
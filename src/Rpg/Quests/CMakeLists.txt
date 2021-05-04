set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Quests)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Quests)

set(SRC
    ${SRC}
    ${INCROOT}/quests.h.h
    ${SRCROOT}/quests_engine.c
    ${SRCROOT}/quests_setup.c
    
    PARENT_SCOPE
)
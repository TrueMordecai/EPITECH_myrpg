set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Allies)

set(SRC
    ${SRC}
    ${INCROOT}/allies.h
    ${SRCROOT}/allies_add_ally.c
    ${SRCROOT}/allies_destroy.c
    ${SRCROOT}/allies_init.c
    PARENT_SCOPE
)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Stats)

set(SRC
    ${SRC}
    ${INCROOT}/stats.h
    ${SRCROOT}/stats_create.c
    ${SRCROOT}/stats_destroy.c
    ${SRCROOT}/stats_init.c
    ${SRCROOT}/stats_reset.c
    PARENT_SCOPE
)
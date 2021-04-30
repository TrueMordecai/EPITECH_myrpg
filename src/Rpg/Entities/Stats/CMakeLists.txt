set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Stats)

set(SRC
    ${SRC}
    ${INCROOT}/stats.h
    ${SRCROOT}/stats_apply_effects_2.c
    ${SRCROOT}/stats_apply_effects.c
    ${SRCROOT}/stats_compute_damages.c
    ${SRCROOT}/stats_create.c
    ${SRCROOT}/stats_destroy.c
    ${SRCROOT}/stats_init.c
    ${SRCROOT}/stats_level_up.c
    ${SRCROOT}/stats_reset.c
    ${SRCROOT}/stats_update.c
    PARENT_SCOPE
)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Entity/AI)

set(SRC
    ${SRC}
    ${SRCROOT}/entity_compute_move.c
    ${SRCROOT}/ai_get_allies.c
    ${SRCROOT}/ai_get_path.c
    ${SRCROOT}/ai_move.c
    ${SRCROOT}/ai_sight.c
    ${SRCROOT}/ai_flee_away.c
    PARENT_SCOPE
)
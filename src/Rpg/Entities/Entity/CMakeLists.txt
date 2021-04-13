set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Entities/Entity)

add_subdirectory(AI)

set(SRC
    ${SRC}
    ${INCROOT}/entity.h
    ${SRCROOT}/entity_create.c
    ${SRCROOT}/entity_destroy.c
    ${SRCROOT}/entity_draw.c
    ${SRCROOT}/entity_handle_events.c
    ${SRCROOT}/entity_init.c
    ${SRCROOT}/entity_move_possibilities.c
    ${SRCROOT}/entity_move.c
    ${SRCROOT}/entity_spell_sight.c
    ${SRCROOT}/entity_turn.c
    ${SRCROOT}/entity_update.c
    ${SRCROOT}/entity_attack.c
    PARENT_SCOPE
)
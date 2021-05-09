set(INCROOT ${PROJECT_SOURCE_DIR}/include/Rpg/Fight)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Rpg/Fight)

add_subdirectory(Spells)
add_subdirectory(Timeline)
add_subdirectory(SpellsBar)

set(SRC
    ${SRC}
    ${INCROOT}/fight.h
    ${SRCROOT}/cell_tests.c
    ${SRCROOT}/fight_create.c
    ${SRCROOT}/fight_destroy.c
    ${SRCROOT}/fight_draw.c
    ${SRCROOT}/fight_get_line.c
    ${SRCROOT}/fight_get_tile.c
    ${SRCROOT}/fight_handle_events.c
    ${SRCROOT}/fight_init_enemy.c
    ${SRCROOT}/fight_init_entities.c
    ${SRCROOT}/fight_pathfinding_2.c
    ${SRCROOT}/fight_pathfinding_nodes.c
    ${SRCROOT}/fight_pathfinding.c
    ${SRCROOT}/fight_pos_vec_conversions.c
    ${SRCROOT}/fight_rect_buff.c
    ${SRCROOT}/fight_show_sight.c
    ${SRCROOT}/fight_spawn_particles.c
    ${SRCROOT}/fight_turn.c
    ${SRCROOT}/fight_update.c
    PARENT_SCOPE
)

/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_update
*/

#include <libmy/printf.h>

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

int fight_rm_dead_entity(fight_t *fight, int id)
{
    entity_t *entity;

    if (id < 0 || fight->nb_entities <= id)
        return 0;
    entity = fight->entities[id];
    if (!entity || entity->alive > 0)
        return 0;
    fight->grid[entity->pos].entity = NULL;
    entity_update_spell_sight(fight->entities[fight->entity_turn]);
    timeline_remove_entity(&fight->timeline, entity);
    if (id == fight->entity_turn && fight_new_entity(fight))
        return 1;
    return fight_end(fight, 0);
}

int fight_rm_dead_entities(fight_t *fight)
{
    entity_t *entity;

    for (int i = 0; i < fight->nb_entities; i++) {
        entity = fight->entities[i];
        if (entity->alive <= 0 && fight->grid[entity->pos].entity == entity
            && fight_rm_dead_entity(fight, i))
            return 1;
    }
    return 0;
}

int fight_end(fight_t *fight, float dt)
{
    int ennemies = 0;
    int player = 0;

    for (int i = 0; i < fight->nb_entities; i++) {
        ennemies += (fight->entities[i]->alive > 0
            && fight->entities[i]->team == ENNEMIES);
        player += (fight->entities[i]->alive > 0
            && fight->entities[i]->type == PLAYER);
    }
    if (!ennemies || !player) {
        fight->end_timer += dt;
        if (fight->end_timer >= 1 && fight->end_timer - dt <= 1)
            play_sound(&fight->rpg->state->game_data->audio,
                (player) ? "fight_win" : "fight_lose");
        if (fight->end_timer >= 2) {
            battle_end(&fight->rpg->map->current_zone->battle);
            return 1;
        }
    }
    return 0;
}

static void update_infobox(fight_t *fight)
{
    if (fight->timeline.time_hovered >= INFO_WAIT
        && fight->timeline.hovered >= 0)
        infobox_update(&fight->infobox, INFOBOX_ENTITY,
            ((frame_t *)fight->timeline.frames.data + fight->timeline.hovered)
                ->entity);
    else if (fight->spells_bar.time_hovered >= INFO_WAIT
        && fight->spells_bar.current_hovered >= 0)
        infobox_update(&fight->infobox, INFOBOX_SPELL,
            MY_VEC_GET_ELEM(spell_base_t *,
                &fight->spells_bar.last_entity->spells,
                fight->spells_bar.current_hovered));
}

void fight_update(fight_t *fight, float dt)
{
    fight_reset_buff(fight);
    for (int i = 0; i < fight->nb_entities; i++) {
        entity_update(fight->entities[i], dt, i == fight->entity_turn);
        fight_spawn_particles(fight->entities[i], fight->rpg->state);
    }
    if (fight->entities[fight->entity_turn]->team == ENNEMIES
        && fight->entities[fight->entity_turn]->actions.length == 0)
        fight_new_entity(fight);
    if (fight_end(fight, dt))
        return;
    if (!fight_rm_dead_entities(fight)) {
        timeline_update(&fight->timeline, dt);
        spells_bar_update(
            &fight->spells_bar, fight->entities[fight->entity_turn], dt);
        update_infobox(fight);
    }
}

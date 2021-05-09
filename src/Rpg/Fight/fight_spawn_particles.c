/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Spanws status-effect particles
*/

#include "GameEngine/state.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"
#include "functions.h"
#include "GameEngine/particle_manager.h"

void do_spawn_particles(entity_t *entity, state_t *state)
{
    sfVector2f pos = fight_pos_to_world_vec(entity->fight, entity->pos);
    sfFloatRect b = sfRectangleShape_getGlobalBounds(entity->rect);
    sfFloatRect dims = sfSprite_getGlobalBounds(
        state->game_data->particles->sprites[PARTICLE_BOOST]);
    sfVector2f cpos = {pos.x + b.width / 2 - dims.width / 2,
        pos.y + b.height / 2 - dims.height / 2};
    particle_t particle = {
        .position =
            (sfVector2f){get_rand(cpos.x - b.width / 2, cpos.x + b.width / 2),
                get_rand(cpos.y - b.height / 2, cpos.y)},
        .color = sfColor_fromRGBA(255, 255, 255, 100),
        .duration = 0.8,
        .speed = 40,
        .type = PARTICLE_BOOST,
    };

    particle_manager_spawn(state->game_data->particles, particle);
}

void fight_spawn_particles(entity_t *entity, state_t *state)
{
    bool has_boost = false;
    effect_t *effects = entity->stats->effects.data;
    size_t len = entity->stats->effects.length;

    if (get_randi(0, 100) > 5)
        return;
    for (size_t i = 0; i < len; ++i) {
        if (effects[i].spell->type & EFFECT_BOOST) {
            has_boost = true;
            break;
        }
    }
    if (has_boost)
        do_spawn_particles(entity, state);
}

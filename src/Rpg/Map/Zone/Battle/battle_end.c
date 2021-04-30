/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle end
*/

#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

void battle_end(battle_t *battle)
{
    battle->pos = (sfVector2i){0, 0};
    battle->size = battle->zone->size;
    map_reset_zoom(battle->zone->map);
    battle->zone->is_battle = 0;
    if (battle->player->entity->alive == 1) {
        stats_gain_xp(battle->player->entity->stats, 51);
        play_sound(&battle->fight->rpg->state->game_data->audio, "fight_win");
    } else
        play_sound(&battle->fight->rpg->state->game_data->audio, "fight_lose");
    fight_destroy(battle->fight);
    battle->player->body->velocity = (pe_vec2f_t){0, 0};
    battle->player->body->force = (pe_vec2f_t){0, 0};
    battle->player->dir = (sfVector2i){0, 0};
    battle->player->entity->anim.paused = 0;
    battle->fight = NULL;
}
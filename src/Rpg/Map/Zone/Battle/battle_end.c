/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle end
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

static void remove_dead_allies(battle_t *battle)
{
    allies_t *allies = &battle->zone->map->rpg->allies;
    entity_t *ally;

    for (size_t i = 0; i < allies->allies.length; i++) {
        ally = MY_VEC_GET_ELEM(entity_t *, &allies->allies, i);
        if (ally->alive != 1) {
            entity_destroy(ally);
            my_vec_remove(&allies->allies, NULL, i--);
        }
    }
}

static void validate_boss_kill(battle_t *battle)
{
    if (battle->zone->id != 2)
        return;
    quests_validate(&battle->fight->rpg->quests);
}

void battle_end(battle_t *battle)
{
    battle->pos = (sfVector2i){0, 0};
    battle->size = battle->zone->size;
    map_reset_zoom(battle->zone->map);
    battle->zone->is_battle = 0;
    if (battle->player->entity->alive == 1) {
        stats_gain_xp(battle->player->entity->stats, 51);
        validate_boss_kill(battle);
    } else
        sfRectangleShape_setFillColor(battle->player->entity->rect, sfWhite);
    fight_destroy(battle->fight);
    remove_dead_allies(battle);
    battle->player->body->velocity = (pe_vec2f_t){0, 0};
    battle->player->body->force = (pe_vec2f_t){0, 0};
    battle->player->dir = (sfVector2i){0, 0};
    battle->player->entity->anim.paused = 0;
    battle->fight = NULL;
}

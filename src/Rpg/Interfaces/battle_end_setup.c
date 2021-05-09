/*
** EPITECH PROJECT, 2021
** battle_end_setup.c
** File description:
** rpg
*/

#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"

struct fight_t;

static void battle_end_setup_new_item(struct battle_t *b)
{
    int total = 0;

    for (unsigned int i = 0; i < b->fight->nb_entities; i++) {
        if (b->fight->entities[i]->team == ENNEMIES) {
            total += b->fight->entities[i]->stats->level;
            b->fight->rpg->battle_end.enemy_number++;
        }
    }
    b->fight->rpg->battle_end.average_level =
        total / b->fight->rpg->battle_end.enemy_number;
    if (b->fight->rpg->battle_end.average_level <= 0)
        b->fight->rpg->battle_end.average_level = 1;
}

extern void battle_end_setup(struct battle_t *battle)
{
    rpg_t *r = battle->fight->rpg;

    battle->fight->rpg->battle_end.is_on = true;
    battle->fight->rpg->battle_end.is_item_add = false;
    if (r->player->entity->alive == 1) {
        sfSprite_setTextureRect(r->battle_end.menu_sprite, (sfIntRect){0, 0, 112, 32});
        battle_end_setup_new_item(battle);
        r->battle_end.is_win = true;
    } else {
        sfSprite_setTextureRect(r->battle_end.menu_sprite, (sfIntRect){0, 32, 112, 32});
        r->battle_end.is_win = false;
    }
}

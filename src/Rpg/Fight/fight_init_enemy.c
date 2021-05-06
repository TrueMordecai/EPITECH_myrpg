/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_create
*/

#include <libmy/printf.h>
#include <stdlib.h>

#include "Rpg/Entities/player.h"
#include "Rpg/Fight/fight.h"
#include "Rpg/Map/battle.h"
#include "Rpg/rpg.h"
#include "functions.h"

static void set_texture_and_spells(fight_t *fight, entity_t *entity)
{
    int texture = get_randi(0, 1);
    int spell = get_randi(0, 1);
    sfColor color = sfWhite;

    if (entity->type == ENNEMY_CAC) {
        if (texture == 0)
            color = sfColor_fromRGB(
                get_randi(50, 255), get_randi(50, 255), get_randi(50, 255));
        entity_init_rect(entity, (texture == 0) ? "Skeleton" : "Lion", color);
        entity_add_spell(
            entity, get_spell(fight->rpg, (spell) ? "punch" : "scratch"));
    } else {
        entity_init_rect(entity, (texture == 0) ? "Dog" : "Frog", color);
        entity_add_spell(
            entity, get_spell(fight->rpg, (spell) ? "dist" : "dist2"));
    }
}

int fight_init_enemy(fight_t *fight, int pos, int *id)
{
    zone_t *zone = fight->rpg->map->current_zone;
    int zone_level =
        2.5 * (1 + ((zone->mother_zone != -1) ? zone->mother_zone : zone->id));

    if (pos == -1) {
        (*id)--;
        return 1;
    }
    fight->entities[*id + 1] =
        entity_create(NULL, ENNEMY_CAC + get_randi(0, 1), ENNEMIES, pos);
    fight->grid[pos].entity = fight->entities[*id + 1];
    fight->entities[*id + 1]->stats = stats_create();
    fight->entities[*id + 1]->fight = fight;
    set_texture_and_spells(fight, fight->entities[*id + 1]);
    stats_init_from_level(fight->entities[*id + 1]->stats,
        get_randi(zone_level - 2, zone_level + 2));
    animations_update_rect(&fight->entities[*id + 1]->anim);
    return 0;
}
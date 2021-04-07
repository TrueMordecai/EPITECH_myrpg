/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ally_draw_move
*/

#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

void ally_draw_move_possibilities(fight_t *fight)
{
    entity_t *entity = fight->entities[fight->entity_turn];
    int pm = entity->stats->current_pm;
    sfVector2i pos = fight_pos_to_vec(fight, entity->pos, 0);
    int y_diff;

    if (entity->type == ENNEMY)
        return;
    for (int y = pos.y - pm; y <= pos.y + pm; y++) {
        y_diff = pm - abs(pos.y - y);
        for (int x = pos.x - y_diff; x <= pos.x + y_diff; x++)
            fight_place_rect(fight, \
            fight_xy_to_pos(fight, x, y), sfGreen, WALKABLE);
    }
}
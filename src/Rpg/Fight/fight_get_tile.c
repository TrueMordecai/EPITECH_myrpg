/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_get_tile
*/

#include <stdlib.h>
#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

static int get_cell(fight_t *fight, int x, int y, int test)
{
    int pos = fight_xy_to_pos(fight, x, y);

    if (pos == INEXISTING)
        return INEXISTING;
    if ((test & WALKABLE) && !cell_is_walkable(&fight->grid[pos]))
        return INEXISTING;
    if ((test & OCCUPIED) && !cell_is_occupied(&fight->grid[pos]))
        return INEXISTING;
    if ((test & C_EMPTY) && !cell_is_empty(&fight->grid[pos]))
        return INEXISTING;
    return pos;
}

int *fight_get_range(fight_t *fight, int from, int range, int test)
{
    int *cells;
    int y_diff;
    sfVector2i pos = fight_pos_to_vec(fight, from, 0);
    int i = 0;

    if (from == -1 || range < 0)
        return NULL;
    cells = malloc(sizeof(int) * (2 + (range * (range + 1)) * 2));
    for (int y = pos.y - range; y <= pos.y + range; y++) {
        y_diff = range - abs(pos.y - y);
        for (int x = pos.x - y_diff; x <= pos.x + y_diff; x++) {
            cells[i++] = get_cell(fight, x, y, test);
        }
    }
    cells[i] = END_ARRAY;
    return cells;
}

int fight_get_mouse_tile(fight_t *fight)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(fight->rpg->wind);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(
        fight->rpg->wind, mouse_pos, fight->rpg->map->view);

    return fight_world_vec_to_pos(fight, world_pos);
}

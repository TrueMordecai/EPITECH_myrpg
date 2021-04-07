/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_get_tile
*/

#include "Rpg/rpg.h"
#include "Rpg/Fight/fight.h"
#include "My/my_display.h"

int fight_get_mouse_tile(fight_t *fight)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(fight->rpg->wind);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(fight->rpg->wind, \
    mouse_pos, fight->rpg->map->view);

    return fight_world_vec_to_pos(fight, world_pos);
}
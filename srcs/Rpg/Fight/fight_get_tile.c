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
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(fight->rpg->wind, mouse_pos, fight->rpg->map->view);
    sfVector2i tile_pos = {world_pos.x / fight->rpg->map->tiles_size, world_pos.y / fight->rpg->map->tiles_size};

    tile_pos.x -= fight->rpg->map->current_zone->battle.pos.x;
    tile_pos.y -= fight->rpg->map->current_zone->battle.pos.y;
    my_print("Pos (%d, %d)\n", tile_pos.x, tile_pos.y);
    return tile_pos.x + tile_pos.y * fight->size.x;
}
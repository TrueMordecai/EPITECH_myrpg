/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** fight_pos_vec_conversions
*/

#include "Rpg/Fight/fight.h"
#include "Rpg/rpg.h"

sfVector2i fight_pos_to_vec(fight_t *fight, int pos, int world)
{
    sfVector2i vec = {pos % fight->size.x, pos / fight->size.x};

    if (world) {
        vec.x += fight->pos.x;
        vec.y += fight->pos.y;
    }
    return vec;
}

sfVector2f fight_pos_to_world_vec(fight_t *fight, int pos)
{
    int ts = fight->rpg->map->tiles_size;
    sfVector2i pos_i = fight_pos_to_vec(fight, pos, 1);

    return (sfVector2f){pos_i.x * ts, pos_i.y * ts};
}

int fight_vec_to_pos(fight_t *fight, sfVector2i vec)
{
    if (vec.x < 0 || vec.x >= fight->size.x || vec.y < 0
        || vec.y >= fight->size.y)
        return INEXISTING;
    return vec.x + vec.y * fight->size.x;
}

int fight_xy_to_pos(fight_t *fight, int x, int y)
{
    return fight_vec_to_pos(fight, (sfVector2i){x, y});
}

int fight_world_vec_to_pos(fight_t *fight, sfVector2f world_vec)
{
    sfVector2i tile_pos = {world_vec.x / fight->rpg->map->tiles_size,
        world_vec.y / fight->rpg->map->tiles_size};

    tile_pos.x -= fight->pos.x;
    tile_pos.y -= fight->pos.y;
    if (tile_pos.x < 0 || tile_pos.x >= fight->size.x || tile_pos.y < 0
        || tile_pos.y >= fight->size.y)
        return INEXISTING;
    return tile_pos.x + tile_pos.y * fight->size.x;
}

/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** battle compute layer
*/

#include "Rpg/rpg.h"

static sfRectangleShape *init_rect(int flags, int x, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = sfWhite;
    int color_value = 70;

    if (flags == SOLID)
        color = sfBlack;
    else if (flags == TRANSPARENT)
        color = sfColor_fromRGB(40, 40, 40);
    else
        color = sfColor_fromRGB(color_value, color_value, color_value);
    sfRectangleShape_setSize(rect, (sfVector2f){M_TO_PX, M_TO_PX});
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, (sfVector2f){x * M_TO_PX, y * M_TO_PX});
    sfRectangleShape_setOutlineColor(rect, sfColor_fromRGB(50, 50, 50));
    sfRectangleShape_setOutlineThickness(rect, -0.5);
    return rect;
}

void battle_compute_layer(battle_t *battle)
{
    if (!battle->zone)
        return;
    layer_init(battle->layer, battle->size, (sfVector2i){0, 0});
    for (int x = 0; x < battle->size.x; x++) {
        for (int y = 0; y < battle->size.y; y++)
            battle->layer->tiles[x + y * battle->size.x] =
                init_rect(battle->tiles[x + y * battle->size.x] & 3, x, y);
    }
}

/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Draws the tooltip of an item
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rpg/rpg.h"

static char *int_to_str(int i)
{
    char *str = malloc(sizeof(char) * 3);

    str[0] = i / 10 + '0';
    str[1] = i % 10 + '0';
    str[2] = 0;
    return (str);
}

static unsigned int draw_one_line(
    rpg_t *game, char *name, unsigned char stat, unsigned char drawed_line)
{
    char *numeric_stat = int_to_str((int)stat);

    if (stat == 0) {
        free(numeric_stat);
        return 0;
    }
    sfText_setString(game->inventory.stat_text, name);
    sfText_setPosition(
        game->inventory.stat_text, get_mouse_pos_vec2f(game->wind));
    sfText_move(game->inventory.stat_text,
        (sfVector2f){
            (int)(70 * SL(game)), (int)((140 + drawed_line * 50) * SL(game))});
    sfRenderWindow_drawText(game->wind, game->inventory.stat_text, NULL);
    sfText_move(
        game->inventory.stat_text, (sfVector2f){(int)(200 * SL(game)), 0});
    sfText_setString(game->inventory.stat_text, numeric_stat);
    sfRenderWindow_drawText(game->wind, game->inventory.stat_text, NULL);
    free(numeric_stat);
    return (1);
}

static void tooltip_draw_stats(
    rpg_t *game, item_t *items)
{
    int drawed_line = 0;

    drawed_line += draw_one_line(game, "Level :", items->level, drawed_line);
    drawed_line += draw_one_line(game, "Earth : ", items->earth, drawed_line);
    drawed_line += draw_one_line(game, "Fire : ", items->fire, drawed_line);
    drawed_line += draw_one_line(game, "Water : ", items->water, drawed_line);
    drawed_line += draw_one_line(game, "Wind : ", items->wind, drawed_line);
    drawed_line += draw_one_line(game, "Life : ", items->life, drawed_line);
    drawed_line += draw_one_line(
        game, "Res Earth : ", items->res_earth, drawed_line);
    drawed_line += draw_one_line(
        game, "Res Fire: ", items->res_fire, drawed_line);
    drawed_line += draw_one_line(
        game, "Res Water : ", items->res_water, drawed_line);
    drawed_line += draw_one_line(
        game, "Res Wind : ", items->res_wind, drawed_line);
}

extern void rpg_inventory_draw_items_tooltip(rpg_t *game, item_t *item)
{
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->wind);
    sfVector2f new_vec = {vec.x, vec.y};

    if (!item->name)
        return;
    sfText_setPosition(game->inventory.text, new_vec);
    sfText_setString(game->inventory.text, item->name);
    sfSprite_setTextureRect(
        game->inventory.tooltip, (sfIntRect){64 * item->rarity, 0, 64, 64});
    sfSprite_setPosition(
        game->inventory.tooltip, get_mouse_pos_vec2f(game->wind));
    sfText_move(game->inventory.text,
        (sfVector2f){(int)((576 * SL(game))
                         - sfText_getLocalBounds(game->inventory.text).width)
                / 2,
            (int)(70 * SL(game))});
    sfRenderWindow_drawSprite(game->wind, game->inventory.tooltip, NULL);
    tooltip_draw_stats(game, item);
    sfRenderWindow_drawText(game->wind, game->inventory.text, NULL);
}

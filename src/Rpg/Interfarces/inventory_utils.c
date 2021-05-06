/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** main loop of my hunter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rpg/rpg.h"

extern sfVector2f get_mouse_pos_vec2f(sfRenderWindow *w)
{
    sfVector2i vec = sfMouse_getPositionRenderWindow(w);

    return (sfVector2f){vec.x, vec.y};
}

extern void rpg_destroy_item(item_t *i)
{
    i->earth = 0;
    i->elem = 0;
    i->fire = 0;
    i->life = 0;
    i->level = 0;
    i->name = NULL;
    free(i->name);
    i->rarity = 0;
    i->res_earth = 0;
    i->res_fire = 0;
    i->res_water = 0;
    i->res_wind = 0;
    i->water = 0;
    i->wind = 0;
    i = NULL;
}

extern void rpg_copy_item(item_t *d, item_t s)
{
    d->earth = s.earth;
    d->elem = s.elem;
    d->fire = s.fire;
    d->level = s.level;
    d->life = s.life;
    d->name = strdup(s.name);
    d->rarity = s.rarity;
    d->res_earth = s.res_earth;
    d->res_fire = s.res_fire;
    d->res_water = s.res_water;
    d->res_wind = s.res_wind;
    d->water = s.water;
    d->wind = s.wind;
}

extern bool sprite_is_hover(sfSprite *s, sfVector2f m_pos)
{
    sfVector2f pos = sfSprite_getPosition(s);
    sfIntRect rect = sfSprite_getTextureRect(s);
    sfVector2f scale = sfSprite_getScale(s);

    if (m_pos.x > pos.x && m_pos.x < pos.x + rect.width * scale.x) {
        if (m_pos.y > pos.y && m_pos.y < pos.y + rect.height * scale.y) {
            return (true);
        }
    }
    return (false);
}

extern void set_item_texture_rect(sfSprite *sprite, item_t *i)
{
    if (i->name != NULL)
        sfSprite_setTextureRect(
            sprite, (sfIntRect){i->rarity * 16, i->elem * 16, 16, 16});
}

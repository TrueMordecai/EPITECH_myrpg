/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Initializes a generic infobox
*/

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

static void init_view(infobox_base_t *base)
{
    base->view = sfView_create();
    base->window_size =
        sfRenderWindow_getSize(base->rpg->state->game_data->window);
    sfView_setSize(
        base->view, (sfVector2f){base->window_size.x, base->window_size.y});
    sfView_setCenter(base->view,
        (sfVector2f){base->window_size.x / 2.0, base->window_size.y / 2.0});
    sfView_move(base->view,
        (sfVector2f){
            -(base->window_size.x * 0.375), -(base->window_size.y * 0.15)});
}

static void init_rects(infobox_base_t *base)
{
    base->icon = sfRectangleShape_create();
    base->box = sfRectangleShape_create();
    sfRectangleShape_setSize(
        base->icon, (sfVector2f){115 * SL(base->rpg), 115 * SL(base->rpg)});
    sfRectangleShape_setPosition(
        base->icon, (sfVector2f){30 * SL(base->rpg), 30 * SL(base->rpg)});
    sfRectangleShape_setOutlineColor(base->icon, sfColor_fromRGB(72, 104, 89));
    sfRectangleShape_setOutlineThickness(base->icon, 3);
    sfRectangleShape_setSize(base->box,
        (sfVector2f){base->window_size.x * 0.25, base->window_size.y * 0.7});
    sfRectangleShape_setOutlineColor(base->box, sfColor_fromRGB(44, 59, 57));
    sfRectangleShape_setOutlineThickness(base->box, -3);
    sfRectangleShape_setFillColor(
        base->box, sfColor_fromRGBA(141, 166, 152, 130));
}

void infobox_init(infobox_base_t *base, void *data)
{
    init_view(base);
    init_rects(base);
    base->box_size = sfRectangleShape_getSize(base->box);
    switch (base->type) {
        case INFOBOX_ENTITY:
            infobox_entity_init((infobox_entity_t *)base, data);
            break;
        case INFOBOX_SPELL:
            infobox_spell_init((infobox_spell_base_t *)base, data);
            break;
        default: break;
    }
}

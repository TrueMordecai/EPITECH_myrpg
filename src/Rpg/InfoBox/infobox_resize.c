/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_shrink
*/

#include "Rpg/InfoBox/infobox.h"

void infobox_reset_box_size(infobox_base_t *base)
{
    sfView_setSize(
        base->view, (sfVector2f){base->window_size.x, base->window_size.y});
    sfView_setCenter(base->view,
        (sfVector2f){base->window_size.x / 2.0, base->window_size.y / 2.0});
    sfView_move(base->view,
        (sfVector2f){
            -(base->window_size.x * 0.375), -(base->window_size.y * 0.15)});
    sfRectangleShape_setSize(base->box,
        (sfVector2f){base->window_size.x * 0.25, base->window_size.y * 0.7});
    base->box_size = sfRectangleShape_getSize(base->box);
}

void infobox_set_box_size(
    infobox_base_t *base, sfVector2f new_size, int unmove_view)
{
    if (unmove_view)
        sfView_move(base->view,
            (sfVector2f){(base->window_size.x - base->box_size.x) / 2.0,
                (base->window_size.y - base->box_size.y) / 2.0});
    sfRectangleShape_setSize(base->box, new_size);
    base->box_size = new_size;
    sfView_move(base->view,
        (sfVector2f){-(base->window_size.x - base->box_size.x) / 2.0,
            -(base->window_size.y - base->box_size.y) / 2.0});
}

/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_base_draw
*/

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/InfoBox/infobox_entity.h"

void infobox_draw(infobox_base_t *base, sfRenderWindow *window)
{
    sfRenderWindow_setView(window, base->view);
    sfRenderWindow_drawRectangleShape(window, base->box, NULL);
    sfRenderWindow_drawRectangleShape(window, base->icon, NULL);
    switch (base->type) {
        case INFOBOX_ENTITY:
            infobox_entity_draw((infobox_entity_t *)base, window);
            break;
        default: break;
    }
    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
}
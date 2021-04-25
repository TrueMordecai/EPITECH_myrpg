/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_destroy
*/

#include <stdlib.h>
#include "Rpg/InfoBox/infobox.h"
#include "Rpg/InfoBox/infobox_entity.h"

void infobox_destroy(infobox_base_t *base)
{
    switch (base->type) {
        case INFOBOX_ENTITY:
            infobox_entity_destroy((infobox_entity_t *)base);
            break;
        default: break;
    }
    sfView_destroy(base->view);
    sfRectangleShape_destroy(base->icon);
    sfRectangleShape_destroy(base->box);
    free(base);
}
/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Destroys a generic infobox
*/

#include <stdlib.h>
#include "Rpg/InfoBox/infobox.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

void infobox_destroy(infobox_base_t *base)
{
    switch (base->type) {
        case INFOBOX_ENTITY:
            infobox_entity_destroy((infobox_entity_t *)base);
            break;
        case INFOBOX_SPELL:
            infobox_spell_destroy((infobox_spell_base_t *)base);
            break;
        default: break;
    }
    sfView_destroy(base->view);
    sfRectangleShape_destroy(base->icon);
    sfRectangleShape_destroy(base->box);
    free(base);
}

/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Updates a generic infobox
*/

#include <libmy/printf.h>

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/InfoBox/infobox_entity.h"
#include "Rpg/InfoBox/infobox_spell.h"

void infobox_change_type(
    infobox_base_t **base_ptr, enum infobox_type new_type, void *new_data)
{
    infobox_base_t *new_base = infobox_recreate(new_type, new_data, *base_ptr);

    infobox_destroy(*base_ptr);
    *base_ptr = new_base;
}

void infobox_update(
    infobox_base_t **base_ptr, enum infobox_type type, void *data)
{
    if (type != (*base_ptr)->type) {
        infobox_change_type(base_ptr, type, data);
        return;
    }
    switch (type) {
        case INFOBOX_ENTITY:
            infobox_entity_set_entity((infobox_entity_t **)base_ptr, data);
            break;
        case INFOBOX_SPELL:
            infobox_spell_set_spell((infobox_spell_base_t **)base_ptr, data);
            break;
        default: break;
    }
}

/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_update
*/

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/InfoBox/infobox_entity.h"

void infobox_update(
    infobox_base_t **base_ptr, enum infobox_type type, void *data)
{
    switch (type) {
        case INFOBOX_ENTITY:
            infobox_entity_set_entity(*((infobox_entity_t **)base_ptr), data);
            break;
        default: break;
    }
}
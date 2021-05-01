/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** allies_destroy
*/

#include "Rpg/Entities/allies.h"

static void destroy_entity(void *entity_ptr)
{
    entity_t *entity = *(entity_t **)entity_ptr;

    entity_destroy(entity);
}

void allies_destroy(allies_t *allies)
{
    my_vec_free(&allies->allies, &destroy_entity);
}
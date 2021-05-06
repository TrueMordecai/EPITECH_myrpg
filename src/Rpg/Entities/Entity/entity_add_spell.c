/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** entity_add_spell
*/

#include <libmy/printf.h>

#include "Rpg/rpg.h"
#include "Rpg/Entities/entity.h"

spell_base_t *get_null_spell(void);

void entity_add_spell(entity_t *entity, spell_base_t *spell)
{
    if (!spell)
        return;
    my_vec_push(&entity->spells, &spell);
}

void entity_init_spells(entity_t *entity, rpg_t *rpg)
{
    my_hash_map_iter_t iter;

    my_hash_map_iter_init(&iter, &rpg->spells);
    while (my_hash_map_iter_next(&iter))
        entity_add_spell(entity, *((spell_base_t **)iter.value));
    if (entity->spells.length == 0)
        entity_add_spell(entity, get_null_spell());
}
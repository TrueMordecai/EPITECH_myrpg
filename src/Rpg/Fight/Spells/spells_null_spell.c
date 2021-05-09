/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spells_init
*/

#include <libmy/printf.h>
#include <stdalign.h>
#include <libmy/collections/hash_map.h>

#include "Rpg/Fight/spell.h"
#include "Rpg/rpg.h"

spell_base_t *get_null_spell(void)
{
    static spell_attack_t punch;

    return (spell_base_t *)&punch;
}

void set_null_spell(void)
{
    spell_attack_t *punch = (spell_attack_t *)get_null_spell();

    punch->base.area = 1;
    punch->base.name = "ERROR SPELL";
    punch->base.ap = 3;
    punch->base.po = 1;
    punch->base.texture_id = -1;
    punch->base.turn_limit = 3;
    punch->base.type = SPELL_ATTACK;
    punch->damages[EARTH] = 5;
}

/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** spell_destroy
*/

#include <stdlib.h>
#include "Rpg/Fight/spell.h"

void spell_destroy(spell_base_t *spell)
{
    if (!spell)
        return;
    free(spell->name);
    free(spell);
}
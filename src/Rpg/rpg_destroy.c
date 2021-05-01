/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** rpg_destroy
*/

#include <stdlib.h>
#include "Rpg/rpg.h"

void rpg_destroy(rpg_t *rpg)
{
    map_destroy(rpg->map);
    player_destroy(rpg->player);
    my_hash_map_drop(&rpg->spells);
    allies_destroy(&rpg->allies);
    free(rpg);
}
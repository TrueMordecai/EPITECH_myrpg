/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** MyRPG create
*/

#include <libmy/memory/alloc.h>

#include "Rpg/Fight/spell.h"
#include "Rpg/rpg.h"

rpg_t *rpg_create(state_t *state)
{
    rpg_t *rpg = my_calloc(1, sizeof(rpg_t));

    spells_init(rpg);
    rpg->state = state;
    rpg->quests.nb_quests = 0;
    rpg->quests.rpg = rpg;
    rpg->quests.quests = NULL;
    rpg->wind = state->game_data->window;
    rpg->player = player_create(rpg);
    rpg->inventory = inventory_init(rpg);
    allies_init(&rpg->allies, rpg);
    rpg->map = map_create(rpg);
    if (!rpg->map) {
        rpg_destroy(rpg);
        return NULL;
    }
    quests_init(&rpg->quests, "assets/Quests/list_quests");
    return rpg;
}

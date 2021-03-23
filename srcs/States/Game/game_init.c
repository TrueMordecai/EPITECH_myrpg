/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game init
*/

#include "States/Game/game_state.h"
#include "My/my_display.h"

int game_init(state_t *state)
{
    state->state_datas = (size_t *)rpg_create(state);
    return 0;
}

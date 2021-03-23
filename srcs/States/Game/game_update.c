/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Menu
*/

#include "States/Game/game_state.h"
#include "My/my_display.h"
#include "My/my_convert.h"


int game_update(state_t *state, float dt)
{
    rpg_update((rpg_t *)state->state_datas, dt);
    return 0;
}

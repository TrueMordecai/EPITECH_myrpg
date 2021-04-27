/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Suspends a state
*/

#include <assert.h>

#include "GameEngine/state.h"

int state_pause(state_t *state, state_id_t from)
{
    assert(state != NULL);
    assert(state->vtable.pause != NULL);
    return (*state->vtable.pause)(state, from);
}

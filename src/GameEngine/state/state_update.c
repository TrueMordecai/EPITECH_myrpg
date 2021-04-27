/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Updates the passed state
*/

#include <assert.h>

#include "GameEngine/state.h"

int state_update(state_t *state, float delta)
{
    assert(state != NULL);
    assert(state->vtable.update != NULL);
    return (*state->vtable.update)(state, delta);
}

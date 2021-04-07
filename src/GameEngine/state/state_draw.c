/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Draws the game state
*/

#include <assert.h>

#include "GameEngine/state.h"

int state_draw(state_t *state, float delta)
{
    assert(state != NULL);
    assert(state->vtable.draw != NULL);
    return (*state->vtable.draw)(state, delta);
}

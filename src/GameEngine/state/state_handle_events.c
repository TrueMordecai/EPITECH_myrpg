/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Handles the event loop of a state
*/

#include <assert.h>

#include "GameEngine/state.h"

int state_handle_events(state_t *state)
{
    assert(state != NULL);
    assert(state->vtable.handle_events != NULL);
    return (*state->vtable.handle_events)(state);
}

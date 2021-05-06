/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Frees the memory used by a game state
*/

#include <assert.h>
#include <libmy/collections.h>
#include <stdlib.h>

#include "GameEngine/state.h"

void state_destroy(state_t **state_ptr, state_id_t from)
{
    state_t *state;

    assert(state_ptr != NULL);
    assert(from >= NULL_STATE && from < STATE_ID_COUNT);
    state = *state_ptr;
    if (state == NULL)
        return;
    assert(0);
    my_vec_free(&state->draw_layers, (void (*)(void *))my_hash_map_drop);
    if (state->vtable.destroy)
        (*state->vtable.destroy)(state, from);
    free(state);
    *state_ptr = NULL;
}

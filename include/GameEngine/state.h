/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Game State
*/

#ifndef GE_STATE_H
#define GE_STATE_H

#include <libmy/collections/vec.h>

#include "types.h"

enum state_id {
    NULL_STATE,
    MENU_STATE,
    SETTINGS_STATE,
    GAME_STATE,
    STATE_ID_COUNT,
};

struct state;

typedef int (*state_pause_t)(struct state *, state_id_t);
typedef int (*state_resume_t)(struct state *, state_id_t);
typedef int (*state_handle_events_t)(struct state *);
typedef int (*state_update_t)(struct state *, float);
typedef int (*state_draw_t)(struct state *, float);
typedef void (*state_destroy_t)(struct state *, state_id_t);

struct state_vtable {
    state_pause_t pause;
    state_resume_t resume;
    state_handle_events_t handle_events;
    state_update_t update;
    state_draw_t draw;
    state_destroy_t destroy;
};

struct state {
    state_vtable_t vtable;
    game_data_t *game_data;
    /// A vector of @ref drawable element maps.
    /// Each map has the following types:
    /// - Key  : unsigned char
    /// - Value: drawable_t
    my_vec_t draw_layers;
    state_id_t state_id;
};

int state_pause(state_t *state, state_id_t from);
int state_resume(state_t *state, state_id_t from);
int state_handle_events(state_t *state);
int state_update(state_t *state, float delta);
int state_draw(state_t *state, float delta);

/// Frees the common state data (like draw layers) before
/// calling @ref state::drop, then frees the value of @c state.
///
/// @param state A pointer to the state, cannot be @c NULL, its value is set
/// to @c NULL by this call.
/// @param from The previous state.
void state_destroy(state_t **state, state_id_t from);

/// Intializes the common state data (like draw layers).
/// This must be the first function to be called after allocating the state
/// memory.
///
/// NOTE: Do not call outside [state_name]_create functions.
///
/// @param state The (fully uninitialized) state, may be @c NULL.
/// @param data A pointer to the game's data.
/// @param state_id The id of the state.
/// @param layer_count The number of draw layer this state should have.
///
/// @returns 0 on success, 1 if @c state is @c NULL or an allocation error
/// occured.
/// @protected
int state_init(state_t *state, game_data_t *data, state_id_t state_id,
    size_t layer_count);

#endif

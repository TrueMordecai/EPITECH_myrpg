/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The draw state
*/

#ifndef __SW_STATE_H__
#define __SW_STATE_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// The draw state.
/// @since 0.1.0

#include <SFML/Graphics/RenderStates.h>

#include "sw/types.h"

/// The draw state, used as context for the widget draw methods.
///
/// @since 0.1.0
struct sw_state_s {
    /// The CSFML render states.
    /// @since 0.1.0
    sfRenderStates render_states;
    /// The number of microseconds since the last update.
    /// @since 0.1.0
    sw_u64_t elapsed_ms;
};

/// Initializes a Simple Widgets state.
///
/// @param state The SW draw state.
/// @param render_states SFML render states, may be @c NULL.
///
/// @memberof sw_state_s
/// @public
/// @since 0.1.0
SW_API sw_state_t *sw_state_init(
    sw_state_t *state, sfRenderStates const *render_states);

/// Returns the passed state, or a default one if missing.
///
/// @param state A SW draw state, can be @c NULL.
///
/// @returns The given state pointer or a default state if @c state is @c NULL.
///
/// @memberof sw_state_s
/// @public
/// @since 0.1.0
SW_API sw_state_t const *sw_state_get(sw_state_t const *state);

SW_API_END

#endif // !defined(__SW_STATE_H__)

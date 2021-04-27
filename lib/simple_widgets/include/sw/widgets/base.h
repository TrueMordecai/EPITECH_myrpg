/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Defines the base widget
*/

#ifndef __SW_WIDGETS_BASE_H__
#define __SW_WIDGETS_BASE_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// Defines the base widget.
/// @since 0.1.0

#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include "sw/state.h"
#include "sw/types.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

/// Initializes an empty base widget.
///
/// @param widget The widget to initialize.
/// @param parent The parent, can be @c NULL.
///
/// @returns @c SW_OK on success.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_base_init(sw_base_t *widget, sw_base_t *parent);

/// Creates an empty base widget.
///
/// @param parent The parent, can be @c NULL.
///
/// @returns @c SW_ERR_ALLOCATION if the widget couldn't be allocated.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_base_t *sw_base_create(sw_base_t *parent);

////////////////////////////////////////////////////////////////////////////////
// PROTECTED API - do not use outside derived widgets!
////////////////////////////////////////////////////////////////////////////////

/// The internal state flags of a base widget.
/// @internal
typedef enum sw_base_flags_e {
    /// @privatesection
    /// Whether the update method must be called.
    SW_BASE_FLAG_NEEDS_UPDATE = 1 << 0,
    /// Whether this widget's base is fully initialized.
    SW_BASE_FLAG_INITIALIZED = 1 << 1,
} sw_base_flags_t;

/// Base widget internal data.
///
/// @internal
struct sw_base_data_s {
    /// @privatesection
    /// The parent of this widget, or @c NULL if this is the root.
    sw_base_t *parent;
    sw_list_t children;
    /// The absolute coordinates of this widget, points to the top-left
    /// corner of the widget's content.
    sw_vec2f_t pos;
    /// The outer rectangle outside the border.
    sw_spacing_t margin;
    /// The border rectangle between the margin and padding.
    sw_spacing_t border;
    /// The spacing between the border and the content.
    sw_spacing_t padding;
    sw_vec2f_t size;
    /// The position of this widget in the parent's child array, if present.
    size_t child_index;
    sw_base_flags_t flags;
    sw_color_t border_color;
    /// The current main layout for children.
    sw_layout_t *layout;
    /// Data used by the parent's layout to manage this widget.
    void *layout_data;
    /// The background image, may be @c NULL.
    sfSprite *background;
    sw_vec2i_t background_size;
};

/// The set_size method, used by @ref sw_base_s::sw_set_size.
typedef void (*sw_set_size_t)(sw_base_t *, sw_vec2f_t);
/// The set_position method, used by @ref sw_base_s::sw_set_position.
typedef void (*sw_set_position_t)(sw_base_t *, sw_vec2f_t);
/// The draw method, used by @ref sw_base_s::sw_draw.
typedef void (*sw_draw_t)(sw_base_t *, sfRenderWindow *, sw_state_t const *);
/// The drop method, used by @ref sw_base_s::sw_drop.
typedef void (*sw_drop_t)(sw_base_t *);
/// The on_event method, used by @ref sw_base_s::sw_send_event.
typedef sw_result_t (*sw_on_event_t)(sw_base_t *, sfEvent const *);
/// The update method, used by @ref sw_base_s::sw_update.
typedef void (*sw_update_t)(sw_base_t *);

/// The widget vtable, do not access outside widget implementations.
struct sw_base_vtable_s {
    /// @protectedsection
    /// The set_size method, used by @ref sw_base_s::sw_set_size.
    sw_set_size_t set_size;
    /// The set_position method, used by @ref sw_base_s::sw_set_position.
    sw_set_position_t set_position;
    /// The draw method, used by @ref sw_base_s::sw_draw.
    sw_draw_t draw;
    /// The drop method, used by @ref sw_base_s::sw_drop.
    sw_drop_t drop;
    /// The on_event method, used by @ref sw_base_s::sw_send_event.
    sw_on_event_t on_event;
    /// The update method, used by @ref sw_base_s::sw_update.
    sw_update_t update;
};

/// The base widget type, can be used on its own to contain other widgets.
/// @implements sw_widget_t
struct sw_base_s {
    /// @private
    sw_base_data_t data;
    /// Widget base virtual function table.
    /// @protected
    sw_base_vtable_t vtable;
};

/// Uninitializes the given base widget component.
/// DO NOT CALL outside derived widget implementations, use @ref sw_drop
/// instead.
///
/// @param widget The widget base.
///
/// @since 0.1.0
/// @memberof sw_base_s
/// @protected
SW_PROTECTED_API void sw_base_drop(sw_base_t *widget);

/// Draws the base component of a widget.
/// DO NOT CALL outside derived widget implementations, use @ref sw_draw
/// instead.
///
/// @param widget The widget base.
/// @param window Where the widget will be drawn.
/// @param state Draw parameters.
///
/// @memberof sw_base_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_base_draw(
    sw_base_t *widget, sfRenderWindow *window, sw_state_t const *state);

/// Sets the size of the given widget base.
/// DO NOT CALL outside derived widget implementations, use @ref sw_set_size
/// instead.
///
/// @param widget The widget base.
/// @param new_size The new size of the widget.
///
/// @returns The previous size of this widget, excluding spacing.
///
/// @memberof sw_base_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_base_set_size(sw_base_t *widget, sw_vec2f_t new_size);

/// Sets the position of a base widget component.
/// DO NOT CALL outside derived widget implementations, use @ref
/// sw_set_position instead.
///
/// @param widget The widget base.
/// @param new_pos The new position of the widget.
///
/// @returns The position of this widget, excluding spacing.
///
/// @memberof sw_base_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_base_set_position(
    sw_base_t *widget, sw_vec2f_t new_pos);

/// Draws the border of a base widget component.
/// DO NOT CALL outside derived widget implementations!
///
/// @param widget The widget base.
/// @param window Where the border will be drawn.
/// @param state Draw parameters.
///
/// @memberof sw_base_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_base_draw_border(
    sw_base_t *widget, sfRenderWindow *window, sw_state_t const *state);

/// Marks a widget base component for an update.
/// DO NOT CALL outside derived widget implementations!
///
/// @param widget The widget base.
///
/// @memberof sw_base_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_base_update(sw_base_t *widget);

SW_API_END

#endif // !defined(__SW_WIDGETS_BASE_H__)

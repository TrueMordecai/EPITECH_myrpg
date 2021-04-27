/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Universal widget functions
*/

#ifndef __SW_WIDGET_H__
#define __SW_WIDGET_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// Universal widget functions.
///
/// @since 0.1.0

#include "sw/widgets/base.h"

/// @param widget The widget.
///
/// @returns The size of this widget, excluding spacing.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_get_size(sw_widget_t *widget);

/// @param widget The widget.
///
/// @returns The size of this widget, with spacing.
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_get_size_spacing(sw_widget_t *widget);

/// Sets the size of the given widget.
///
/// @param widget The widget.
/// @param new_size The new size of the widget.
///
/// @returns The previous size of this widget, excluding spacing.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_set_size(sw_widget_t *widget, sw_vec2f_t new_size);

/// @param widget The widget.
///
/// @returns The position of this widget, excluding spacing.
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_get_position(sw_widget_t *widget);

/// Sets the position of this widget.
///
/// @param widget The widget.
/// @param new_pos The new position of the widget.
///
/// @returns The position of this widget, excluding spacing.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_set_position(sw_widget_t *widget, sw_vec2f_t new_pos);

/// Draws the widget to the given window.
///
/// @param widget The widget to draw.
/// @param window Where the widget will be drawn.
/// @param state Draw parameters.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void sw_draw(
    sw_widget_t *widget, sfRenderWindow *window, sw_state_t const *state);

/// Sends a SFML event to the widget.
/// Children widgets are typically notified by events too, unless the event was
/// captured by the parent such as a click on a button widget.
///
/// @param widget The widget.
/// @param event The event.
///
/// @return @c SW_OK if the event was captured, @c SW_PASS otherwise.
/// May also return an error.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_send_event(sw_widget_t *widget, sfEvent const *event);

/// Unitializes the widget without freeing the given pointer.
/// Prefer using @ref sw_destroy if the widget was creating using a
/// @c [name]_create function.
///
/// @param widget The widget to uninitialize, may be @c NULL.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void sw_drop(sw_widget_t *widget);

/// Unitializes and frees the given pointer.
///
/// @c sw_destroy must only be used on a widget that has been created using a
/// sw_<widget name>_create function.
///
/// @param widget The widget to uninitialize, may be @c NULL.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void sw_destroy(sw_widget_t *widget);

/// Returns the children of this widget.
///
/// @param widget The parent widget.
/// @param[out] children_count Where the number of children is stored,
/// or @c NULL.
///
/// @returns An array of widget pointers, or @c NULL
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_widget_t **sw_get_children(
    sw_widget_t *widget, size_t *children_count);

/// Returns the number of children contained by this widget.
///
/// @param widget The parent widget.
///
/// @returns The number of children.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API size_t sw_get_children_count(sw_widget_t *widget);

/// Checks whether @c pos is inside the widget's bounds (excluding spacing).
///
/// @param widget The widget.
/// @param pos The position to check.
///
/// @returns Is @c pos inside @c widget?
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API bool sw_is_inside(sw_widget_t *widget, sw_vec2f_t pos);

/// Checks whether the passed event happened in the widget.
///
/// @param widget The widget.
/// @param event The event to check.
///
/// @returns Has @c event happened inside @c widget?
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API bool sw_is_event_inside(sw_widget_t *widget, sfEvent const *event);

/// Marks a widget for an update.
///
/// @param widget The widget.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void sw_mark_dirty(sw_widget_t *widget);

/// Forces a widget update.
/// This function is automatically called by @c sw_draw and @c sw_send_event
/// when the widget is marked for update.
/// This resets the update marker.
///
/// @param widget The widget to update.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void sw_update(sw_widget_t *widget);

/// Returns the current layout.
///
/// @param widget The widget.
///
/// @returns The current layout, or @c NULL if none.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_layout_t *sw_get_layout(sw_widget_t *widget);

/// @param widget The widget to update.
///
/// @returns The widget's parent, or @c NULL if none.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_widget_t *sw_get_parent(sw_widget_t *widget);

/// Changes the parent of an existing widget.
///
/// This function is automatically called by the widget creation functions, use
/// this only if you want to update or remove the widget's parent.
///
/// @param widget The widget.
/// @param new_parent The new parent, or @c NULL to detach this widget.
/// @param[out] old_parent Set to the previous parent of @c widget, or @c NULL
/// if none, can be @c NULL.
///
/// @returns @c SW_ERR_ALLOCATION if widget attachment has failed.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_set_parent(
    sw_widget_t *widget, sw_widget_t *new_parent, sw_widget_t **old_parent);

/// Removes the widget from its parent.
///
/// @param widget The child widget to remove.
///
/// @returns The old parent.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_widget_t *sw_remove_child(sw_widget_t *widget);

/// @param widget The widget.
///
/// @returns the layout data of a widget.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void *sw_get_layout_data(sw_widget_t const *widget);

/// Sets the layout data of a widget, DO NOT USE outside layout
/// implementations.
///
/// @param widget The widget.
/// @param data The layout data.
///
/// @returns the layout data of a widget.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API void *sw_set_layout_data(sw_widget_t *widget, void *data);

/// @param widget the widget.
///
/// @returns Whether this widget is fully initialized.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API bool sw_is_initialized(sw_widget_t *widget);

/// @param widget the widget.
///
/// @returns Whether this widget needs a call to @ref sw_update.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API bool sw_needs_update(sw_widget_t *widget);

/// Sets the background texture of this widget.
///
/// @param widget the widget.
/// @param texture The CSFML texture.
/// @param reset_rect Should the background texture area be reset to the size
/// of the new texture?
///
/// @returns @c SW_OK or @c SW_ERR_ALLOCATION if a sprite could not be
/// allocated.
///
/// @memberof sw_base_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_set_background_texture(
    sw_widget_t *widget, sfTexture const *texture, bool reset_rect);

/// Sets the background texture area of this widget.
///
/// @param widget The widget.
/// @param rect The texture area.
///
/// @returns @c SW_OK or @c SW_ERR_ALLOCATION if a sprite could not be
/// allocated.
/// @memberof sw_base_s
///
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_set_background_texture_rect(
    sw_widget_t *widget, sw_irect_t rect);

/// Same as @ref sw_get_position.
/// @since 0.1.0
#define SW_POS(w) (((sw_base_t *)w)->data.pos)

/// Returns the widget's margin.
/// @since 0.1.0
#define SW_MARGIN(w) (((sw_base_t *)w)->data.margin)

/// Returns the widget's border.
/// @since 0.1.0
#define SW_BORDER(w) (((sw_base_t *)w)->data.border)

/// Returns the widget's padding.
/// @since 0.1.0
#define SW_PADDING(w) (((sw_base_t *)w)->data.padding)

/// Same as @ref sw_get_size.
/// @since 0.1.0
#define SW_SIZE(w) (((sw_base_t *)w)->data.size)

/// Same as @ref sw_get_parent.
/// @since 0.1.0
#define SW_PARENT(w) (((sw_base_t *)w)->data.parent)

/// Same as @ref sw_is_inside
/// Automatically converts the passed vector to a @ref sw_vec2f_t.
/// @since 0.1.0
#define SW_INSIDE(w, p) (sw_is_inside(w, (sw_vec2f_t){(float)p.x, (float)p.y}))

/// Same as @ref sw_is_inside, but takes an x and y coordinate pair instead.
/// Automatically converts the coordinates to floats.
/// @since 0.1.0
#define SW_INSIDE2(w, x, y) (sw_is_inside(w, (sw_vec2f_t){(float)x, (float)y}))

/// Same as @ref sw_get_layout.
/// @since 0.1.0
#define SW_LAYOUT(w) (((sw_base_t *)w)->data.layout)

/// Same as @ref sw_get_layout_data.
/// @since 0.1.0
#define SW_LAYOUT_DATA(w) (((sw_base_t *)w)->data.layout_data)

SW_API_END

#endif // !defined(__SW_WIDGET_H__)

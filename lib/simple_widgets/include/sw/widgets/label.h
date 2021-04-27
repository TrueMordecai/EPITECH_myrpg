/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** label widget definitions.
*/

#ifndef __SW_WIDGETS_LABEL_H__
#define __SW_WIDGETS_LABEL_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// Label widget definitions.
/// @since 0.1.0

#include <SFML/Graphics/Types.h>
#include "sw/widgets/base.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

/// Initializes a label widget.
///
/// @param widget The label widget to initialize.
/// @param parent The parent widget, or @c NULL.
/// @param text The string to display, can be @c NULL or empty
/// @param font The font to use, this font WILL NOT be freed upon calling
/// @ref sw_destroy.
///
/// @returns @c SW_ERR_ALLOCATION on error.
///
/// @memberof sw_label_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_label_init(
    sw_label_t *widget, sw_widget_t *parent, char const *text, sfFont *font);

/// Creates a label widget.
///
/// @param parent The parent widget, or @c NULL.
/// @param text The string to display, can be @c NULL or empty
/// @param font The font to use, this font WILL NOT be freed upon calling
/// @ref sw_destroy.
///
/// @returns The allocated label widget.
///
/// @memberof sw_label_s
/// @public
/// @since 0.1.0
SW_API sw_label_t *sw_label_create(
    sw_widget_t *parent, char const *text, sfFont *font);

////////////////////////////////////////////////////////////////////////////////
// PROTECTED API - do not use outside derived widgets!
////////////////////////////////////////////////////////////////////////////////

/// The internal data of a label widget.
///
/// @internal
struct sw_label_data_s {
    /// @privatesection
    sfText *text;
};

/// The label widget type.
/// Pointers of this type can safely be casted to a @ref sw_base_t pointer.
///
/// @extends sw_base_s
/// @since 0.1.0
struct sw_label_s {
    /// @privatesection
    sw_base_t base;
    sw_label_data_t data;
};

/// Uninitializes a label widget component.
/// DO NOT CALL outside derived label implementations!
///
/// @param widget The label widget component to drop.
///
/// @memberof sw_label_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_label_drop(sw_label_t *widget);

/// Draws a label, without drawing children.
/// DO NOT CALL outside derived label implementations!
///
/// @param widget The label widget component.
/// @param window Where the border will be drawn.
/// @param state Draw parameters.
///
/// @memberof sw_label_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_label_draw(
    sw_label_t *widget, sfRenderWindow *window, sw_state_t const *state);

/// Sets the position of a label widget without updating positions of children.
/// DO NOT CALL outside derived label implementations!
///
/// @param widget The label widget component.
/// @param new_pos The new position of the widget.
///
/// @returns The position of this widget, excluding spacing.
///
/// @memberof sw_label_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_label_set_position(
    sw_label_t *widget, sw_vec2f_t new_pos);

SW_API_END

#endif // !defined(__SW_WIDGETS_LABEL_H__)

/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** button widget definitions.
*/

#ifndef __SW_WIDGETS_BUTTON_H__
#define __SW_WIDGETS_BUTTON_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// Button widget definitions.
/// @since 0.1.0

#include "sw/widgets/base.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

/// The state of a button widget.
///
/// @since 0.1.0
typedef enum sw_button_state_e {
    /// The default button state.
    /// @since 0.1.0
    SW_BUTTON_IDLE = 0,
    /// When the button is pressed.
    /// @since 0.1.0
    SW_BUTTON_PRESSED,
    /// When the button is hovered.
    /// @since 0.1.0
    SW_BUTTON_HOVERED,
    /// The button is disabled.
    /// @since 0.1.0
    SW_BUTTON_DISABLED,
    /// The number of button states available, not a state itself.
    /// @since 0.1.0
    SW_BUTTON_STATE_COUNT,
} sw_button_state_t;

/// Button click handler.
/// Takes the button widget and an user-supplied pointer as parameters.
///
/// @since 0.1.0
typedef void (*sw_button_on_click_t)(sw_button_t *, void *);

/// Initializes a button widget.
///
/// @param widget The button widget to initialize.
/// @param parent The parent widget, or @c NULL.
/// @param on_click The function to call on button click, or @c NULL.
///
/// @returns @c SW_ERR_ALLOCATION on error.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_button_init(
    sw_button_t *widget, sw_widget_t *parent, sw_button_on_click_t on_click);

/// Creates a button widget.
///
/// @param parent The parent widget, or @c NULL.
/// @param on_click The function to call on button click, or @c NULL.
///
/// @returns The allocated button widget.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_button_t *sw_button_create(
    sw_widget_t *parent, sw_button_on_click_t on_click);

/// Sets the text of a button widget.
///
/// @param widget The button widget.
/// @param text The string to display, can be @c NULL or empty
/// @param font The font to use, this font WILL NOT be freed upon calling
/// @ref sw_destroy.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API void sw_button_set_text(
    sw_button_t *widget, char const *text, sfFont *font);

/// Clicks the button, executing the callback if present and resetting the
/// button's state.
///
/// @param widget The button widget.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API void sw_button_click(sw_button_t *widget);

/// Fetches the current state of this button.
///
/// @param widget The button widget.
///
/// @return The button state.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_button_state_t sw_button_get_state(sw_button_t const *widget);

/// Forcibly sets the state of this button.
///
/// @param widget The button widget.
/// @param state The new state.
///
/// @returns The old state of the button.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_button_state_t sw_button_set_state(
    sw_button_t *widget, sw_button_state_t state);

/// Fetches the click handler's data.
///
/// @param widget The button widget.
///
/// @returns The user data.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API void *sw_button_get_user_data(sw_button_t *widget);

/// Sets the click handler's data.
/// The user data pointer is directly passed to the click callback.
///
/// @param widget The button widget.
/// @param user_data The new user data.
///
/// @returns The previous user data.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API void *sw_button_set_user_data(sw_button_t *widget, void *user_data);

/// Sets the texture of the button for the given state, or sets the same
/// texture for all states if @c state is @c SW_BUTTON_STATE_COUNT.
///
/// @param widget The button widget.
/// @param texture The SFML texture.
/// @param state The state to assign the texture to.
/// @param reset_rect Whether the texture area should be reset to the texture
/// size.
///
/// @returns @c SW_OK or @c SW_ERR_ALLOCATION if a sprite could not be
/// allocated.
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_button_set_texture(sw_button_t *widget,
    sfTexture const *texture, sw_button_state_t state, bool reset_rect);

/// Sets the texture area for the given button state, or assigns the same
/// texture area for all states if @c state is @c SW_BUTTON_STATE_COUNT.
///
/// @param widget The button widget.
/// @param rect The texure area.
/// @param state The state to assign the texture area to.
///
/// @returns @c SW_OK or @c SW_ERR_ALLOCATION if a sprite could not be
/// allocated
///
/// @memberof sw_button_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_button_set_texture_rect(
    sw_button_t *widget, sw_irect_t rect, sw_button_state_t state);

////////////////////////////////////////////////////////////////////////////////
// PROTECTED API - do not use outside derived widgets!
////////////////////////////////////////////////////////////////////////////////

/// The internal data of a button widget.
///
/// @internal
struct sw_button_data_s {
    /// @privatesection
    sw_button_state_t state;
    sw_button_on_click_t on_click;
    bool has_text;
    sfText *text;
    /// A custom user-supplied pointer.
    void *user_data;
    sfSprite *sprites[SW_BUTTON_STATE_COUNT];
    sw_vec2i_t sprites_size[SW_BUTTON_STATE_COUNT];
};

/// The button widget type.
/// Pointers of this type can safely be casted to a @ref sw_base_t pointer.
///
/// @extends sw_base_s
/// @since 0.1.0
struct sw_button_s {
    /// @privatesection
    sw_base_t base;
    sw_button_data_t data;
};

/// Uninitializes a button widget component.
/// DO NOT CALL outside derived button implementations!
///
/// @param widget The button widget component.
///
/// @memberof sw_button_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_button_drop(sw_button_t *widget);

/// Draws a button, without drawing children.
/// DO NOT CALL outside derived button implementations!
///
/// @param widget The button widget component.
/// @param window Where the border will be drawn.
/// @param state Draw parameters.
///
/// @memberof sw_button_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_button_draw(
    sw_button_t *widget, sfRenderWindow *window, sw_state_t const *state);

/// Sets the size of a button widget without updating positions of children.
/// DO NOT CALL outside derived button implementations!
///
/// @param widget The button widget component.
/// @param new_size The new size of the widget.
///
/// @returns The previous size of this widget, excluding spacing.
///
/// @memberof sw_button_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_button_set_size(
    sw_button_t *widget, sw_vec2f_t new_size);

/// Sets the position of a button widget without updating positions of
/// children.
/// DO NOT CALL outside derived button implementations!
///
/// @param widget The button widget component.
/// @param new_pos The new position of the widget.
///
/// @returns The position of this widget, excluding spacing.
///
/// @memberof sw_button_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API void sw_button_set_position(
    sw_button_t *widget, sw_vec2f_t new_pos);

/// DO NOT CALL outside derived button implementations!
///
/// @param widget The button widget component.
/// @param event The event.
///
/// @return @c SW_OK if the event was captured, @c SW_PASS otherwise.
/// May also return an error.
///
/// @memberof sw_button_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API sw_result_t sw_button_on_event(
    sw_button_t *widget, sfEvent const *event);

SW_API_END

#endif // !defined(__SW_WIDGETS_BUTTON_H__)

/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The vertical layout
*/

#ifndef __SW_LAYOUTS_VERTICAL_H__
#define __SW_LAYOUTS_VERTICAL_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// The vertical layout.
/// This layout arranges on top of each other.
/// @since 0.1.0

#include "sw/layout.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

//// Initializes a vertical layout.
///
/// @param layout The vertical layout to initialize.
/// @param owner The owner widget.
///
/// @returns @c SW_ERR_NO_OWNER if @c owner if @c NULL, or @c SW_ERR_ALLOCATION
/// if allocation failed.
///
/// @memberof sw_vlayout_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_vlayout_init(sw_vlayout_t *layout, sw_widget_t *owner);

/// Creates a vertical layout.
///
/// @param owner The owner widget.
///
/// @returns The allocated vertical layout pointer.
///
/// @memberof sw_vlayout_s
/// @public
/// @since 0.1.0
SW_API sw_vlayout_t *sw_vlayout_create(sw_widget_t *owner);

/// Adds a widget to the right of this vertical layout.
///
/// @param layout The vertical layout.
/// @param widget The widget to add.
///
/// @memberof sw_vlayout_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_vlayout_add(sw_vlayout_t *layout, sw_widget_t *widget);

/// Adds multiple widgets to the right of this vertical layout.
///
/// @param layout The vertical layout.
/// @param count The number of widgets to add.
/// @param widgets The widgets to add.
///
/// @memberof sw_vlayout_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_vlayout_add_multiple(
    sw_vlayout_t *layout, size_t count, sw_widget_t *widgets[count]);

////////////////////////////////////////////////////////////////////////////////
// PRIVATE API - do not call!
////////////////////////////////////////////////////////////////////////////////

/// Internal data for the vertical layout.
/// @internal
typedef struct sw_vlayout_data_s {
    /// @privatesection
    sw_base_t *widget;
    size_t pos;
} sw_vlayout_data_t;

/// The vertical layout type.
/// Pointers of this type can safely be casted to a @ref sw_layout_t pointer.
///
/// @extends sw_layout_t
/// @since 0.1.0
struct sw_vlayout_s {
    /// @privatesection
    sw_layout_t base;
    sw_list_t widgets;
};

/// Do not call!
///
/// @memberof sw_vlayout_s
/// @private
/// @since 0.1.0
SW_LOCAL void sw_vlayout_update(sw_vlayout_t *layout);

/// Do not call!
///
/// @memberof sw_vlayout_s
/// @private
/// @since 0.1.0
SW_LOCAL void sw_vlayout_drop(sw_vlayout_t *layout);

/// Do not call!
///
/// @memberof sw_vlayout_s
/// @private
/// @since 0.1.0
SW_LOCAL sw_vec2f_t sw_vlayout_get_size(sw_vlayout_t *layout);

/// Do not call!
///
/// @memberof sw_vlayout_s
/// @private
/// @since 0.1.0
SW_LOCAL bool sw_vlayout_remove(sw_vlayout_t *layout, sw_base_t *widget);

SW_API_END

#endif // !defined(__SW_LAYOUTS_VERTICAL_H__)

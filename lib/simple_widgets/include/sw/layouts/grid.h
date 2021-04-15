/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The grid layout
*/

#ifndef __SW_LAYOUTS_GRID_H__
#define __SW_LAYOUTS_GRID_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// The grid layout.
/// This layout arranges widgets in a fixed size grid.
/// @since 0.1.0

#include "sw/layout.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

/// Initializes a grid layout of the given size.
///
/// @param layout The grid layout to initialize.
/// @param owner The owner widget.
/// @param size The dimensions of the grid.
///
/// @returns @c SW_ERR_NO_OWNER if @c owner if @c NULL, or @c SW_ERR_ALLOCATION
/// if allocation failed.
///
/// @memberof sw_glayout_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_glayout_init(
    sw_glayout_t *layout, sw_widget_t *owner, sw_vec2u_t size);

/// Creates a grid layout of the given size.
///
/// @returns The allocated grid layout pointer.
///
/// @memberof sw_glayout_s
/// @public
/// @since 0.1.0
SW_API sw_glayout_t *sw_glayout_create(sw_widget_t *owner, sw_vec2u_t size);

/// Sets a widget a the given position.
///
/// If @c pos is already occupied, this will remove the exsiting widget.
///
/// @param layout The grid layout.
/// @param widget The widget to set, must be initialized.
/// @param pos The position.
///
/// @returns @c SW_ERR_OUT_OF_BOUNDS if @c pos is outside the grid, or
/// @c SW_ERR_ALLOCATION if allocation failed.
///
/// @memberof sw_glayout_s
/// @public
/// @since 0.1.0
SW_API sw_result_t sw_glayout_set(
    sw_glayout_t *layout, sw_widget_t *widget, sw_vec2u_t pos);

////////////////////////////////////////////////////////////////////////////////
// PRIVATE API - do not call!
////////////////////////////////////////////////////////////////////////////////

/// Private data used by @ref sw_glayout_t.
///
/// @internal
typedef struct sw_glayout_data_s {
    /// @privatesection
    sw_base_t *widget;
    sw_vec2u_t pos;
} sw_glayout_data_t;

/// The grid layout type.
/// Pointers of this type can safely be casted to a @ref sw_layout_t pointer.
///
/// @extends sw_layout_t
/// @since 0.1.0
struct sw_glayout_s {
    /// @privatesection
    sw_layout_t base;
    sw_glayout_data_t *grid;
    sw_vec2u_t size;
};

/// Do not call!
///
/// @memberof sw_glayout_s
/// @private
/// @since 0.1.0
SW_LOCAL bool sw_glayout_remove(sw_glayout_t *layout, sw_base_t *widget);

/// Do not call!
///
/// @memberof sw_glayout_s
/// @private
/// @since 0.1.0
SW_LOCAL sw_vec2f_t sw_glayout_get_size(sw_glayout_t *layout);

/// Do not call!
///
/// @memberof sw_glayout_s
/// @private
/// @since 0.1.0
SW_LOCAL void sw_glayout_update(sw_glayout_t *layout);

/// Do not call!
///
/// @memberof sw_glayout_s
/// @private
/// @since 0.1.0
SW_LOCAL void sw_glayout_drop(sw_glayout_t *layout);

SW_API_END

#endif // !defined(__SW_LAYOUTS_GRID_H__)

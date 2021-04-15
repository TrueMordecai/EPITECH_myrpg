/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Layout System definitions
*/

#ifndef __SW_LAYOUT_H__
#define __SW_LAYOUT_H__

#include "sw/config.h"

SW_API_BEGIN

/// @file
///
/// Widget layouts.
/// Layouts are automaticaly assigned to their owner on creation.
/// @since 0.1.0

#include "sw/types.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC API
////////////////////////////////////////////////////////////////////////////////

/// Unitializes and frees the given layout.
/// @c sw_layout_destroy must only be used on a layout that has been created
/// using a sw_<layout name>_create function.
///
/// @param layout The layout.
///
/// @memberof sw_layout_s
/// @public
/// @since 0.1.0
SW_API void sw_layout_destroy(sw_layout_t *layout);

/// Updates the position of the contained widgets.
/// You should generally not need to call this because it is automatically
/// called at the most appropriate times.
///
/// @param layout The layout.
///
/// @memberof sw_layout_s
/// @public
/// @since 0.1.0
SW_API void sw_layout_update(sw_layout_t *layout);

/// Returns the minimum size required to hold the contained widgets.
///
/// @param layout The layout.
///
/// @returns The minimum size.
///
/// @memberof sw_layout_s
/// @public
/// @since 0.1.0
SW_API sw_vec2f_t sw_layout_get_size(sw_layout_t *layout);

/// @param layout The layout, can be @c NULL.
/// @param widget The widget to check, can be @c NULL.
///
/// @returns Whether @c widget is contained in @c layout.
///
/// @memberof sw_layout_s
/// @public
/// @since 0.1.0
SW_API bool sw_layout_contains(sw_layout_t *layout, sw_widget_t const *widget);

/// Removes a widget from this layout.
///
/// @param layout The layout.
/// @param widget The widget to remove.
///
/// @returns @c true on success, or @c false if @c widget was not in @c layout.
///
/// @memberof sw_layout_s
/// @public
/// @since 0.1.0
SW_API bool sw_layout_remove(sw_layout_t *layout, sw_widget_t *widget);

////////////////////////////////////////////////////////////////////////////////
// PROTECTED API - do not use outside derived layouts!
////////////////////////////////////////////////////////////////////////////////

/// The internal data of a layout base.
struct sw_layout_data_s {
    /// @protectedsection
    /// The owner of this layout.
    sw_base_t *owner;
};

/// The update method, used by @ref sw_layout_s::sw_layout_update.
typedef void (*sw_layout_update_t)(sw_layout_t *);
/// The drop method, used by @ref sw_layout_s::sw_layout_destroy.
typedef void (*sw_layout_drop_t)(sw_layout_t *);
/// The get_size method, used by @ref sw_layout_s::sw_layout_get_size.
typedef sw_vec2f_t (*sw_layout_get_size_t)(sw_layout_t *);
/// The remove method, used by @ref sw_layout_s::sw_layout_remove.
typedef bool (*sw_layout_remove_t)(sw_layout_t *, sw_widget_t *widget);

/// The layout vtable, do not access outside layout implementations.
struct sw_layout_vtable_s {
    /// @protectedsection
    /// The update method, used by @ref sw_layout_s::sw_layout_update.
    sw_layout_update_t update;
    /// The drop method, used by @ref sw_layout_s::sw_layout_destroy.
    sw_layout_drop_t drop;
    /// The get_size method, used by @ref sw_layout_s::sw_layout_get_size.
    sw_layout_get_size_t get_size;
    /// The remove method, used by @ref sw_layout_s::sw_layout_remove.
    sw_layout_remove_t remove;
};

/// The layout base type.
/// This type cannot directly be instanciated, use @ref sw_glayout_t, or
/// @ref sw_vlayout_t instead.
///
/// @since 0.1.0
struct sw_layout_s {
    /// @protectedsection
    /// The layout data, do not access outside layout implementations.
    sw_layout_data_t data;
    /// The layout vtable, do not access outside layout implementations.
    sw_layout_vtable_t vtable;
};

/// Initializes the base component of a layout.
/// DO NOT CALL outside derived layout implementations!
///
/// @memberof sw_layout_s
/// @protected
/// @since 0.1.0
SW_PROTECTED_API sw_result_t sw_layout_init(
    sw_layout_t *layout, sw_widget_t *owner);

SW_API_END

#endif // !defined(__SW_LAYOUT_H__)

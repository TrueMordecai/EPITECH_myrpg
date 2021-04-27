/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** The types used by Simple Widgets
*/

#ifndef __SW_TYPES_H__
#define __SW_TYPES_H__

#include "sw/config.h"

/// @file
///
/// Common types definitons

SW_API_BEGIN

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <libmy/collections/vec.h>
#include <stdbool.h>
#include "sw/config.h"

/// A vector of widgets.
typedef my_vec_t sw_list_t;

/// 2-dimensional signed int vector type.
/// @since 0.1.0
typedef sfVector2i sw_vec2i_t;

/// 2-dimensional unsigned int vector type.
/// @since 0.1.0
typedef sfVector2u sw_vec2u_t;

/// 2-dimensional float vector type.
/// @since 0.1.0
typedef sfVector2f sw_vec2f_t;

/// signed int rectangle type.
/// @since 0.1.0
typedef sfIntRect sw_irect_t;

/// The values used for margin, border and padding spacing.
/// @since 0.1.0
typedef union sw_spacing_u {
    struct {
        /// top spacing.
        float top;
        /// right spacing.
        float right;
        /// bottom spacing.
        float bottom;
        /// left spacing.
        float left;
    };
    /// Consecutive spacing values.
    float values[4];
} sw_spacing_t;

/// A RGBA 32 bit (8 bit depth) color type.
/// @since 0.1.0
typedef union sw_color_u {
    struct {
        /// Red channel
        sw_u8_t r;
        /// Green channel
        sw_u8_t g;
        /// Blue channel
        sw_u8_t b;
        /// Alpha channel, 0 is fully transparent, 255 fully opaque.
        sw_u8_t a;
    };
    /// The color value, as a 32 bit unsigned integer.
    sw_u32_t value;
    /// The SFML color value.
    sfColor sf_color;
} sw_color_t;

/// The return value type for most SW functions.
/// @since 0.1.0
typedef enum sw_result_e {
    /// Operation completed succesfully.
    /// @since 0.1.0
    SW_OK = 0,
    /// Operation was (succesfully) canceled.
    /// @since 0.1.0
    SW_PASS,
    /// Allocation error.
    /// @since 0.1.0
    SW_ERR_ALLOCATION,
    /// Layout has no valid owner.
    /// @since 0.1.0
    SW_ERR_NO_OWNER,
    /// Out-of-bounds parameter(s).
    /// @since 0.1.0
    SW_ERR_OUT_OF_BOUNDS,
    /// The number of result values available, not a return value.
    /// @since 0.1.0
    SW_RESULT_COUNT,
} sw_result_t;

/// @copydoc sw_state_s
typedef struct sw_state_s sw_state_t;

////////////////////////////////////////////////////////////////////////////////
// WIDGETS
////////////////////////////////////////////////////////////////////////////////

/// Represents any widget type.
///
/// @note Type Safety
/// A widget type MUST be either @ref sw_base_t or contain it as its first
/// member.
typedef void sw_widget_t;

/// @copydoc sw_base_data_s
typedef struct sw_base_data_s sw_base_data_t;
/// @copydoc sw_base_vtable_s
typedef struct sw_base_vtable_s sw_base_vtable_t;
/// @copydoc sw_base_s
typedef struct sw_base_s sw_base_t;

/// @copydoc sw_button_data_s
typedef struct sw_button_data_s sw_button_data_t;
/// @copydoc sw_button_s
typedef struct sw_button_s sw_button_t;

/// @copydoc sw_label_data_s
typedef struct sw_label_data_s sw_label_data_t;
/// @copydoc sw_label_s
typedef struct sw_label_s sw_label_t;

////////////////////////////////////////////////////////////////////////////////
// LAYOUTS
////////////////////////////////////////////////////////////////////////////////

/// @copydoc sw_layout_vtable_s
typedef struct sw_layout_vtable_s sw_layout_vtable_t;
/// @copydoc sw_layout_data_s
typedef struct sw_layout_data_s sw_layout_data_t;
/// @copydoc sw_layout_s
typedef struct sw_layout_s sw_layout_t;

/// @copydoc sw_glayout_s
typedef struct sw_glayout_s sw_glayout_t;

/// @copydoc sw_vlayout_s
typedef struct sw_vlayout_s sw_vlayout_t;

SW_API_END

#endif // !defined(__SW_TYPES_H__)

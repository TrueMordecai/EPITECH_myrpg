/*
** EPITECH PROJECT, 2021
** Simple Widgets Library
** File description:
** Library version and attributes
*/

/// @file
///
/// Simple Widgets Library core definitions
/// @since 0.1.0

#ifndef __SW_CONFIG_H__
#define __SW_CONFIG_H__

/// Simple Widgets Library version major number.
#define SW_VERSION_MAJOR 0
/// Simple Widgets Library version minor number.
#define SW_VERSION_MINOR 1
/// Simple Widgets Library version patch number.
#define SW_VERSION_PATCH 0

// Attributes
#ifdef __cplusplus
    #ifdef __GNUC__
        #define SW_ATTRIBUTE(attr_params) __attribute__((attr_params))
    #else // !defined(_GNUC_)
        #define SW_ATTRIBUTE(attr_params) [[gnu::attr_params]]
    #endif // defined(_GNUC_)
    #define SW_API_BEGIN \
        extern "C"       \
        {
    #define SW_API_END }
#else // !defined(__cplusplus)
    #define SW_ATTRIBUTE(attr_params) __attribute__((attr_params))
    /// @internal
    #define SW_API_BEGIN
    /// @internal
    #define SW_API_END
#endif // defined(__cplusplus)

#if __GNUC__ >= 4
    #define SW_API   SW_ATTRIBUTE(visibility("default"))
    #define SW_LOCAL SW_ATTRIBUTE(visibility("hidden"))
#else // __GNUC__ < 4
    #define SW_API
    #define SW_LOCAL
#endif // __GNUC__ >= 4

#if __GNUC__
    #define SW_INLINE SW_ATTRIBUTE(always_inline) inline
#else // !defined(__GNUC__)
    #define SW_INLINE inline
#endif // defined(__GNUC__)

/// @def SW_LOCAL
///
/// Simple Widgets internal API.
/// @since 0.1.0

/// @def SW_INLINE
///
/// Qualifies an inline API.
/// @since 0.1.0

/// @def SW_API
///
/// Qualifies a public API.
/// @since 0.1.0

/// Qualifies an API that should only used in custom implementations of a base
/// object, such as a widget.
/// @since 0.1.0
#define SW_PROTECTED_API SW_API

#include <SFML/Config.h>

/// Unsigned 8-bit number.
/// @since 0.1.0
typedef sfUint8 sw_u8_t;
/// Signed 8-bit number.
/// @since 0.1.0
typedef sfInt8 sw_i8_t;
/// Unsigned 16-bit number.
/// @since 0.1.0
typedef sfUint16 sw_u16_t;
/// Signed 16-bit number.
/// @since 0.1.0
typedef sfInt16 sw_i16_t;
/// Unsigned 32-bit number.
/// @since 0.1.0
typedef sfUint32 sw_u32_t;
/// Signed 32-bit number.
/// @since 0.1.0
typedef sfInt32 sw_i32_t;
/// Unsigned 64-bit number.
/// @since 0.1.0
typedef sfUint64 sw_u64_t;
/// Signed 64-bit number.
/// @since 0.1.0
typedef sfInt64 sw_i64_t;

#endif // !defined(__SW_CONFIG_H__)

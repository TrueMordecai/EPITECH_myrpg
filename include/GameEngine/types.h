/*
** EPITECH PROJECT, 2021
** MyRPG - Game Engine
** File description:
** Holds the type definitions for the game engine
*/

#ifndef __GAME_ENGINE_TYPES_H__
#define __GAME_ENGINE_TYPES_H__

/// @file
///
/// Holds all of the type aliases from the Game Engine.

// asset_manager.h
typedef union asset asset_t;
typedef struct asset_manager asset_manager_t;

// audio_manager.h
typedef union audio audio_t;
typedef struct audio_manager audio_manager_t;

// game.h
typedef struct game_data game_data_t;

// settings.h
typedef struct settings settings_t;

// state.h
typedef enum state_id state_id_t;
typedef struct state_vtable state_vtable_t;
typedef struct state state_t;

#endif // !defined(__GAME_ENGINE_TYPES_H__)

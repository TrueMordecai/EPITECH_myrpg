/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Settings state
*/

#ifndef __SETTINGS_STATE_H__
#define __SETTINGS_STATE_H__

#include <sw/widgets/base.h>
#include <sw/widgets/button.h>

#include "GameEngine/settings.h"
#include "GameEngine/state.h"

#define SETTINGS_DRAW_LAYERS (1)

typedef struct settings_state {
    state_t base;
    sw_base_t gui;
    settings_t old_settings;
} settings_state_t;

state_t *settings_state_create(game_data_t *data);
int settings_state_resume(settings_state_t *state, state_id_t last_state);
int settings_state_handle_events(settings_state_t *state);
int settings_state_update(settings_state_t *state, float dt);
int settings_state_draw(settings_state_t *state, float dt);
int settings_state_pause(settings_state_t *state, state_id_t new_state);
void settings_state_destroy(settings_state_t *state, state_id_t from);

void settings_init_gui(settings_state_t *state);

void settings_refit_size(sw_widget_t *widget);
sw_widget_t *settings_title_create(settings_state_t *state);
sw_widget_t *settings_body_create(settings_state_t *state);

typedef struct settings_row {
    char const *label;
    sw_vec2u_t bounds;
    size_t value_offset;
} settings_row_t;

typedef struct settings_adjust_button {
    union {
        sw_base_t base;
        sw_button_t button;
    };
    sw_on_event_t base_on_event;
    int offset;
    sw_vec2u_t bounds;
    game_data_t *game_data;
} settings_adjust_button_t;

settings_adjust_button_t *settings_adjust_button_create(
    game_data_t *data, sw_vec2u_t bounds, int offset, unsigned *location);

typedef struct settings_display_button {
    union {
        sw_base_t base;
        sw_button_t button;
    };
    unsigned *value;
} settings_display_button_t;

settings_display_button_t *settings_display_button_create(
    game_data_t *data, unsigned *location);

typedef struct settings_footer_t {
    sw_base_t base;
    sw_button_t *apply_button;
    sw_button_t *back_button;
} settings_footer_t;

settings_footer_t *settings_footer_create(settings_state_t *state);

#define SETTINGS(state)    ((state)->base.game_data->settings)
#define WINDOW_SIZE(state) (SETTINGS(state).window_size)

#endif // !defined(__SETTINGS_STATE_H__)

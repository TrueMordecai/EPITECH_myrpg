/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** menu state
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <sw/layouts/vertical.h>
#include <sw/widget.h>
#include <sw/widgets/button.h>
#include "GameEngine/state.h"

#define MENU_DRAW_LAYERS (1)

typedef struct menu_state {
    state_t base;
    sw_base_t *gui_base;
    sfRectangleShape *bg;
} menu_state_t;

state_t *menu_state_create(game_data_t *data);
int menu_state_resume(menu_state_t *state, state_id_t last_state);
int menu_state_handle_events(menu_state_t *state);
int menu_state_update(menu_state_t *state, float dt);
int menu_state_draw(menu_state_t *state, float dt);
int menu_state_pause(menu_state_t *state, state_id_t new_state);
void menu_state_destroy(menu_state_t *state, state_id_t from);

void menu_init_gui(menu_state_t *state);

#endif /* !MENU_STATE_H */

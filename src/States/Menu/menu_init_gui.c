/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Intializes the GUI of the main menu
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>

#include "GameEngine/game.h"
#include "GameEngine/settings.h"
#include "functions.h"
#include "States/Menu/menu_state.h"

static void init_tutorial(menu_state_t *state)
{
    state->tutorial = sfRectangleShape_create();

    sfRectangleShape_setTexture(state->tutorial,
        get_texture(&state->base.game_data->assets, "tutorial"), 1);
    sfRectangleShape_setSize(
        state->tutorial, (sfVector2f){1920 * SCL(state), 1080 * SCL(state)});
}

static void init_gui2(menu_state_t *state, sw_vlayout_t *layout)
{
    sw_vlayout_add(layout,
        create_btn(&state->base, "Tutorial",
            (sw_spacing_t){{50 * SCL(state), 0, 50 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(&state->base, "Quit",
            (sw_spacing_t){{50 * SCL(state), 0, 0, 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
}

void menu_init_gui(menu_state_t *state)
{
    sw_base_t *base = sw_base_create(NULL);
    sw_vlayout_t *layout = sw_vlayout_create(base);

    sw_set_background_texture(
        base, get_texture(&state->base.game_data->assets, "menu_bg"), 1);
    sw_set_size(base, (sw_vec2f_t){1920 * SCL(state), 1080 * SCL(state)});
    sw_layout_update((sw_layout_t *)layout);
    sw_vlayout_add(layout,
        create_btn(&state->base, "Play",
            (sw_spacing_t){{400 * SCL(state), 0, 50 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(&state->base, "Settings",
            (sw_spacing_t){{50 * SCL(state), 0, 50 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    init_gui2(state, layout);
    state->gui_base = base;
    init_tutorial(state);
}

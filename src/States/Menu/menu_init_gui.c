/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** menu_init_gui
*/

#include <libmy/ascii/ascii.h>
#include <libmy/printf.h>

#include "functions.h"
#include "GameEngine/game_head.h"
#include "States/Game/game_state.h"
#include "States/Menu/menu_state.h"
#include "States/Settings/settings_state.h"

void menu_init_gui(menu_state_t *state)
{
    sw_base_t *base = sw_base_create(NULL);
    sw_vlayout_t *layout = sw_vlayout_create(base);

    sw_set_size(base, (sw_vec2f_t){1920 * SCL(state), 1080 * SCL(state)});
    sw_vlayout_update(layout);
    sw_vlayout_add(layout,
        create_btn(&state->base, "Play",
            (sw_spacing_t){{400 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(&state->base, "Settings",
            (sw_spacing_t){{75 * SCL(state), 0, 75 * SCL(state), 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    sw_vlayout_add(layout,
        create_btn(&state->base, "Quit",
            (sw_spacing_t){{75 * SCL(state), 0, 0, 0}},
            (sw_vec2f_t){225 * SCL(state), 75 * SCL(state)}));
    state->gui_base = base;
}
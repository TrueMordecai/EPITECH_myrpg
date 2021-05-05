/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** destroy menu
*/

#include "States/Menu/menu_state.h"

// Does nothing since the menu state doesn't have any extra data yet.
void menu_state_destroy(menu_state_t *state, state_id_t from)
{
    (void)state;
    (void)from;
    sw_destroy(state->gui_base);
}

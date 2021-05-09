/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** destroy menu
*/

#include <SFML/Graphics.h>
#include "States/Menu/menu_state.h"

void menu_state_destroy(menu_state_t *state, state_id_t from)
{
    (void)from;
    sfRectangleShape_destroy(state->tutorial);
    sw_destroy(state->gui_base);
}

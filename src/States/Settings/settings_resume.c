/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Settings - resume
*/

#include <libmy/io/iostream.h>

#include "States/Settings/settings_state.h"

int settings_state_resume(settings_state_t *state, state_id_t last_state)
{
    my_puts("Settings State\n");
    my_fflush(MY_STDOUT);
    (void)state;
    (void)last_state;
    return 0;
}

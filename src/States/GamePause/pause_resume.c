/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Menu - resume
*/

#include <libmy/io/iostream.h>

#include "States/GamePause/pause_state.h"

int pause_state_resume(pause_state_t *state, state_id_t last_state)
{
    my_puts("Pause State\n");
    my_fflush(MY_STDOUT);
    (void)state;
    (void)last_state;
    return 0;
}

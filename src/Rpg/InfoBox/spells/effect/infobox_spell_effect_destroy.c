/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_spell_destroy
*/

#include <stdlib.h>

#include "Rpg/InfoBox/infobox_spell.h"

static void destroy_text(void *text_ptr)
{
    sfText_destroy(*((sfText **)text_ptr));
}

void infobox_spell_effect_clear_vecs(infobox_spell_effect_t *info)
{
    my_vec_clear(&info->boosts, &destroy_text);
    my_vec_clear(&info->damages, &destroy_text);
}

void infobox_spell_effect_destroy(infobox_spell_effect_t *info)
{
    my_vec_free(&info->boosts, &destroy_text);
    my_vec_free(&info->damages, &destroy_text);
    sfText_destroy(info->lifetime);
    sfText_destroy(info->max_cumul);
    sfText_destroy(info->boost);
    sfText_destroy(info->damage);
}

/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_entity_destroy
*/

#include "Rpg/InfoBox/infobox_entity.h"
static void destroy_text(void *text_ptr)
{
    sfText_destroy(*((sfText **)text_ptr));
}

void infobox_entity_clear_effects(infobox_entity_t *info)
{
    my_vec_clear(&info->effect_names, &destroy_text);
}

void infobox_entity_destroy(infobox_entity_t *info)
{
    sfText_destroy(info->name);
    sfText_destroy(info->level);
    sfText_destroy(info->life);
    sfText_destroy(info->pa);
    sfText_destroy(info->pm);
    sfText_destroy(info->damage);
    sfText_destroy(info->resistance);
    sfText_destroy(info->effects);
    my_vec_free(&info->effect_names, &destroy_text);
    for (int i = 0; i < 4; i++) {
        sfText_destroy(info->elements[0][i]);
        sfText_destroy(info->elements[1][i]);
        sfText_destroy(info->elements[2][i]);
    }
}

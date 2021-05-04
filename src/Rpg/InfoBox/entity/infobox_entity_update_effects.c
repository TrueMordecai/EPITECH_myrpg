/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_entity_update_effects
*/

#include <libmy/ascii.h>
#include <libmy/parsing/parsing.h>
#include <libmy/printf/printf.h>
#include <stdarg.h>

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_entity.h"

static sfVector3f get_text_pos(infobox_entity_t *info, sfText *text)
{
    sfText *last_text = NULL;
    sfFloatRect bounds;
    sfVector3f pos = {
        0.05 * info->base.box_size.x, 0.8 * info->base.box_size.y, -1};

    if (!info->effect_names.length)
        return pos;
    last_text = MY_VEC_GET_ELEM(
        sfText *, &info->effect_names, info->effect_names.length - 1);
    bounds = sfText_getGlobalBounds(last_text);
    pos.x = bounds.left + bounds.width;
    pos.y = bounds.top - sfText_getLocalBounds(last_text).top;
    if (pos.x + sfText_getGlobalBounds(text).width
        >= 0.95 * info->base.box_size.x) {
        pos.x = 0.05 * info->base.box_size.x;
        pos.y += 0.05 * info->base.box_size.y;
    }
    return pos;
}

static void add_effect_text(infobox_entity_t *info, char *name, int last)
{
    sfText *text;
    sfVector3f pos;
    char *str = name;

    infobox_create_text(&info->base, &text, sfWhite, 25);
    if (!last) {
        str = malloc(sizeof(char) * (my_strlen(name) + 3));
        my_sprintf(str, "%s, ", name);
    }
    sfText_setString(text, str);
    pos = get_text_pos(info, text);
    infobox_set_text_pos(text, pos);
    my_vec_push(&info->effect_names, &text);
    if (!last)
        free(str);
}

void infobox_entity_update_effects(infobox_entity_t *info, entity_t *entity)
{
    sfText *last_text;
    sfFloatRect bounds;

    for (size_t i = 0; i < entity->stats->effects.length; i++)
        add_effect_text(info,
            ((effect_t *)entity->stats->effects.data + i)->spell->base.name,
            (i + 1 == entity->stats->effects.length));
    last_text = MY_VEC_GET_ELEM(
        sfText *, &info->effect_names, info->effect_names.length - 1);
    bounds = sfText_getGlobalBounds(last_text);
    infobox_set_box_size(&info->base,
        (sfVector2f){info->base.box_size.x,
            bounds.top + bounds.height + info->base.box_size.y * 0.02},
        1);
}
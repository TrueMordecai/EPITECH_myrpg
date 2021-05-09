/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** Updates an entity infobox
*/

#include <libmy/ascii.h>
#include <libmy/parsing/parsing.h>
#include <libmy/printf/printf.h>
#include <stdarg.h>

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_entity.h"

void infobox_entity_set_entity_3(infobox_entity_t *info, entity_t *entity)
{
    sfVector2f bs = info->base.box_size;
    stats_t *s = entity->stats;

    info->entity = entity;
    sfRectangleShape_setTexture(
        info->base.icon, sfRectangleShape_getTexture(entity->rect), 0);
    sfRectangleShape_setTextureRect(info->base.icon, (sfIntRect){0, 0, 16, 16});
    sfRectangleShape_setFillColor(
        info->base.icon, sfRectangleShape_getFillColor(entity->rect));
    infobox_init_text(info->effects, "%d Effect%s",
        (sfVector3f){0.03 * bs.x, 0.75 * bs.y, -1}, info->effect_names.length,
        (info->effect_names.length > 1) ? "s:" : ":");
    for (int i = 0; i < 4; i++) {
        infobox_init_text(info->elements[1][i], "%d",
            (sfVector3f){0.4 * bs.x, (0.4 + i * 0.1) * bs.y, 0},
            s->elements[i]);
        infobox_init_text(info->elements[2][i], "%d%",
            (sfVector3f){0.8 * bs.x, (0.4 + i * 0.1) * bs.y, 0},
            s->resistances[i]);
    }
}

void infobox_entity_set_entity_2(infobox_entity_t *info, entity_t *entity)
{
    sfVector2f bs = info->base.box_size;
    stats_t *s = entity->stats;

    infobox_init_text(info->name, "%s",
        (sfVector3f){0.65 * bs.x, 0.07 * bs.y, 0}, entity->name);
    infobox_init_text(info->level, "Level: %d",
        (sfVector3f){0.35 * bs.x, 0.15 * bs.y, -1}, s->level);
    infobox_init_text(info->life, "%d/%d HP",
        (sfVector3f){0.35 * bs.x, 0.25 * bs.y, 1}, s->current_life, s->life);
    infobox_init_text(info->pa, "%d/%d PA",
        (sfVector3f){0.6 * bs.x, 0.25 * bs.y, 1}, s->current_pa, s->pa);
    infobox_init_text(info->pm, "%d/%d PM",
        (sfVector3f){0.9 * bs.x, 0.25 * bs.y, 1}, s->current_pm, s->pm);
    infobox_init_text(
        info->damage, "Damage", (sfVector3f){0.4 * bs.x, 0.35 * bs.y, 0});
    infobox_init_text(info->resistance, "Resistance",
        (sfVector3f){0.8 * bs.x, 0.35 * bs.y, 0});
}

void infobox_entity_set_entity(infobox_entity_t **info_ptr, entity_t *entity)
{
    stats_t *s;
    infobox_entity_t *info = *info_ptr;

    if (!entity)
        return;
    infobox_reset_box_size(&info->base);
    s = entity->stats;
    info->entity = entity;
    infobox_entity_set_entity_2(info, entity);
    infobox_entity_set_entity_3(info, entity);
    infobox_entity_clear_effects(*info_ptr);
    if (s->effects.length == 0)
        infobox_set_box_size(&info->base,
            (sfVector2f){info->base.box_size.x, info->base.box_size.y * 0.8},
            1);
    else
        infobox_entity_update_effects(info, entity);
}

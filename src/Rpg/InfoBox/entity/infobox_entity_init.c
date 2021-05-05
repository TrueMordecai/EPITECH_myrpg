/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** infobox_entity_init
*/

#include "GameEngine/settings.h"
#include "Rpg/rpg.h"
#include "Rpg/InfoBox/infobox_entity.h"

static void create_texts(infobox_entity_t *info)
{
    infobox_create_text(&info->base, &info->name, sfWhite, 35);
    infobox_create_text(&info->base, &info->level, sfWhite, 25);
    infobox_create_text(&info->base, &info->life, sfWhite, 25);
    infobox_create_text(&info->base, &info->pa, sfWhite, 25);
    infobox_create_text(&info->base, &info->pm, sfWhite, 25);
    infobox_create_text(&info->base, &info->damage, sfWhite, 25);
    infobox_create_text(&info->base, &info->resistance, sfWhite, 25);
    infobox_create_text(&info->base, &info->effects, sfWhite, 30);
    for (int i = 0; i < 4; i++) {
        infobox_create_text(&info->base, &info->elements[0][i], sfWhite, 25);
        infobox_init_text(info->elements[0][i], ELEMENTS_NAMES[i],
            (sfVector3f){0.05 * info->base.box_size.x,
                (0.4 + i * 0.1) * info->base.box_size.y, -1});
        infobox_create_text(&info->base, &info->elements[1][i], sfWhite, 25);
        infobox_create_text(&info->base, &info->elements[2][i], sfWhite, 25);
    }
}

void infobox_entity_init(infobox_entity_t *info, entity_t *entity)
{
    info->entity = entity;
    my_vec_init(&info->effect_names, sizeof(sfText *));
    create_texts(info);
    infobox_entity_set_entity(&info, entity);
}

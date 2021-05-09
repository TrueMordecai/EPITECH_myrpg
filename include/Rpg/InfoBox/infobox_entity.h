/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** An infobox that describes an entity
*/

#ifndef INFOBOX_ENTITY_H_
#define INFOBOX_ENTITY_H_

#include "Rpg/Entities/entity.h"
#include "Rpg/InfoBox/infobox.h"

typedef struct infobox_entity {
    infobox_base_t base;
    entity_t *entity;
    sfText *name;
    sfText *level;
    sfText *life;
    sfText *ap;
    sfText *mp;
    sfText *damage;
    sfText *resistance;
    /// Elements Texts (NAME, DAMAGE, RESISTANCE)
    sfText *elements[3][4];
    sfText *effects;
    my_vec_t effect_names;
} infobox_entity_t;

extern char const *ELEMENTS_NAMES[4];

void infobox_entity_init(infobox_entity_t *info, entity_t *entity);
void infobox_entity_set_entity(infobox_entity_t **info_ptr, entity_t *entity);
void infobox_entity_update_effects(infobox_entity_t *info, entity_t *entity);
void infobox_entity_draw(infobox_entity_t *info, sfRenderWindow *window);
void infobox_entity_destroy(infobox_entity_t *info);
void infobox_entity_clear_effects(infobox_entity_t *info);

#endif /* !INFOBOX_ENTITY_H_ */

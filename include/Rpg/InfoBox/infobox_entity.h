/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_entity
*/

#ifndef INFOBOX_ENTITY_H_
#define INFOBOX_ENTITY_H_

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/Entities/entity.h"

typedef struct infobox_entity {
    infobox_base_t base;
    entity_t *entity;
    sfText *name;
    sfText *level;
    sfText *life;
    sfText *pa;
    sfText *pm;
    sfText *damage;
    sfText *resistance;
    ///Elements Texts (NAME, DAMAGE, RESISTANCE)
    sfText *elements[3][4];
    sfText *effects;
    /// Max 4(?) effects
    my_vec_t effect_names;
} infobox_entity_t;

extern char const *ELEMENTS_NAMES[4];

void infobox_entity_init(infobox_entity_t *info, entity_t *entity);
void infobox_entity_set_entity(infobox_entity_t *info, entity_t *entity);
void infobox_entity_draw(infobox_entity_t *info, sfRenderWindow *window);
void infobox_entity_destroy(infobox_entity_t *info);

#endif /* !INFOBOX_ENTITY_H_ */
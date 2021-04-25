/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** infobox_effect
*/

#ifndef INFOBOX_EFFECT_H_
#define INFOBOX_EFFECT_H_

#include "Rpg/InfoBox/infobox.h"
#include "Rpg/Entities/entity.h"

typedef struct infobox_effect {
    infobox_base_t base;
    effect_t *effect;
    sfText *name;
    /// Turns left, type
    sfText *infos;
    my_vec_t boosts;
    my_vec_t damages;
} infobox_effect_t;

#endif /* !INFOBOX_EFFECT_H_ */
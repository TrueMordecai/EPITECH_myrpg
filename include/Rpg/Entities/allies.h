/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** The ally entities
*/

#ifndef ALLY_H_
#define ALLY_H_

#define MAX_ALLIES_IN_FIGHT 3

#include <libmy/collections/vec.h>

#include "Rpg/Entities/entity.h"

typedef struct rpg rpg_t;

typedef struct allies_t {
    int selected_allies[MAX_ALLIES_IN_FIGHT];
    my_vec_t allies;
    rpg_t *rpg;
} allies_t;

void allies_init(allies_t *allies, rpg_t *rpg);
void allies_add_ally(allies_t *allies, entity_t *ally);
void allies_add_random_ally(allies_t *allies);
void allies_destroy(allies_t *allies);

#endif /* !ALLY_H_ */

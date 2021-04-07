/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map physic
*/

#ifndef RPG_MAP_PHYSIC_H
#define RPG_MAP_PHYSIC_H

#include "Physics/physics.h"
#include "Rpg/Map/zone.h"

enum PHYSIC_TILES {EMPTY, SOLID, TRANSPARENT};
enum PHYSIC_SHAPES {FULL, HALF, QUARTER, TRI};

void physic_add_tile(pe_world_t *world, pe_vec2f_t pos);
void physic_add_shaped_tile(zone_t *zone, sfVector2i pos, int tile);
void physic_add_zone_border(zone_t *zone);

#endif /* !RPG_MAP_PHYSIC_H */
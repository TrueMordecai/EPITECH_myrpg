/*
** EPITECH PROJECT, 2021
** My rpg
** File description:
** physic add zone border
*/

#include "Rpg/rpg.h"

static void set_border(zone_t *zone, pe_vec2f_t size, pe_vec2f_t pos)
{
    pe_body_t *body = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *fixture = pe_fixture_init();

    body->pos = pos;
    pe_shape_init_rect(&fixture->shape, VEC2F(0, 0), size);
    pe_body_add_fixture(body, fixture);
    pe_world_add_body(zone->world, body);
}

void physic_add_zone_border(zone_t *zone)
{
    set_border(zone, VEC2F(zone->size.x, 1), VEC2F(zone->size.x / 2, 0));
    set_border(zone, VEC2F(zone->size.x, 1), \
    VEC2F(zone->size.x / 2, zone->size.y));
    set_border(zone, VEC2F(1, zone->size.y), VEC2F(-1, zone->size.y / 2));
    set_border(zone, VEC2F(1, zone->size.y), \
    VEC2F(zone->size.x, zone->size.y / 2));
}
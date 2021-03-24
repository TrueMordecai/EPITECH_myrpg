/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map physic
*/

#include "Rpg/rpg.h"
#include "My/my_display.h"
void physic_add_tile(pe_world_t *world, pe_vec2f_t pos)
{
    pe_body_t *body = pe_body_init(STATIC, 2, 0);
    pe_fixture_t *fixture = pe_fixture_init();

    body->pos = pos;
    pe_body_add_fixture(body, fixture);
    pe_world_add_body(world, body);
}

static void init_shape_rect(pe_shape_t *shape, pe_vec2f_t pos, \
pe_vec2f_t size, int dir)
{
    float c = cosf(dir * PE_PI / 2.f);
    float s = sinf(dir * PE_PI / 2.f);

    if (dir % 2 != 0)
        size = VEC2F(size.y, size.x);
    pos = VEC2F(pos.x * c - pos.y * s, pos.x * s + pos.y * c);
    pe_shape_init_rect(shape, pos, size);
}

static void init_shape_tri(pe_shape_t *shape, int dir)
{
    pe_vec2f_t *v_alloc = malloc(sizeof(pe_vec2f_t) * 3);
    pe_vec2f_t pos = {0.5f, 0.5f};
    float c = cosf(dir * PE_PI / 2.f);
    float s = sinf(dir * PE_PI / 2.f);

    pos = VEC2F(pos.x * c - pos.y * s, pos.x * s + pos.y * c);
    for (int i = 0; i < 3; i++) {
        v_alloc[i] = pos;
        pos = VEC2F(-pos.y, pos.x);
    }
    pe_shape_init_polygon(shape, VEC2F(0, 0), v_alloc, 3);
}

void physic_add_shaped_tile(zone_t *zone, sfVector2i pos, int tile)
{
    pe_body_t *body = pe_body_init(STATIC, 2, 0);
    pe_fixture_t *fixture = pe_fixture_init();

    switch ((tile % 16) / 4) {
    case HALF:
        init_shape_rect(&fixture->shape, \
        VEC2F(-0.125f, 0), VEC2F(0.5f, 1), tile % 4);
        break;
    case QUARTER:
        init_shape_rect(&fixture->shape, \
        VEC2F(-0.125f, -0.125f), VEC2F(0.5f, 0.5f), tile % 4 - 1);
        break;
    case TRI:
        init_shape_tri(&fixture->shape, tile % 4);
        break;
    }
    body->pos = VEC2F(pos.x, pos.y);
    pe_body_add_fixture(body, fixture);
    pe_world_add_body(zone->world, body);
    zone->battle[pos.x + pos.y * zone->size.x] = SOLID + (tile >= 16);
}
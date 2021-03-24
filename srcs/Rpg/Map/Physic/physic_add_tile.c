/*
** EPITECH PROJECT, 2021
** My Rpg
** File description:
** map physic
*/

#include "Rpg/rpg.h"

void physic_add_tile(pe_world_t *world, pe_vec2f_t pos)
{
    pe_body_t *body = pe_body_init(STATIC, 2, 0);
    pe_fixture_t *fixture = pe_fixture_init();

    body->pos = pos;
    pe_body_add_fixture(body, fixture);
    pe_world_add_body(world, body);
}